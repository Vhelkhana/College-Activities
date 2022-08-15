/****************************************************************************

MACHINE PROBLEM 3

The results from the mayor's race have been reported by each precinct as
follows:

				TALLY OF VOTE PER PRECINCT

            Candidate   Candidate   Candidate   Candidate
Precincts   ERAP        NOYNOY      DIGONG      GLORIA
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

Implement the abovementioned problem using struct (Record). The program 
should allow the inputting of records per candidate containing the no. of 
votes cast per precinct. Included in the inputs is the candidate's name. 
Limit your program inputs based on the no. of precincts and no. of candidate 
as stated in the above table.

The program should allow the retrieval of records and the declaration of winner/s.

*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Record structure

typedef struct
{
	char name[7];
	int vote[5];
} Record;

// Gotoxy

COORD coord = {0, 0};
void gotoxy(int x, int y);

// Function prototyes

void tableHeading();
void precinctNo();

// Main function

int main()
{
	Record Candidate[4], tempRec;
	FILE *fp;
	char fName[15], Temp;
	int i = 0, j = 0, pVote = 0;

	system("cls");

    printf("Enter file name where records will be retrieved: ");
    gets(fName);

	printf("\nRetrieving records from %s...", fName);

    // Opens the file

  	fp = fopen(fName, "r");
	
	// Reads the file

  	int k = 0;
  	fread(&tempRec, sizeof(tempRec), 1, fp);
  	while(!feof(fp))
	{
		Candidate[k] = tempRec;
		fread(&tempRec, sizeof(tempRec), 1, fp);
		k++;
	}
	
	// Closes the file
	
  	fclose(fp);

  	printf("\n%d records retrieved.\n\n", k);

    // Displaying retrieved file

    tableHeading();

    // Print name

    for (i = 0; i < k; i++)
	{
        printf("%s\t\t", Candidate[i].name);
    }
    printf("\n");

    // Print votes

    int voteNo[5][4];

    for (i = 0; i < 5; i++)
	{
		if (i != 0)
		{
			printf("\n");
		}
		printf("%d\t\t", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%d\t\t", Candidate[j].vote[i]);
        }
    }

	// Broken lines

	printf("\n");
	for (i = 0; i < 74; i++)
	{
		printf("-");
	}

	// Total number of votes per candidate

	float sum[4] = {0};

	printf("\nTOTAL\t");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
        	sum[i] += Candidate[i].vote[j];
		}
    }
    for (i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			printf("\t");
		}
		printf("%.0f\t\t", sum[i]);
    }

	// Percentage of votes received per candidate

	float grandTotal, percentage[4];

	printf("\nPERCENTAGE\t");

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

	// Calculate winners

	printf("\n\nCalculating winner...");
    Sleep(2000);

	// Compute highest
    
    float highest1 = percentage[0];
    int h1ctr = 0, h2ctr = 0;
    
    for (i = 0; i < 4; i++)
	{
    	if (percentage[i] > highest1)
		{
            highest1 = percentage[i];
            h1ctr = i; // To note the index containing the highest
        }
	}
	
	// Compute second highest
	
	int highest2 = -1;
	
	for (i = 0; i < 4; i++)
	{
		if (i != h1ctr) // To skip the highest
		{
			if (percentage[i] < highest1 && percentage[i] > highest2)
			{
	            highest2 = percentage[i];
	            h2ctr = i; // To note the index containing the second highest
        	}
		}
	}
	
	// Display winners
	
	if (highest1 > 50)
	{
        printf("\n\nCongratulations! The winner is %s.", Candidate[h1ctr].name);
    }
	else
	{
        printf("\n\nNo one received over 50%% votes! ");
		printf("The two highest-voted candidates, ");
		printf("%s and %s, will have a run-off!", Candidate[h1ctr].name, Candidate[h2ctr].name);
	}
    
    return 0;
}

// Function to print "Candidate" and "Precincts" table heading

void tableHeading()
{
	int i;
    for (i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			printf("\t\t");
		}
        printf("Candidate\t");
        if (i == 3)
		{
            printf("\nPrecincts\t");
        }
    }
}

// Function to print precinct numbers

void precinctNo()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("\n%d\t", i + 1);
	}
}

// Function to make gotoxy() work

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}