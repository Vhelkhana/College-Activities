/****************************************************************************

FINAL PROJECT (LEC) - SWITCH STATEMENT IN C++

Using the switch statement write a program that converts a numerical grade
into a letter grade:

Enter numerical grade: 84
Letter grade: B

Use the following grading scale: A = 90-100, B = 80-89, C = 70-79, D = 60-69,
F = 0-59. Print an error message if the grade is larger than 100 or less than
0. Hint: Break the grade into two digits, then use a switch statement to test
the ten's digit.

**machine problem from:
King, K. N. (2008). C programming: A modern approach, 2nd edition (2nd ed.).
W. W. Norton & Company.

*****************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    float numGrade;
    int intGrade;
    
    do {
        cout << "Enter numerical grade: ";
        cin >> numGrade;
        
        if ((numGrade < 0) || (numGrade > 100))
            cout << "Numerical grade should be from 0-100.\n\n";
    }
    while ((numGrade < 0) || (numGrade > 100));
    
    intGrade = numGrade * 0.1;
        
    switch(intGrade) {
        case 0: 
        case 1: 
        case 2: 
        case 3: 
        case 4: 
        case 5: cout << "Letter grade: F\n";
                break;
        case 6: cout << "Letter grade: D\n";
                break;
        case 7: cout << "Letter grade: C\n";
                break;
        case 8: cout << "Letter grade: B\n";
                break;
        case 9: 
        case 10: cout << "Letter grade: A\n";
                 break;
    }
    
    return 0;
}
