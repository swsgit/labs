// Spencer Stone
// Lab #5A
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	double min;
	double max;
	double average;
	double total;
	double name;
	ifstream infile; 
	ofstream outfile;

	cout << showpoint << fixed << setprecision(2);

	infile.open("C:\\Users\\student\\Desktop\\data.txt");
	if (!infile)
	{
		cout << "Cannot open file, terminating program" << endl;
		exit(1);
	}
	outfile.open("C:\\Users\\student\\Desktop\\result.txt");
	infile >> name;
	while (infile) {
		min = name;
		max = name;
		total = name;
		outfile << "Input: ";
		for (int i = 1; i <= 7; i++) {
			outfile << name << " ";
			infile >> name;
			// Find min
			if (name < min) {
				min = name;
			}
			// Find max
			else if (name > max) {
				max = name;
			}
			// Find total
			total += name;
		}
		// Find average
		average = (total / 7);
		// Save output to file
		outfile << endl;
		outfile << "min: " << min << endl
			<< "max: " << max << endl
			<< "total: " << total << endl
			<< "average: " << average << endl
			<< "------------------------------------------" << endl;
		
	}
	infile.close();
	outfile.close();
	return 0;
}
