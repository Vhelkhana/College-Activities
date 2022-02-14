/****************************************************************************

MACHINE PROBLEM 5

The interest paid on a savings account is compounded daily. This means that
if you start with StartBal dollars in the bank, at the end of the first day
you will have a balance of

    StartBal * (1+ Rate/365)

dollars, where Rate is the annual interest rate (0.10 if annual rate is 10
percent).

At the end of the second day, you will have

    StartBal * (1+Rate/365) * (1+Rate/365)

dollars, and at the end of N days you will have

    StartBal * (1+Rate/365)N [Note: (1+Rate/365) raise to N]

dollars. Write a program that processes values for StartBal, Rate, and N,
and computes the display the Final Account Balance.

*****************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <math.h>

void AccBal(float StartBal, float Rate, float N);

int main()
{
    float StartBal, Rate, N;
    
    printf("Enter starting account balance (in USD): ");
    scanf("%f", &StartBal);
    printf("Enter annual interest rate: ");
    scanf("%f", &Rate);
    printf("Enter days passed: ");
    scanf("%f", &N);
    
    Rate /= 100;
    
    AccBal(StartBal, Rate, N);

    getch();
    return 0;
}

void AccBal(float StartBal, float Rate, float N)
{
    float FinalBal; 
    
    FinalBal = StartBal * pow((1 + Rate / 365), N);
    printf("\nYour final account balance is USD %0.2f.", FinalBal);
}
