// Spencer Stone
// Section 15245 T/Th
// Lab #7B
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void higherThanAvg(int *a, int n);
void arrayContents(int *a, int n);
void highestLowestAverage(int *a, int n);

int main() {
    ifstream infile;
    int evenCount = 0;
    int oddCount = 0;
    int i = 0;
    int x = 0;
    int num;

    infile.open("data.txt");
    if (!infile) {
        cout << "Cannot read input file" << endl;
    }

    while (!infile.eof()) {
        infile >> num;
        if (num % 2 == 0) { evenCount++; }
        else if (num % 2 != 0) { oddCount++; }
    }
    infile.close();

    int *evenArray = new int[evenCount];
    int *oddArray = new int[oddCount];

    infile.open("data.txt");
    if (!infile) {
        cout << "Cannot read input file" << endl;
    }

    while (!infile.eof()) {
        infile >> num;
        if (num % 2 == 0) {
            evenArray[i] = num; 
            i++;
        }
        else if (num % 2 != 0) { 
            oddArray[x] = num;
            x++;
        }
    }
    infile.close();

    cout << "----------------------Even array stats----------------------" << endl;
    arrayContents(evenArray, evenCount);
    highestLowestAverage(evenArray, evenCount);
    higherThanAvg(evenArray, evenCount);

    cout << "----------------------Odd array stats----------------------" << endl;
    arrayContents(oddArray, oddCount);
    highestLowestAverage(oddArray, oddCount);
    higherThanAvg(oddArray, oddCount);

    delete[] evenArray;
    delete[] oddArray;
    
    return 0;
}

void higherThanAvg(int *a, int n) {
    int avg;
    int sum = 0;
    cout << "Above average: ";
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    avg = sum / n;

    for (int i = 0; i < n; i++) {
        if (a[i] > avg) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void arrayContents(int *a, int n) {
    cout << "Array contents: [ ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

void highestLowestAverage(int *a, int n) {
    int sum = 0;
    // Bubble sort worst case O(n)
    int i, t, j = n, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < j; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = 1;
            }
        }
        j--;
    }

    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << "Average: " << sum / n << endl
         << "Highest: " << a[n - 1] << endl
         << "Lowest: " << a[0] << endl;
}
/*
----------------------Even array stats----------------------
Array contents: [ 0 4 10 12 14 16 16 26 30 34 46 48 52 56 58 
60 64 64 66 66 78 80 82 88 90 90 92 92 92 102 ]
Average: 54
Highest: 102
Lowest: 0
Above average: 56 58 60 64 64 66 66 78 80 82 88 90 90 92 92 92 102
----------------------Odd array stats----------------------
Array contents: [ -9 5 17 19 21 39 41 47 51 61 63 63 71 79 
79 85 89 95 95 95 ]
Average: 55
Highest: 95
Lowest: -9
Above average: 61 63 63 71 79 79 85 89 95 95 95
----------------------Data File----------------------
46	30	82	90	56	17	95	16	48	26
4	58	0	78	92	60	12	21	63	47
19	41	90	85	14	-9	52	71	79	16
80	51	95	102	34	10	79	95	61	92
89	88	66	64	92	63	66	64	39	5
*/
