/****************************************************************************

MIDTERM EXAMINATION (LAB) - MP2

Given as input integer number of seconds, print as output its equivalent time
in hours, minutes, and seconds. Recommended output format is something like:

Sample Output:

Enter time in seconds: 7322
7322 seconds is equivalent to 2 hours 2 minutes 2 seconds.

*****************************************************************************/

#include <stdio.h>
#include <conio.h>

int s, H, M, S;

int main()
{
	printf("Enter time in seconds: ");
	scanf("%d", &s);
	
	H = s / 3600; 
	M = (s - (3600 * H)) / 60;
	S = (s - (3600 * H) - (M * 60));
	
	printf("%d seconds is equivalent to %d hours %d minutes %d seconds.\n", s, H, M, S);
	
    getch();
    return 0;
}
