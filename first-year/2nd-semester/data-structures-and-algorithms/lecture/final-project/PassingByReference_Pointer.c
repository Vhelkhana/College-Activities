/**
 * A C program that increments num by 1
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototype

void increment(int* n);

// Main function

int main()
{
    int num = 2;

    printf("\nValue of num before being passed: %d", num);
    increment(&num); // Function call
    printf("\nValue of num after being passed: %d", num);

    return 0;
}

// Function definition

void increment(int* n)
{
    printf("\nValue of *n = %d", *n);
    *n += 1;
}


