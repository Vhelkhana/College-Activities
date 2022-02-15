/****************************************************************************

FINAL EXAMINATION (LAB) - MP2

Write a program to read in a collection of 5 exam scores ranging from 1 to
100. Your program should count and print the number of outstanding scores
(90-100), the number of satisfactory scores (60-89), and the number of
unsatisfactory scores (1-59).
(Note: It is a requirement that you answer it using Iteration or Array)

Sample Output:

Enter 5 Exam Scores:
	Exam Score No. 1 => 91
	Exam Score No. 2 => 75
	Exam Score No. 3 => 85
	Exam Score No. 4 => 55
	Exam Score No. 5 => 90

No. of Outstanding Scores	: 2
No. of Satisfactory Scores	: 2
No. of Unsatisfactory Scores: 1

*****************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
	int i, scores[5], unsatSc = 0, satSc = 0, outSc = 0;
	char resp;
	
	do {
		printf("\nEnter 5 Exam Scores:");
		
		// INPUT
		
		for (i = 0; i < 5; i++) {
			if (i == 0) {
				printf("\n");
			}
			printf("\tExam Score No. %d => ", i + 1);
			scanf("%d", &scores[i]);
			
			if ((scores[i] < 1) || (scores[i] > 100)) {
				printf("\n\tOnly enter grades from 1 to 100. Please try again.\n\n");
				i -= 1;
			} else {
				continue;
			}
		}
		
		// calculation
		
		for (i = 0; i < 5; i++) {
			if ((scores[i] >= 1) && (scores[i] <= 59)) {
				unsatSc++;
			} else if ((scores[i] >= 60) && (scores[i] <= 89)) {
				satSc++;
			} else if ((scores[i] >= 90) && (scores[i] <= 100)) {
				outSc++;
			}
		}
		
		// OUTPUT
		
		printf("\nNo. of Outstanding Scores   : %d", outSc);
		printf("\nNo. of Satisfactory Scores  : %d", satSc);
		printf("\nNo. of Unsatisfactory Scores: %d", unsatSc);
		
		printf("\n\nTry Again [Y/N]? ");
		scanf(" %c", &resp);
	} while (toupper(resp) == 'Y');
	
	return 0;
}
