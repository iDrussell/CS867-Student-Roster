#include "softwareStudent.h"
#include <iostream>
using namespace std;

// constructor
SoftwareStudent::SoftwareStudent(): Student() {}

// Returns Student's degree program
Degree SoftwareStudent::GetDegreeProgram() const {
  return this->degreeProgram;
}


// Prints student information
void SoftwareStudent::Print() const {
  cout << Student::GetStudentID() << "\t";
  cout << "First Name: " << Student::GetFirstName() <<" \t";
  cout << "Last Name: " << Student::GetLastName() << " \t";
  cout << "Age: " << Student::GetAge() << " \t";
  const int* days;
  days = Student::GetNumDays();
  cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";
  cout << "Degree Program: Software" << endl;
}

// Sets student's degree
void SoftwareStudent::SetDegreeProgram(Degree degreeProgram) {
  this->degreeProgram = degreeProgram;
}
