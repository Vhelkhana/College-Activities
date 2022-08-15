/****************************************************************************

FINAL PROJECT (LAB) - IF-ELSE2

*****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int X;

    cout << " Enter value of X: ";
    cin >> X;
    if ((X >= 1) && (X <= 10))    // complex/compound condition
    {    
        cout << X << " is within the range!\n";
    }
    else
    {    
        cout << X << " is out of the range!\n";
    }

    return 0;
}
