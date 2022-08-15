/****************************************************************************

SYNCHRONOUS ACTIVITY 1 - HANDS-ON EXERCISE

Write a program to read in an integer N and compute Slow = Summation of i
from 1 to N = 1 + 2 + 3 + 4 + ... + N (the sum of all integers from 1 to N).
Then compute Fast = (N * (N + 1)) / 2 and compare Fast and Slow. Your program
should print both Fast and Slow and indicate whether they are equal. (You
would need a loop to compute Slow.)

*****************************************************************************/

#include <stdio.h>

int main ()
{
  	int Slow = 0, Fast = 0, N = 0, i, sum = 0;
  
  	printf("Enter an integer: ");
  	scanf("%d", &N);
  
  	// Computation of Slow
  
  	for (i = 1; i <= N; i++)
  	{
		sum += i;
  	}
	  
  	Slow = sum;

  	// Computation of Fast
  
  	Fast = (N * (N + 1)) / 2;
  
  	// Displaying results
  
  	printf("Slow: %d\n", Slow);
  	printf("Fast: %d\n", Fast);
  	
  	if (Fast == Slow)
  		printf("Slow and Fast is equal.");
  	else
    	printf("They are not equal.");

  	return 0;
}

