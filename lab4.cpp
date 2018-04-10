// Spencer Stone
// Lab #4D
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    cout << showpoint << fixed << setprecision(2);

    double caffine;
    double adjc;
    int_fast32_t hours;

    cout << "Enter mg of caffine: ";
    cin >> caffine;
    while(caffine < 1 || caffine > 350 || !cin) {
        cout << "Caffine in mg must be a positive number no greater than 350" << endl;
        cout << "Enter mg of caffine: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> caffine;
    }

    cout << "Enter hours after ingestion: ";
    cin >> hours;
    while(hours < 1 || hours > 14 || !cin) {
        cout << "Hours must be a positive whole number less than 15" << endl;
        cout << "Enter hours after ingestion: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> hours;
    }

    adjc = caffine;
    cout << "[Total Caffine]\t[Hours]\t[Adjusted Caffine]" << endl;
    for (int i = 1; i <= hours; i++) {
        adjc *= 0.87;
        cout << caffine << "mg\t" << i << "\t" << adjc << "mg" << endl;
    }


    return 0;

}

/**
Enter mg of caffine: 300
Enter hours after ingestion: 5
[Total Caffine] [Hours] [Adjusted Caffine]
300.00mg        1       261.00mg
300.00mg        2       227.07mg
300.00mg        3       197.55mg
300.00mg        4       171.87mg
300.00mg        5       149.53mg
------------------------------------------------------------
Enter mg of caffine: 356
Caffine in mg must be a positive number no greater than 350
------------------------------------------------------------
Enter mg of caffine: ten
Caffine in mg must be a positive number no greater than 350
Enter mg of caffine:
 **/
