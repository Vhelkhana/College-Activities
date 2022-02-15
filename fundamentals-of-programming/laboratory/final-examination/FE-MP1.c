/****************************************************************************

FINAL EXAMINATION (LAB) - MP1

Write a program to input a unit of length (floating-point value). Print out
the perimeter of a square, the area of the square, and the volume of a square
box using that input as the value for side.

*****************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
	float peri, area, vol, sdL;
	char resp;
	
	do {
		// INPUT
		
		printf("\nEnter side length of the square in m: ");
		scanf("%f", &sdL);
		
		// calculation
		
		peri = sdL * 4;
		area = sdL * sdL;
		vol = sdL * sdL * sdL;
		
		// OUTPUT
		
		printf("\nPerimeter of the square: %0.2f m", peri);
		printf("\nArea of the square: %0.2f m^2", area);
		printf("\nVolume of the square box: %0.2f m^3", vol);
	
		printf("\n\nTry Again [Y/N]? ");
		scanf(" %c", &resp);
	} while (toupper(resp) == 'Y');
	
	return 0;
}
