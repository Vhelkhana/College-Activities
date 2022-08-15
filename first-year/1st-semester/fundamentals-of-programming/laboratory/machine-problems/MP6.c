/****************************************************************************

MACHINE PROBLEM 6

Write a program that will read five (5) grades in percentile format [0-100]
and then determine and display the lowest grade entered, the highest grade
entered, and the general weighted average (GWA) of the five (5) grades
entered.

*****************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
	int grades[5], i, lGrade, hGrade;
	float sum = 0, GWA;
	char resp;
	
	do
	{
		printf("Enter 5 grades in percentile format within 0-100.");
	
		for (i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				printf("\n");
			}
			printf("\tGrade No. %d => ", i + 1);
			scanf("%d", &grades[i]);
			if ((grades[i] < 0) || (grades[i] > 100))
			{
				printf("\n\tOnly enter grades from 0 to 100. Please try again.\n\n");
				i -= 1;
			}
			else
			{
				sum += grades[i];
			}		
		}
		
		GWA = sum / 5;
		
		lGrade = grades[0];
		hGrade = grades[0];
		
		for (i = 0; i < 5; i++)
		{
			if (grades[i] < lGrade)
			{
				lGrade = grades[i];
			}
			else if (grades[i] > hGrade)
			{
				hGrade = grades[i];
			}
		}
		
		printf("\nThe highest grade is %d.", hGrade);
		printf("\nThe lowest grade is %d.", lGrade);
		printf("\nThe general weighted average is %0.2f.", GWA);
	
		printf("\n\nTry Again [Y/N]? ");
		scanf(" %c", &resp);
	}
	while (toupper(resp) == 'Y');
	
	return 0;
}
