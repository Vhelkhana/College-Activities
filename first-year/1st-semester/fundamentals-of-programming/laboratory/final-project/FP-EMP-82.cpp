/****************************************************************************

FINAL PROJECT (LAB) - EMP-82

*****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int CTR, X, SUM = 0;

    cout << "This program computes and displays sum of 10 integer values\n";
    for(CTR = 1; CTR <= 10; CTR++)
    {
        cout << "Enter an integer value: ";
        cin >> X;
        SUM += X;
    }
    cout << "The SUM is " << SUM << "\n";

  return 0;
}
