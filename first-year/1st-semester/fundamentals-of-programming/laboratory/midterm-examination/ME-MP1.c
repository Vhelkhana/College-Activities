/****************************************************************************

MIDTERM EXAMINATION (LAB) - MP1

An automobile is used for commuting purposes. Write a program that takes as
input the distance of the commute, the automobile's fuel efficiency in
kilometers per liter, and price of gasoline per liter and then outputs the
cost of the gasoline for the commute.

*****************************************************************************/

#include <stdio.h>

float costGas, distanceCommute, fuelEfficiency, priceGas;

int main()
{
	printf("Enter distance of the commute: ");
	scanf("%f", &distanceCommute);
	
	printf("Enter fuel efficiency in kilometers per liter: ");
	scanf("%f", &fuelEfficiency);
	
	printf("Enter price of gasoline per liter: ");
	scanf("%f", &priceGas);
	
    costGas = (distanceCommute/fuelEfficiency) * priceGas;
    printf("\nThe cost of the gasoline of the commute is PHP %0.2f.\n", costGas);
    
    return 0;
}
