/*****************************************************************************

MACHINE PROBLEM 1

The formula for the computation of the volume of cylinder is V = pi*r^2*h.
Write a program that will compute and display computed volume of a cylinder
taken as inputs the diameter of its circular base and its height.

****************************************************************************/

#include <stdio.h>
#include <conio.h> 
#define pi 3.1416

int main()
{
    float d,h,r,V;
    
    printf("===VOLUME OF A CYLINDER CALCULATOR===\n\n");
    printf("Enter diameter: ");
    scanf("%f", &d);
    printf("Enter height: ");
    scanf("%f", &h);
    
    r = d/2;
    V = pi*r*r*h;
    // V = pi*(d/2)*(d/2)*h;
    
    printf("\nThe volume of the cylinder is %0.2f cm^3.",V);

    getch();
    return 0;
}
