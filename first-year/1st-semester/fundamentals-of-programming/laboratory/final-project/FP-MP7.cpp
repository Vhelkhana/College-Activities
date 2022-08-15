/****************************************************************************

FINAL PROJECT (LAB) - MP7

Write a program to test if a non-negative integer number is prime or not.

Sample Output 1:
Enter a non-negative integer number: 11
11 is a prime number

Sample Output 2:
Enter a non-negative integer number: 15
15 is a non-prime number

*****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int nNum, i, flag = 0;
	
	cout << "Enter a non-negative integer number: ";
	cin >> nNum;
	
	if (nNum <= 1) // numbers 1 and below are not prime
	{
		cout << nNum << " is a non-prime number";
	}
	else if (nNum > 1)
	{
		for(i = 2; i <= nNum/2; i++)
	    {
	        if(nNum % i == 0)
			{
	            flag = 1;
	        }
	    }
	    if (flag == 1)
		{
			cout << nNum << " is a non-prime number";
		}
	    else
		{
			cout << nNum << " is a prime number";
		}
	}
	
	return 0;
}
