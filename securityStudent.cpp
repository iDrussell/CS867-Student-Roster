#include "securityStudent.h"
#include <iostream>
using namespace std;


//constructor
SecurityStudent::SecurityStudent() : Student() {}

// Returns  degree program
Degree SecurityStudent::GetDegreeProgram() const {
  return this->degreeProgram;
}

// Printst student information
void SecurityStudent::Print() const {
  cout << Student::GetStudentID() << "\t";
  cout << "First Name: " << Student::GetFirstName() <<" \t";
  cout << "Last Name: " << Student::GetLastName() << " \t";
  cout << "Age: " << Student::GetAge() << " \t";
  const int* days;
  days = Student::GetNumDays();
  cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";
  cout << "Degree Program: Security" << endl;
}

// Sets student's degree program
void SecurityStudent::SetDegreeProgram(Degree degreeProgram) {
  this->degreeProgram = degreeProgram;
}
