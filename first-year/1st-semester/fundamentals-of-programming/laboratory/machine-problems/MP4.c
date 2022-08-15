/****************************************************************************

MACHINE PROBLEM 4

Write a program that determines whether a meeting room is in violation of
fire law regulations regarding the maximum room capacity. The program will
read in the maximum room capacity and the number of people attending the
meeting. If the number of people is less than or equal to the maximum room
capacity, the program announces that it is legal to hold the meeting and
tells how many additional people may legally attend. If the number of people
exceeds the maximum room capacity, the program announces that the meeting
cannot be held as planned due to fire regulations and tells how many people
must be excluded in order to meet the fire regulations.

Sample Output No. 1:

Enter the Maximum Room Capacity : 50
Enter the No. of People Attending : 45
It is legal to hold the meeting...
5 additional people my legally attend

Sample Output No. 2:

Enter the Maximum Room Capacity : 50
Enter the No. of People Attending : 55
The meeting cannot be held as planned due to fire regulations...
5 people must be excluded in order to meet the fire regulations

*****************************************************************************/
#include <stdio.h>

void mtFrReg(int rmCap, int nmPeople);

int main()
{
    int rmCap, nmPeople;
    
    printf("Enter the Maximum Room Capacity: ");
    scanf("%d", &rmCap);
    printf("Enter the No. of People Attending: ");
    scanf("%d", &nmPeople);
    
    mtFrReg(rmCap, nmPeople);
    
    return 0;
}

void mtFrReg(int rmCap, int nmPeople)
{
    int adPeople, exPeople;

    if (nmPeople <= rmCap)
    {
        adPeople = rmCap - nmPeople;
        printf("It is legal to hold the meeting...");
        if ((adPeople != 1) && (adPeople != 0))
        {
            printf("\n%d additional people may legally attend.\n", adPeople);
        }
        else
        {
            printf("\n%d additional person may legally attend.\n", adPeople); 
        }
    }
    else if (nmPeople > rmCap)
    {
        exPeople = nmPeople - rmCap;
        printf("The meeting cannot be held as planned due to fire regulations...");
		if (exPeople != 1)
        {
            printf("\n%d people must be excluded in order to meet the fire regulations.\n", exPeople);
        }
	        
	    else
        {
            printf("\n%d person must be excluded in order to meet the fire regulations.\n", exPeople);
        }
    }
}
