// Spencer Stone
// Lab #4D
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

void printResults(string product, float caffine, int hours);

int main() {
    cout << showpoint << fixed << setprecision(2);

    float caffine;
    int hours;
    string product;

    cout << "Enter product name: ";
    getline(cin, product);

    cout << "Enter mg of caffine: ";
    cin >> caffine;
    if (caffine < 0 || caffine > 350) {
        cout << "Caffine in mg must be a positive number no greater than 350" << endl;
        return 1;
    }

    cout << "Enter hours after ingestion: ";
    cin >> hours;
    if (hours < 0 || hours > 14) {
        cout << "Hours must be a positive number less than 15" << endl;
        return 1;
    }

    printResults(product, caffine, hours);

    return 0;

}

void printResults(string product, float caffine, int hours) {
    float adjc;
    adjc = caffine;
    for (int i = 0; i <= hours; i++) {
        adjc *= 0.87;
    }

    cout << product << "\t" <<
     caffine << "mg\t\t" << 
     adjc << "mg" << endl;
}
/**
Enter product name: 16 oz Starbucks coffee
Enter mg of caffine: 310
Enter hours after ingestion: 10
------------------------------------------------------------
16 oz Starbucks coffee  310.00mg        67.00mg
5-hr Energy drink       245.00mg        80.41mg
Black tea               47.00mg         20.38mg
Red Bull                80.00mg         13.09mg
------------------------------------------------------------
Enter mg of caffine: 356
Caffine in mg must be a positive number no greater than 350
------------------------------------------------------------
Enter hours after ingestion: 16
Hours must be a positive number less than 15
 **/