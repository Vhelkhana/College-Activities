/*****************************************************************************

MACHINE PROBLEM 2

Write a program that determines the additional state tax owed by the employee.
The S	tate charges a 4-percent tax on net income. Determine net income by
subtracting a $500 allowance for each dependent from gross income. Your
program should read gross income, number of dependents, and the tax amount
already deducted. It should then compute the actual tax owed and print the
difference between tax owed and tax deducted followed by the message SEND
CHECK or REFUND, depending on whether the difference is positive or negative.

*****************************************************************************/
#include <stdio.h>

int main()
{
    float gIncome, nIncome, tDducted, tOwed, diff;
    int dpendent;
    
    printf("Enter gross income [USD]: ");
    scanf("%f", &gIncome);
    printf("Enter number of dependents: ");
    scanf("%d", &dpendent);
    printf("Enter deducted tax amount [USD]: ");
    scanf("%f", &tDducted);
    
    nIncome = gIncome - (dpendent * 500);
    tOwed = nIncome * 0.04;
    diff = tOwed - tDducted;
    
    printf("\nnet income: %0.2f", nIncome);
    printf("\ndifference: %0.2f", diff);
    printf("\n\nThe tax you owe is USD %0.2f.\n\n", tOwed);
    
    if (diff > 0)
        printf("SEND CHECK\n");
    else
        printf("REFUND\n");
    
    return 0;
}
