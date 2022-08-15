/****************************************************************************

MACHINE PROBLEM 1

The results from the mayor's race have been reported by each precinct as
follows:

            Candidate   Candidate   Candidate   Candidate
Precincts   A           B           C           D
1           192         48          206         37
2           147         90          312         21
3           186         12          121         38
4           114         21          408         39
5           267         13          382         29

Write a program to do the following:

a. Print out the table with the appropriate headings for the rows and
    columns.
b. Compute and print the total number of votes received by each
    candidate and the percent of the total votes cast.
c. If any one candidate received over 50 percent of the total votes, the
    program should print a message declaring that candidate the winner.
d. If no candidate received 50 percent of the votes, the program should
    print a message declaring a run-off between the two candidates who
    received the highest number of votes; two candidates should be identified
    by their letter names.
e. Run the program once with the preceding data and once with candidate C
    receiving only 108 votes in precinct 4. (note: test values are not
    limited to the preceding data)

Note: Use Array for this machine problem

*****************************************************************************/

#include <stdio.h>
#include <windows.h>

void headings();
void cHeadings();

char candidates[4] = {'A', 'B', 'C', 'D'};
int precincts[5] = {1, 2, 3, 4, 5};
int votes[5][4];

COORD coord = {0, 0};
void gotoxy(int x, int y);

int main()
{
	char border = '|';
	int i = 0, j = 0;
    
    // Print headings
	
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t\t%c\t", border);
    headings();
    printf("\nPrecincts");
    printf("\t%c\t", border);
    cHeadings();
    printf("---------------------------------------------------------------------------------------\n");
    
	//// Print precinct number
	
	for (i = 0; i < 5; i++)
	{
    	printf("%5d", precincts[i]);
		printf("\t\t%c\t", border);
    	if (i != 4)
    	{
    		printf("\n");
		}
	}
	
    printf("\n---------------------------------------------------------------------------------------\n");

    // Table data
    
    int xcoord, ycoord = 4;
    
    for (i = 0; i < 5; i++, ycoord++)
	{
    	xcoord = 27;
		for (j = 0; j < 4; j++, xcoord += 16)
		{
			gotoxy(xcoord, ycoord);
			scanf("%4d", &votes[i][j]);
		}
		printf("\n");
	}
	
	// Total number of votes per candidate

	float sum[4] = {0};

    printf("\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("\t\t\t%c\t", border);
	headings();
	printf("\t\t\t\t\t%c\t", border);
    cHeadings();
    printf("----------------------------------------------------------------------------------------------\n");
    printf("Total no. of votes\t");
    printf("%c\t", border);
    for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
        	sum[j] += votes[i][j];
		}
    }
    for (i = 0; i < 4; i++)
	{
		printf("%.0f\t\t", sum[i]);
    }

    // Percentage of votes received per candidate
    
    float grandTotal, percentage[4];

    printf("\nPercentage of votes\t");
    printf("%c\t", border);
    for (i = 0; i < 4; i++)
	{
        if (i == 0)
		{
        	for (j = 0; j < 4; j++)
			{
        		grandTotal += sum[j];
			}
		}
        percentage[i] = (sum[i] / grandTotal) * 100;
        printf("%f\t", percentage[i]);
    }
    
    printf("\n----------------------------------------------------------------------------------------------");

    // Check for winners

    printf("\n\nChecking for winners...");
    Sleep(2000);
    
    //// Compute highest
    
    float highest1 = percentage[0];
    int h1ctr = 0, h2ctr = 0;
    
    for (i = 0; i < 4; i++)
	{
    	if (percentage[i] > highest1)
		{
            highest1 = percentage[i];
            h1ctr = i;
        }
	}
	
	//// Compute second highest
	
	int highest2 = 0;
	
	for (i = 0; i < 4; i++)
	{
		if (i != h1ctr) // To skip the highest
		{
			if (percentage[i] < highest1 && percentage[i] > highest2)
			{
	            highest2 = percentage[i];
	            h2ctr = i;
        	}
		}
	}
	
	// Display winners
	
	if (highest1 > 50)
	{
            printf("\n\nCongratulations! The winner is Candidate %c.", candidates[h1ctr]);
    } else
	{
        	printf(
				"\n\nNo one received over 50%% votes! The two highest-voted candidates, Candidate %c and %c, will have a run-off!",
				candidates[h1ctr], candidates[h2ctr]
				);
	}
    
    return 0;
}

// Print "Candidate" headings

void headings()
{
	int i;
    for (i = 0; i < 4; i++)
	{
        printf("Candidate\t");
        if (i == 4)
		{
            printf("\n");
        }
    }
}

// Print candidate letter names

void cHeadings()
{
    int i;
	for (i = 0; i < 5; i++)
	{
        printf("%5c\t\t", candidates[i]);
        if (i == 4)
		{
            printf("\n");
        }
    }
}

// gotoxy()

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
