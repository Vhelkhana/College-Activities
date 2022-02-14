/****************************************************************************

FINAL PROJECT (LAB) - EMP-9

*****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int CTR, N, FACT = 1;

  cout << "This program computes and displays Factorial of N\n";
  cout << "Enter value for N: ";
  cin >> N;
  for(CTR = 1; CTR <= N; CTR++)
    FACT = FACT * CTR;      // FACT *= CTR
  cout << "The Factorial of " << N << " is " << FACT << "\n";

  return 0;
}
