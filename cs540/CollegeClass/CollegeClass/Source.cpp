#include <iostream>
#include <string>

class PierceCollege {
private:
  std::string courseName, instructorName, userName;
  int courseNumber;
  char finalGrade;

public:
  PierceCollege(std::string courseName, std::string instructorName,
                int courseNumber, std::string userName) {
    this->courseName = courseName;
    this->instructorName = instructorName;
    this->courseNumber = courseNumber;
    this->userName = userName;
  }
  char calculateGrade() { return finalGrade; }
  void addfinalGrade(char finalGrade) { this->finalGrade = finalGrade; }
  int getCourseNum() { return courseNumber; }
  std::string getCourseName() { return courseName; }
  std::string getUserName() { return userName; }
  std::string getInstructor() { return instructorName; }

  /* comparing chars requires illogical math */
  friend int operator>(PierceCollege lhs, PierceCollege &rhs) {
    return lhs.finalGrade < rhs.finalGrade;
  }
  friend int operator<(PierceCollege lhs, PierceCollege &rhs) {
    return lhs.finalGrade > rhs.finalGrade;
  }
  friend std::ostream &operator<<(std::ostream &out, PierceCollege pc) {
    return out << "Name: " << pc.getUserName() << "\n"
               << "Grade: " << pc.calculateGrade() << "\n"
               << "Course Number: " << pc.getCourseNum() << "\n"
               << "Course Name: " << pc.getCourseName() << "\n"
               << "Instructor: " << pc.getInstructor() << "\n";
  }
  friend void compare(PierceCollege lhs, PierceCollege rhs) {
    if (lhs > rhs) {
      std::cout << lhs.getUserName() << " has a higher grade\n";
    } else if (lhs < rhs) {
      std::cout << rhs.getUserName() << " has a higher grade\n";
    }
  }
};

int main() {
  PierceCollege john("PKMN101", "Proffesor Oak", 90001, "john");
  PierceCollege mac("FRMG101", "Ol' Mc Donald", 90002, "mac");
  john.addfinalGrade('A');
  mac.addfinalGrade('B');

  std::cout << john;
  std::cout << mac;

  compare(john, mac);

  system("pause");

  return 0;
}
