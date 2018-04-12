// Spencer Stone
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

	infile.open("C:\\Users\\student\\Desktop\\data.txt");
	if (!infile)
	{
		cout << "Cannot open file, terminating program" << endl;
		exit(1);
	}
	outfile.open("C:\\Users\\student\\Desktop\\result.txt");
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
**/
