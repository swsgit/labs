// Spencer Stone
// Section 15245 T/Th
// Lab #7B
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void bubbleSort (int *a, int n);
void higherThanAvg(int a[], int n);
int highestValue(int a[], int n);
int averageValue(int a[], int n);
int lowestValue(int a[]);

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

    int evenArray[evenCount];
    int oddArray[oddCount];

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

    bubbleSort(evenArray, evenCount);
    bubbleSort(oddArray, oddCount);

    cout << "-----------Even array stats-----------" << endl
         << "Average: " << averageValue(evenArray, evenCount) << endl
         << "Highest: " << highestValue(evenArray, evenCount) << endl
         << "Lowest: " << lowestValue(evenArray) << endl
         << "Above average: "; higherThanAvg(evenArray, evenCount);

    cout << "-----------Odd array stats-----------" << endl
         << "Average: " << averageValue(oddArray, oddCount) << endl
         << "Highest: " << highestValue(oddArray, oddCount) << endl
         << "Lowest: " << lowestValue(oddArray) << endl
         << "Above average: "; higherThanAvg(oddArray, oddCount);
    
    return 0;
}

void bubbleSort (int *a, int n) {
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
}

int highestValue(int a[], int n) { return a[n-1]; }

int lowestValue(int a[]) { return a[0]; }

int averageValue(int a[], int n) {
    int sum;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum / n;
}

void higherThanAvg(int a[], int n) {
    int avg = averageValue(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] > avg) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
