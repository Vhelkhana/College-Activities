/****************************************************************************

FINAL PROJECT (LEC) - IF-ELSE LADDER IN C++

The following table shows the daily flights from one city to another:

Departure time      Arrival time
8:00 a.m.           10:16 a.m.
9:43 a.m.           11:52 a.m.
11:19 a.m.          1:31 p.m.
12:47 p.m.          3:00 p.m.
2:00 p.m.           4:08 p.m.
3:45 p.m.           5:55 p.m.
7:00 p.m.           9:20 p.m.
9:45 p.m.           11:58 p.m.

Write a program that asks user to enter a time (expressed in hours and
minutes, using the 24-hour clock). The program then displays the departure
and arrival times for the flight whose departure time is closest to that
entered by the user:

Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m.

Hint: Convert the input into a time expressed in minutes since midnight, and
compare it to the departure times, also expressed in minutes since midnight.
For example, 13:15 is 13 x 60 + 15 = 795 minutes since midnight, which is
closer to 12:47 p.m. (767 minutes since midnight) than to any of the other
departure times.

**machine problem from:
King, K. N. (2008). C programming: A modern approach, 2nd edition (2nd ed.).
W. W. Norton & Company.

*****************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int hours, minutes, depMin;
    char separator = ':';
    
    cout << "Departure time      Arrival time\n";
    cout << "8:00 a.m.           10:16 a.m.\n"; // 480 ==> 9:45pm - 8am = 615mins / 2 = 307.5 ==> 172.5 to 531.5
    cout << "9:43 a.m.           11:52 a.m.\n"; // 583 ==> 8am - 9:43am = 103mins / 2 = 51.5 ==> 531.5 to 631
    cout << "11:19 a.m.          1:31 p.m.\n"; // 679 ==> 9:43am - 11:19am = 96mins / 2 = 48 ==> 631 to 723
    cout << "12:47 p.m.          3:00 p.m.\n"; // 767 ==> 11:19am - 12:47pm = 88mins / 2 = 44 ==> 723 to 803.5
    cout << "2:00 p.m.           4:08 p.m.\n"; // 840 ==> 12:47pm - 2pm = 73mins / 2 = 36.5 ==> 803.5 to 892.5
    cout << "3:45 p.m.           5:55 p.m.\n"; // 945 ==> 2pm - 3:45pm = 105mins / 2 = 52.5 ==> 892.5 to 1042.5
    cout << "7:00 p.m.           9:20 p.m.\n"; // 1140 ==> 3:45pm - 7pm = 195mins / 2 = 97.5 ==> 1042.5 to 1125
    cout << "9:45 p.m.           11:58 p.m.\n"; // 1305 ==> 7pm - 9:45pm = 165mins / 2 = 82.5 ==> 1125 to 1432.5
    
    do
    {
        cout << "\n\nEnter a 24-hour time: ";
        cin >> hours >> separator >> minutes;
        if ((hours < 0) || (hours > 24) || (minutes < 0) || (minutes > 59))
            cout << "Please enter a valid input.";
    }
    while ((hours < 0) || (hours > 24) || (minutes < 0) || (minutes > 59));
    
    depMin = (hours * 60) + minutes;
    
    if (depMin >= 172.5 && depMin <= 531.5)
        cout << "Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n";
    else if (depMin >= 531.6 && depMin <= 631)
        cout << "Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n";
    else if (depMin >= 632 && depMin <= 723)
        cout << "Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n";
    else if (depMin >= 724 && depMin <= 803.5)
        cout << "Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n";
    else if (depMin >= 803.6 && depMin <= 892.5)
        cout << "Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n";
    else if (depMin >= 892.6 && depMin <= 1042.5)
        cout << "Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n";
    else if (depMin >= 1042.6 && depMin <= 1125)
        cout << "Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n";
    else if (depMin >= 1126 && depMin <= 1432.5)
        cout << "Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n";

    return 0;
}
