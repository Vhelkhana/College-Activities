/****************************************************************************

FINAL PROJECT (LAB) - EMP-32

*****************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
  char RColor;

  cout << "Enter the letter representing the color of the Rainbow: ";
  cin >> RColor;
  switch(toupper(RColor)) {
    case 'R': cout << RColor << " represents RED!";
	          break;
    case 'O': cout << RColor << " represents ORANGE!";
    	      break;
    case 'Y': cout << RColor << " represents YELLOW!";
    	      break;
    case 'G': cout << RColor << " represents GREEN!";
    	      break;
    case 'B': cout << RColor << " represents BLUE!";
    	      break;
    case 'I': cout << RColor << " represents INDIGO!";
    	      break;
    case 'V': cout << RColor << " represents VIOLET!";
    	      break;
    default: cout << "Invalid Input!!!";
  }

   return 0;
}
