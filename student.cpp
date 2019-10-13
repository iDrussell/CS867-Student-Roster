#include <string>
#include "student.h"
#include <iostream>
using namespace std;

// Constructor
Student::Student() {
  studentID = "";
  firstName = "";
  lastName = "";
  emailAddress = "";
  age = -1;
  numDays[0] = -1;
  numDays[1] = -1;
  numDays[2] = -1;
}



// mutators
void Student::SetStudentID(string studentID) {
  this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
  this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
  this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
  this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
  this->age = age;
}

void Student::SetNumDays(int course1, int course2, int course3) {
  this->numDays[0] = course1;
  this->numDays[1] = course2;
  this->numDays[2] = course3;
}


// accessors
string Student::GetStudentID() const {
  return studentID;
}

string Student::GetFirstName() const {
  return firstName;
}

string Student::GetLastName() const {
  return lastName;
}

string Student::GetEmailAddress() const {
  return emailAddress;
}

int Student::GetAge() const {
  return age;
}

const int* Student::GetNumDays() const{
  return numDays;
}
