// Spencer Stone
// Section 15245 T/Th
// 5/2/18 Lab #6C
#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

struct Party {
    int partyID;
    int numAdults;
    int numChild;
    char mealType;
    char weekend;
    double deposit;
};

int getInputFromFile_f1(vector<Party>& partys);
double calcCostOfMeals_f2(int numPerson, bool isAdult, char mealType);
double calcAdditionalCosts_f3(double totalBill, bool isWeekend);
int calcTotalBill_f4(Party party);

int main() {
    int err;
    vector<Party> partys;

    err = getInputFromFile_f1(partys);
    if (err != 0) {
        return 1;
    }
    for (unsigned int i = 0; i < partys.size(); i++) {
        err = calcTotalBill_f4(partys[i]);
        if (err != 0) {
            return 1;
        }
    }

    return 0;
}

int getInputFromFile_f1(vector<Party>& partys) {
    ifstream infile;
    ofstream ofile;
    Party party;
    int partyID;
    int numAdults;
    int numChild;
    char mealType;
    char weekend;
    double deposit;
    bool error;

    infile.open("data.txt");
    if (!infile) {
        return 1;
    }
    ofile.open("errors.txt");
    if (!ofile) {
        return 1;
    }

    while (!infile.eof()) {
        error = false;
        infile >> partyID;
        ofile << "PartyID: " << partyID << endl;
        if (partyID < 0) {
            ofile << "PartyID must be a positive number" << endl;
            error = true;
        }

        infile >> numAdults;
        if (numAdults < 0) {
            ofile << "number of adults must be a positive number" << endl;
            error = true;
        }

        infile >> numChild;
        if (numChild < 0) {
             ofile << "number of children must be a positive number" << endl;
             error = true;
        }

        infile >> mealType;
        if (toupper(mealType) != 'S' && toupper(mealType) != 'D') {
            ofile << "Meal type must be S or D" << endl;
            error = true;
        }

        infile >> weekend;
        if (toupper(weekend) != 'Y' && toupper(weekend) != 'N') {
            ofile << "Weekend must be Y or N" << endl;
            error = true;
        }

        infile >> deposit;
        if (deposit < 0) {
            ofile << "Deposit must be a positive number" << endl;
            error = true;
        }

        if (!error) {
            ofile << "No errors detected" << endl;
        }
        ofile << "---------------------------------------" << endl;

        party.partyID = partyID;
        party.numAdults = numAdults;
        party.numChild = numChild;
        party.mealType = mealType;
        party.weekend = weekend;
        party.deposit = deposit;
        partys.push_back(party);
    }
    infile.close();

    return 0;
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
    cout << "------------------------------------" << endl;
}
/*
<-------------data.txt------------->
1	10 	0	S	Y	100.00
2	27	3	D	Y	57.50
3	125	17	D	N	0.00
4	4	0	S	N	25.00
5	0		25	S	Y	23.75
6	250	43	D	N	500.00
7	0	0	D	N	0.0
8	10	0	R	Y	10.00
9	17	3	D	R	15.00
10	5	0	D	Y	275.00
11	-3	10	D	Y	20.00
12	14	-1	S	N	30.00
13	20	3	D	Y	-10.00
<-------------errors.txt------------->
PartyID: 1
No errors detected
---------------------------------------
PartyID: 2
No errors detected
---------------------------------------
PartyID: 3
No errors detected
---------------------------------------
PartyID: 4
No errors detected
---------------------------------------
PartyID: 5
No errors detected
---------------------------------------
PartyID: 6
No errors detected
---------------------------------------
PartyID: 7
No errors detected
---------------------------------------
PartyID: 8
Meal type must be S or D
---------------------------------------
PartyID: 9
Weekend must be Y or N
---------------------------------------
PartyID: 10
No errors detected
---------------------------------------
PartyID: 11
number of adults must be a positive number
---------------------------------------
PartyID: 12
number of children must be a positive number
---------------------------------------
PartyID: 13
Deposit must be a positive number
<-------------Output------------->
Party ID: 1
Number of adults: 10
Number of children: 0
Cost for meals: $217.50
Surcharge: $2.74
Tax and tip: $39.15
Total cost of party: $259.39
Deposit: $100.00
total balence due: $159.39
------------------------------------
Party ID: 2
Number of adults: 27
Number of children: 3
Cost for meals: $743.04
Surcharge: $9.36
Tax and tip: $133.75
Total cost of party: $886.15
Deposit: $57.50
total balence due: $828.65
------------------------------------
Party ID: 3
Number of adults: 125
Number of children: 17
Cost for meals: $3488.16
Surcharge: $0.00
Tax and tip: $627.87
Total cost of party: $4116.03
Deposit: $0.00
total balence due: $4116.03
------------------------------------
Party ID: 4
Number of adults: 4
Number of children: 0
Cost for meals: $87.00
Surcharge: $0.00
Tax and tip: $15.66
Total cost of party: $102.66
Deposit: $25.00
total balence due: $77.66
------------------------------------
Party ID: 5
Number of adults: 0
Number of children: 25
Cost for meals: $326.25
Surcharge: $4.11
Tax and tip: $58.72
Total cost of party: $389.09
Deposit: $23.75
total balence due: $365.34
------------------------------------
Party ID: 6
Number of adults: 250
Number of children: 43
Cost for meals: $7115.64
Surcharge: $0.00
Tax and tip: $1280.82
Total cost of party: $8396.46
Deposit: $500.00
total balence due: $7896.46
------------------------------------
Party ID: 7
Number of adults: 0
Number of children: 0
Cost for meals: $0.00
Surcharge: $0.00
Tax and tip: $0.00
Total cost of party: $0.00
Deposit: $0.00
total balence due: $0.00
------------------------------------
Party ID: 8
Number of adults: 10
Number of children: 0
Cost for meals: $0.00
Surcharge: $0.00
Tax and tip: $0.00
Total cost of party: $0.00
Deposit: $10.00
total balence due: $-10.00
------------------------------------
Party ID: 9
Number of adults: 17
Number of children: 3
Cost for meals: $485.04
Surcharge: $0.00
Tax and tip: $87.31
Total cost of party: $572.35
Deposit: $15.00
total balence due: $557.35
------------------------------------
Party ID: 10
Number of adults: 5
Number of children: 0
Cost for meals: $129.00
Surcharge: $1.63
Tax and tip: $23.22
Total cost of party: $153.85
Deposit: $275.00
total balence due: $-121.15
------------------------------------
Party ID: 11
Number of adults: -3
Number of children: 10
Cost for meals: $77.40
Surcharge: $0.98
Tax and tip: $13.93
Total cost of party: $92.31
Deposit: $20.00
total balence due: $72.31
------------------------------------
Party ID: 12
Number of adults: 14
Number of children: -1
Cost for meals: $291.45
Surcharge: $0.00
Tax and tip: $52.46
Total cost of party: $343.91
Deposit: $30.00
total balence due: $313.91
------------------------------------
Party ID: 13
Number of adults: 20
Number of children: 3
Cost for meals: $562.44
Surcharge: $7.09
Tax and tip: $101.24
Total cost of party: $670.77
Deposit: $-10.00
total balence due: $680.77
------------------------------------
*/
