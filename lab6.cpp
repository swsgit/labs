// Spencer Stone
// Section 15245 T/Th
// 5/2/18 Lab #6C
// Phase 1
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

struct Party {
    int partyID;
    int numAdults;
    int numChild;
    char mealType;
    char weekend;
    double deposit;
};

int getInputFromKB_f1();
double calcCostOfMeals_f2(int numPerson, bool isAdult, char mealType);
double calcAdditionalCosts_f3(double totalBill, bool isWeekend);
int calcTotalBill_f4(Party party);

int main() {
    int numPerson = 10;
    char mealType = 'S';
    bool isAdult = false;
    double costOfMeals;
    double adjcosts;

    cout << showpoint << fixed << setprecision(2);

    // Test of 1st function
    getInputFromKB_f1();

    // Test of 2nd function
    costOfMeals = calcCostOfMeals_f2(numPerson, isAdult, mealType);
    cout << "Cost of meals: $" << costOfMeals << endl;

    // Test of 3rd fuction
    adjcosts = calcAdditionalCosts_f3(costOfMeals, true);
    cout << "Tip/tax and surcharge: $" << adjcosts << endl;
    
    // Test of 4th function
    Party party = {1, 10, 0 , 'S', 'Y', 100};
    calcTotalBill_f4(party);
}

int getInputFromKB_f1() {
    int partyID;
    int numAdults;
    int numChild;
    char mealType;
    char weekend;
    double deposit;

    cout << "Input party ID: ";
    cin >> partyID;
    if (partyID < 0 || !cin) {
        cout << "partyID must be a positive number" << endl;
        return EXIT_FAILURE;
    }

    cout << "Input number of adults: ";
    cin >> numAdults;
    if (numAdults < 0 || !cin) {
        cout << "number of adults must be a positive number" << endl;
        return EXIT_FAILURE;
    }

    cout << "Input number of children: ";
    cin >> numChild;
    if (numChild < 0 || !cin) {
        cout << "number of children must be a positive number" << endl;
        return EXIT_FAILURE;
    }
    cout << "Input meal type [S or D]: ";
    cin >> mealType;
    cout << mealType;
    if (toupper(mealType) != 'S' && toupper(mealType) != 'D') {
        cout << "Meal type must be S or D" << endl;
        return EXIT_FAILURE;
    }
    cout << "Input if its a weekend (Y or N): ";
    cin >> weekend;
    if (toupper(weekend) != 'Y' && toupper(weekend) != 'N') {
        cout << "Weekend must be Y or N" << endl;
        return EXIT_FAILURE;
    }
    cout << "Input deposit ammount: ";
    cin >> deposit;
    if (deposit < 0 || !cin) {
        cout << "Deposit must be a positive number" << endl;
        return EXIT_FAILURE;
    }

    cout << partyID << "\t" << numAdults << "\t" <<
    numChild << "\t" << mealType << "\t" <<
    weekend << "\t" << deposit << endl;

    return EXIT_SUCCESS;
}

double calcCostOfMeals_f2(int numPerson, bool isAdult, char mealType) {
    double deluxeCost = (25.80 * numPerson);
    double stdCost = (21.75 * numPerson);
    double childDeluxeCost = deluxeCost * 0.60;
    double childStdCost = stdCost * 0.60;
    switch (mealType) 
    {
        case 'S': if (isAdult) { return stdCost; } else { return childStdCost; } break;
        case 'D': if (isAdult) { return deluxeCost; } else { return childDeluxeCost; } break;
    } 
}

double calcAdditionalCosts_f3(double totalBill, bool isWeekend) {
    double adjTotalBill = totalBill * 0.18;
    if (isWeekend) { return adjTotalBill * 1.07; } else { return adjTotalBill; }
}

int calcTotalBill_f4(Party party) {
    double costOfMeals;
    double surcharge;
    double tipAndTax;
    double tcop;
    double tbd;

    cout << showpoint << fixed << setprecision(2);
    
    costOfMeals = calcCostOfMeals_f2(party.numAdults, true, party.mealType);
    costOfMeals += calcCostOfMeals_f2(party.numChild, false, party.mealType);

    if (toupper(party.weekend) == 'Y') { 
        surcharge = calcAdditionalCosts_f3(costOfMeals, true) - calcAdditionalCosts_f3(costOfMeals, false);
    } else {
        surcharge = 0.00;
    }

    tipAndTax = calcAdditionalCosts_f3(costOfMeals, false);

    tcop = costOfMeals + surcharge + tipAndTax;
    tbd = tcop - party.deposit;

    cout << "Party ID: " << party.partyID << endl;
    cout << "Number of adults: " << party.numAdults << endl;
    cout << "Number of children: " << party.numChild << endl;
    cout << "Cost for meals: $" << costOfMeals << endl;
    cout << "Surcharge: $" << surcharge << endl;
    cout << "Tax and tip: $" << tipAndTax << endl;
    cout << "Total cost of party: $" << tcop << endl;
    cout << "Deposit: $" << party.deposit << endl;
    cout << "total balence due: $" << tbd << endl; 

    return EXIT_SUCCESS;
}
/*
int getInputFromKB_f1(); <-- function 1
Input party ID: 10
Input number of adults: 0
Input number of children: 20
Input meal type [S or D]: S
SInput if its a weekend (Y or N): N
Input deposit ammount: 100
10      0       20      S       N       100.00
---------------------------------------------------
double calcCostOfMeals_f2(int numPerson, bool isAdult, char mealType); <-- function 2
Cost of meals: $130.50
---------------------------------------------------
double calcAdditionalCosts_f3(double totalBill, bool isWeekend); <-- function 3
Tip/tax and surcharge: $25.13
---------------------------------------------------
int calcTotalBill_f4(Party party); <-- function 4
Party ID: 1
Number of adults: 10
Number of children: 0
Cost for meals: $217.50
Surcharge: $2.74
Tax and tip: $39.15
Total cost of party: $259.39
Deposit: $100.00
total balence due: $159.39
*/