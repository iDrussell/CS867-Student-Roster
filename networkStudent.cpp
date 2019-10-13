#include "networkStudent.h"
#include <iostream>
using namespace std;

//constructor
NetworkStudent::NetworkStudent(): Student() {

}

// Returns Degree
Degree NetworkStudent::GetDegreeProgram() const {
  return this->degreeProgram;
}
//Prints all student data
void NetworkStudent::Print() const {
  cout << Student::GetStudentID() << "\t";
  cout << "First Name: " << Student::GetFirstName() <<" \t";
  cout << "Last Name: " << Student::GetLastName() << " \t";
  cout << "Age: " << Student::GetAge() << " \t";
  const int* days;
  days = Student::GetNumDays();
  cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";
  cout << "Degree Program: Network" << endl;
}

// Sets student's degree program
void NetworkStudent::SetDegreeProgram(Degree degreeProgram) {
  this->degreeProgram = degreeProgram;
}
