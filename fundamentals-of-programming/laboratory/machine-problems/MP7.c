/****************************************************************************

MACHINE PROBLEM 7

Write a program to test if a non-negative integer number is prime or not.

Sample Output 1:
Enter a non-negative integer number: 11
11 is a prime number

Sample Output 2:
Enter a non-negative integer number: 15
15 is a non-prime number

*****************************************************************************/

#include <stdio.h>

int main()
{
	int nNum, i, flag = 0;
	
	printf("Enter a non-negative integer number: ");
	scanf("%d", &nNum);
	
	if (nNum <= 1) // numbers 1 and below are not prime
		printf("%d is a non-prime number\n", nNum);
	else if (nNum > 1) {
		for(i = 2; i <= nNum/2; i++) {
	        if(nNum % i == 0) {
	            flag = 1;
	        }
	    }
	    if (flag == 1)
	        printf("%d is a non-prime number\n", nNum);
	    else
	        printf("%d is a prime number\n", nNum);
	}

	return 0;
}
