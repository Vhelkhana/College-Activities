/****************************************************************************

FINAL PROJECT (LAB) - MP6

Write a program that will read five (5) grades in percentile format [0-100]
and then determine and display the lowest grade entered, the highest grade
entered, and the general weighted average (GWA) of the five (5) grades
entered.

*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int grades[5], i, lGrade, hGrade;
	float sum = 0, GWA;
	char resp;
	
	do {
		cout << "Enter 5 grades in percentile format within 1-100: ";
	
		for (i = 0; i < 5; i++) {
				if (i == 0) {
					cout << "\n";
				}
				cout << "\tGrade No. " << i + 1 << " => ";
				cin >> grades[i];
				if ((grades[i] < 0) || (grades[i] > 100)) {
					cout << "\n\tOnly enter grades from 0 to 100. Please try again.\n\n";
					i -= 1;
				} else {
					sum += grades[i];
				}		
			}
		
		GWA = sum / 5;
		
		lGrade = grades[0];
		hGrade = grades[0];
		
		for (i = 0; i < 5; i++) {
			if (grades[i] < lGrade)
				lGrade = grades[i];
			else if (grades[i] > hGrade)
				hGrade = grades[i];
		}
		
		cout << "\nThe highest grade is " << hGrade << ".";
		cout << "\nThe lowest grade is " << lGrade << ".";
		cout << "\nThe general weighted average is " << std::fixed << std::setprecision(2) << GWA << ".";
		
		cout << "\n\nTry Again [Y/N]? ";
		cin >> resp;
	} while (toupper(resp) == 'Y');
	
	
	return 0;
}
