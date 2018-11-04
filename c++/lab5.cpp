// Spencer Stone
// Section 15245 T/Th
// Lab #5A
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int min;
	int max;
	double average;
	double total;
	double n;
	ifstream infile; 
	ofstream outfile;

	outfile << showpoint << fixed << setprecision(2);

	infile.open("C:\\Users\\Stone\\Desktop\\data.txt");
	if (!infile)
	{
		cout << "Cannot open file, terminating program" << endl;
		exit(1);
	}
	outfile.open("C:\\Users\\Stone\\Desktop\\result.txt");
	while (!infile.eof()) {
		infile >> n;
		min = n;
		max = n;
		total = n;
		outfile << "Input: ";
		for (int i = 1; i <= 6; i++) {
			outfile << (int)n << " ";
			infile >> n;
			// Find min
			if (n < min) {
				min = n;
			}
			// Find max
			else if (n > max) {
				max = n;
			}
			// Find total
			total += n;
		}
		outfile << (int)n;
		// Find average 
		average = (total / 7);
		// Save output to file
		outfile << endl;
		outfile << "min: " << min << endl
			<< "max: " << max << endl
			<< "total: " << (int)total << endl
			<< "average: " << average << endl
			<< "------------------------------------------" << endl;
		
	}
	infile.close();
	outfile.close();
	return 0;
}
/**
Input: 346 130 982 90 656 117 595
min: 90
max: 982
total: 2916
average: 416.57
------------------------------------------
Input: 415 948 126 4 558 571 87
min: 4
max: 948
total: 2709
average: 387.00
------------------------------------------
Input: 42 360 412 721 463 47 119
min: 42
max: 721
total: 2164
average: 309.14
------------------------------------------
Input: 441 190 985 214 509 2 571
min: 2
max: 985
total: 2912
average: 416.00
------------------------------------------
Input: 77 81 681 651 995 93 74
min: 74
max: 995
total: 2652
average: 378.86
------------------------------------------
Input: 310 9 995 561 92 14 288
min: 9
max: 995
total: 2269
average: 324.14
------------------------------------------
Input: 466 664 892 8 766 34 639
min: 8
max: 892
total: 3469
average: 495.57
------------------------------------------
Input: 151 64 98 813 67 834 369
min: 64
max: 834
total: 2396
average: 342.29
------------------------------------------
**/
