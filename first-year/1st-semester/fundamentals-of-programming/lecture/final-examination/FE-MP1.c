/****************************************************************************

FINAL EXAMINATION (LEC)

Write a program that reads in a room number, the room's capacity, and the
size of the class enrolled so far and prints an output line showing the
classroom number, the capacity, number of seats filled, number of seats
available, and whether the class is filled or not filled. Your program should
produce a reasonable-looking output.

Sample Output No. 1:

Enter Room No.						: 310
Enter Room Capacity					: 50
Enter size of the class Enrolled	: 25

Room	Capacity	Enrolment	Empty Seats	Filled/Not Filled
310		  50		   25			25		   Not Filled

Sample Output No. 2:

Enter Room No.						: 310
Enter Room Capacity					: 50
Enter size of the class Enrolled	: 50

Room	Capacity	Enrolment	Empty Seats	Filled/Not Filled
310 	  50		   50		     0			Filled

*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int rmNo, rmCap, enrol, empSeat;
	char fld[7] = "Filled", notFld[11] = "Not Filled", fill[11], resp;
	
	do
	{
		// INPUT
	
		printf("\nEnter Room No.\t\t\t: ");
		scanf("%d", &rmNo);
		printf("Enter Room Capacity\t\t: ");
		scanf("%d", &rmCap);
		printf("Enter size of the class Enrolled: ");
		scanf("%d", &enrol);
		
		// calculation
		
		empSeat = rmCap - enrol;
		
		// OUTPUT
		
		if (empSeat == 0)
		{
			strcpy(fill, fld);
		}
		else
		{
			strcpy(fill, notFld);
		}
		
		printf("\nRoom\tCapacity\tEnrolment\tEmpty Seats\tFilled/Not Filled\n");
		printf("%d\t%d\t\t%d\t\t%d\t\t%s\t\n", rmNo, rmCap, enrol, empSeat, fill);
		
		printf("\n\nTry Again [Y/N]? ");
		scanf(" %c", &resp);
	}
	while (toupper(resp) == 'Y');

	return 0;
}
