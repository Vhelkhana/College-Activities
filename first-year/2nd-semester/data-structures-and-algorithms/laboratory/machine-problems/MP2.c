/****************************************************************************

MACHINE PROBLEM 2

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

The program should allow the saving of record of all candidates.

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

// Function prototypes

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
	
	tableHeading();
	precinctNo();

	// Input candidate and votes per precinct

	int xCoord = 16;
	int yCoord = 1; // 12

	// Columns
 	for (i = 0; i < 4; i++)
	{
		// Rows
		for (j = 0; j <= 5; j++)
		{
			gotoxy(xCoord, yCoord);
			if (j == 0)
			{
				gets(Candidate[i].name);
			}
			else
			{
				scanf("%d", &pVote);
				scanf("%c", &Temp); /* To catch the null value being returned by scanf() or gets(),
									used when there is a scanf() or gets() prior to reading a
									character */
				Candidate[i].vote[j - 1] = pVote;
			}
			yCoord++;
		}
		xCoord += 16;
		yCoord = 1;
	}

	// Total number of votes per candidate

	float sum[4] = {0};

	for (i = 0; i < 74; i++)
	{
		printf("-");
	}
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

	// Save record

	printf("\n\nEnter file name where records will be saved: ");
	gets(fName);
	
	// Opens the file
	
	fp = fopen(fName, "w");
	
	// Writes in file
	
	for (i = 0; i < 4; i++)
	{
		tempRec = Candidate[i];
		fwrite(&tempRec, sizeof(tempRec), 1, fp);
	}
	
	// Closes file
	
	fclose(fp);

	printf("\nRecords saved.");
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