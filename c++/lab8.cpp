// Spencer Stone
// Section 15245 T/Th
// 5/2/18 Lab #8A
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>

using namespace std;

struct House {
    char id[4];
    double income;
    int residents;
};

int getHouseholds(vector<House>& houses);
void printHouseholds(vector<House> houses);
void printAboveAverageIncome(vector<House> houses);
void printBelowPovertyLevel(vector<House> houses);
void printSortedHouses(vector<House> houses);
void printMedianHouseholdIncome(vector<House> houses);
bool compareByIncome(const House &a, const House &b);

int main() {
    int err;
    vector<House> houses;
    char userInput = ' ';
    
    cout << showpoint << fixed << setprecision(2);

    err = getHouseholds(houses);
    if (err != 0) {
        return 1;
    }
    while ((int)userInput != 27) { // ESC to quit
        system("CLS");
        cout << "Options (press ESC to quit):\n"
             << "\tA) Print all of the input data.\n"
             << "\tB) Calculate the average household income.\n"
             << "\tC) Percentage of households having an income below the poverty level.\n"
             << "\tD) Print all of the input data sorted by household income.\n"
             << "\tE) Print the median household income.\n"
             << "Press key for selection: ";
        userInput = _getch();

        switch (toupper(userInput)) {
            case 'A': 
                system("CLS"); 
                printHouseholds(houses);
                cout << "Press any key to exit";
                userInput = _getch();
                break;
            case 'B': 
                system("CLS"); 
                printAboveAverageIncome(houses);
                cout << "Press any key to exit";
                userInput = _getch(); 
                break;
            case 'C': 
                system("CLS"); 
                printBelowPovertyLevel(houses);
                cout << "Press any key to exit";
                userInput = _getch(); 
                break;
            case 'D': 
                system("CLS"); 
                printSortedHouses(houses);
                cout << "Press any key to exit";
                userInput = _getch(); 
                break;
            case 'E': 
                system("CLS"); 
                printMedianHouseholdIncome(houses);
                cout << "Press any key to exit";
                userInput = _getch(); 
                break;
        }
    }

    return 0;
}

int getHouseholds(vector<House>& houses) {
    House house;
    char id[4];
    double income;
    int residents;
    ifstream infile;

    infile.open("households.txt");
    if (!infile) {
        return 1;
    }

    while (!infile.eof()) {
        for (unsigned int i = 0; i < 4; i++) {
            infile >> id[i];
        }
        infile >> income;
        infile >> residents;

        for (unsigned int i = 0; i < 4; i++) {
            house.id[i] = id[i];
        }
        house.income = income;
        house.residents = residents;
        houses.push_back(house);
    }

    return 0;
}

void printHouseholds(vector<House> houses) {
    cout << "[ID]\t[Income]\t[Members]" << endl;
    for (unsigned int i = 0; i < houses.size(); i++) {
        cout << houses[i].id << setw(12)
             << houses[i].income << setw(10)
             << houses[i].residents << endl;
    }
}

void printAboveAverageIncome(vector<House> houses) {
    string houseid;
    double avgincome = 0;
    
    cout << "Households with an income above the average:" << endl;
    cout << "[ID]\t[Income]" << endl;

    for (unsigned int i = 0; i < houses.size(); i++) {
        avgincome += houses[i].income;
    }
    avgincome /= houses.size();

    for (unsigned int i = 0; i < houses.size(); i++) {
        if (houses[i].income > avgincome) {
            houseid = houses[i].id;
            cout << houseid << "\t" << houses[i].income << endl; 
        }
    }

    cout << "Average household income: " << avgincome << endl;
}

void printBelowPovertyLevel(vector<House> houses) {
    double numBelowPovLevel;
    double P;

    cout << "Percentage of households below poverty level: ";

    for (unsigned int i = 0; i < houses.size(); i++) {
        P = 8000.00 + (500.00 * (houses[i].residents - 2));
        if (houses[i].income < P) {
            numBelowPovLevel++;
        }
    }

    cout  << "%" << (numBelowPovLevel / (double)houses.size()) * 100 << endl;
}

bool compareByIncome(const House &a, const House &b)
{
    return a.income < b.income;
}

void printSortedHouses(vector<House> houses) {
    sort(houses.begin(), houses.end(), compareByIncome);
    printHouseholds(houses);
}

void printMedianHouseholdIncome(vector<House> houses) {
    int ma = (houses.size() / 2);
    sort(houses.begin(), houses.end(), compareByIncome);

    if (houses.size() % 2 == 0) {
        cout << "Median household income: "
             << (houses[ma].income + houses[ma - 1].income) / 2 << endl;
    } else {
        cout << "Median household income: "
             << houses[ma].income << endl;
    }
}
/*
<----------households.txt---------->
WHVC	34000.00	5
AAAA	10500.00	8
BURB	23500.00	2
CCCC	15000.00	4
DATA	8000.00	    3
EEEE	36000.00	5
FADE	8500.00	    4
GATE	25000.00	1
HILO	3000.00	    1
JURY	100000.00	5
KNEL	80000	    4
LIST	41000.00	3
MEMM	5000.00	    2
PQRS	18000.00	2
RELM	27500.00	4
SOLD	22100.00	2
<----------------Menu---------------->
Options (press ESC to quit):
        A) Print all of the input data.
        B) Calculate the average household income.
        C) Percentage of households having an income below the poverty level.
        D) Print all of the input data sorted by household income.
        E) Print the median household income.
Press key for selection:
<----------------Menu A---------------->
[ID]    [Income]        [Members]
WHVC    34000.00         5
AAAA    10500.00         8
BURB    23500.00         2
CCCC    15000.00         4
DATA     8000.00         3
EEEE    36000.00         5
FADE     8500.00         4
GATE    25000.00         1
HILO     3000.00         1
JURY   100000.00         5
KNEL    80000.00         4
LIST    41000.00         3
MEMM     5000.00         2
PQRS    18000.00         2
RELM    27500.00         4
SOLD    22100.00         2
Press any key to exit
<----------------Menu B---------------->
Households with an income above the average:
[ID]    [Income]
WHVC    34000.00
EEEE    36000.00
JURY    100000.00
KNEL    80000.00
LIST    41000.00
Average household income: 28568.75
Press any key to exit
<----------------Menu C---------------->
Percentage of households below poverty level: %31.25
Press any key to exit
<----------------Menu D---------------->
[ID]    [Income]        [Members]
HILO     3000.00         1
MEMM     5000.00         2
DATA     8000.00         3
FADE     8500.00         4
AAAA    10500.00         8
CCCC    15000.00         4
PQRS    18000.00         2
SOLD    22100.00         2
BURB    23500.00         2
GATE    25000.00         1
RELM    27500.00         4
WHVC    34000.00         5
EEEE    36000.00         5
LIST    41000.00         3
KNEL    80000.00         4
JURY   100000.00         5
Press any key to exit
<----------------Menu E---------------->
Median household income: 22800.00
Press any key to exit
*/
