/****************************************************************************

FINAL PROJECT (LAB) - IF-ELSE1

*****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int X;

    cout << " Enter value of X: ";
    cin >> X;
    if (X < 10)    // simple condition
    {
        cout << X << " is acceptable!\n";
    }
    else
    {
        cout << X << " is not acceptable!\n";
    }
    
    return 0;
}