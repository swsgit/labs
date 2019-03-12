#include <iostream>
#include <string>

class PierceCollege {
private:
	std::string courseName, instructorName;
	int courseNumber;
	char finalGrade;
public:
	PierceCollege(std::string courseName, std::string instructorName, int courseNumber) {
		this->courseName = courseName;
		this->instructorName = instructorName;
		this->courseNumber = courseNumber;
	}
	char calculateGrade() { return finalGrade; }
	void addfinalGrade(char finalGrade) { this->finalGrade = finalGrade; }
	int getCourseNum() { return courseNumber; }
	std::string getCourseName() { return courseName; }
};

int main() {
	std::string courseName = "CS101";
	std::string instructorName = "Proffesor Oak";
	int courseNumber = 90001;
	PierceCollege pc(courseName, instructorName, courseNumber);
	pc.addfinalGrade('A');

	std::cout <<
		"Grade: " << pc.calculateGrade() << "\n" <<
		"Course Number: " << pc.getCourseNum() << "\n" <<
		"Course Name: " << pc.getCourseName() << "\n";

	system("pause");

	return 0;

}
