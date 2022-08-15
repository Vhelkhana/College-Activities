/**
 * A C program that increments the elements of A by 1
 */

#include <stdio.h>

// Function prototype

void increment(int* arr, int size);

// Main function

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(A) / sizeof(*A);
    
    printf("Value of A before being passed:");
    for(int i = 0; i < arraySize; i++) {
        printf(" %d", *(A + i));
    }

    increment(A, arraySize); // Function call
    
    printf("\nValue of A after being passed:");
    for(int i = 0; i < arraySize; i++) {
        printf(" %d", *(A + i));
    }
}

// Function definition

void increment(int* arr, int size)
{
    for(int i = 0; i < size; i++) {
        *(arr + i) += 1;
    }
}
