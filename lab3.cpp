// Spencer Stone
// Section 15245 T/Th
// 3/8/18 Lab #C

#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void printBill(string pname, double hours, double billCost);

int main() {
    string pName;
    double hours;
    double billCost;
    const double apm = 9.95;
    const double bpm = 14.95;
    const double cpm = 19.95;

    cout << showpoint << fixed << setprecision(2);

    // Recieve input for package name and error check
    cout << "Input package name [A, B, C]: ";
    cin >> pName;
    std:transform(pName.begin(), pName.end(), pName.begin(), ::toupper);
    if (pName != "A" && pName != "B" && pName != "C") {
        cout << "Package name must be either A, B or C" << endl;

        return 1;
    }

    // Recieve input for hours used and error check
    cout << "Input hours used: ";
    cin >> hours;
    if (hours < 0 || hours > 200) {
        cout << "Hours must be a positive integer less than or equal to 200" << endl;

        return 1;
    }

    if (pName == "A") {
        if (hours > 10) {billCost = ((hours - 10) * 2.00) + apm; }
        else { billCost = apm; }
        printBill(pName, hours, billCost);

        // Extra credit
        if (hours == 30) {
            cout << "You would save $" << (billCost - 19.95) <<
            " by switching to package C" << endl;
            cout << "You would save $" << (billCost - ((hours - 20) + bpm)) <<
            " by switching to package B" << endl;
        }

    }
    else if (pName == "B") {
        if (hours > 20) { billCost = (hours - 20) + bpm; }
        else { billCost = bpm; }
        printBill(pName, hours, billCost);
    }
    else if (pName == "C") {
        billCost = cpm;
        printBill(pName, hours, billCost);
    }

    return 0;
}

void printBill(string pname, double hours, double billCost) {
    cout << "package " << pname << ", usage " << hours << " hours\t\t"
    << "Bill $" << billCost << endl;
}
/*
Input package name [A, B, C]: B
Input hours used: 25
package B, usage 25.00 hours            Bill $19.95
------------------------------------------------------
Input package name [A, B, C]: A
Input hours used: 30
package A, usage 30.00 hours            Bill $49.95
You would save $30.00 by switching to package C
You would save $25.00 by switching to package B
------------------------------------------------------
Input package name [A, B, C]: D
Package name must be either A, B or C
*/