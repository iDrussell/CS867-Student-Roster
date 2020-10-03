#include <iostream>
#include <string>
#include "roster.h"
#include <stdexcept>
#include <sstream>
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "student.h"

//Destructor
Roster::~Roster() {
  int i;

  std::cout << "Deleting Roster\n";
  for(i=currentCount; i > 0; --i) {
      delete classRosterArray[i - 1];
      currentCount = currentCount - 1;
  }
}

// Returns current count;
int Roster::GetCount() const {
  return this->currentCount;
}

// Adds student to roster array
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 Degree degreeProgram) {

  if (this->currentCount == 5){
    throw runtime_error("Class roster is full");
  }

  // check degree program to create student object and add
  if (degreeProgram == SECURITY) {

    SecurityStudent* ptr;
    ptr = new SecurityStudent;

    (*ptr).SetStudentID(studentID);
    (*ptr).SetFirstName(firstName);
    (*ptr).SetLastName(lastName);
    (*ptr).SetEmailAddress(emailAddress);
    (*ptr).SetAge(age);
    (*ptr).SetNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
    (*ptr).SetDegreeProgram(degreeProgram);


    this->classRosterArray[currentCount] = ptr;
    this->currentCount = this->currentCount + 1;
  }
  else if (degreeProgram == NETWORK) {
    NetworkStudent* ptr;
    ptr = new NetworkStudent;

    (*ptr).SetStudentID(studentID);
    (*ptr).SetFirstName(firstName);
    (*ptr).SetLastName(lastName);
    (*ptr).SetEmailAddress(emailAddress);
    (*ptr).SetAge(age);
    (*ptr).SetNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
    (*ptr).SetDegreeProgram(degreeProgram);


    this-> classRosterArray[currentCount] = ptr;
    this->currentCount = this->currentCount + 1;
  }
  else if (degreeProgram == SOFTWARE) {

    SoftwareStudent* ptr;
    ptr = new SoftwareStudent;

    (*ptr).SetStudentID(studentID);
    (*ptr).SetFirstName(firstName);
    (*ptr).SetLastName(lastName);
    (*ptr).SetEmailAddress(emailAddress);
    (*ptr).SetAge(age);
    (*ptr).SetNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
    (*ptr).SetDegreeProgram(degreeProgram);


    this->classRosterArray[currentCount] = ptr;
    this->currentCount = this->currentCount + 1;

  }
  else {
    throw runtime_error("Could not add student. Invalid degree program");
  }
  return;

}

// Remove student by student ID
void Roster::Remove(string studentID) {
  int i;
  int j;
  for(i=0; i < currentCount; ++i) {
    if(classRosterArray[i]->GetStudentID() == studentID) {
      delete classRosterArray[i];
      for(j=i; j < currentCount; ++j) {
        classRosterArray[j] = classRosterArray[j+1];
      }
    }
    else {
      throw runtime_error("Student " + studentID + " is not found.");
    }
    currentCount = currentCount - 1;
  }
  return;
}

// Print the average days by student
void Roster::PrintAverageDaysInCourse(string studentID) {
  const int* days;
  int i;
  for (i=0; i<currentCount; ++i){
    if(classRosterArray[i]->GetStudentID() == studentID) {
      days = classRosterArray[i]->GetNumDays();
      std::cout << "Average days in course for " << studentID << " is " << (*(days)+ *(days+1) + *(days+2)) / 3.0 << endl;
    }
  }
  return;
}

// Print invalid emails
void Roster::PrintInvalidEmails() {
  int i;
  string email;
  bool atSign = false;
  bool period = false;
  for (i=0; i < currentCount; ++i) {
    email = classRosterArray[i]->GetEmailAddress();
    if((email.find(' ')!= string::npos) || (email.find('@') == string::npos) || (email.find('.') == string::npos)) {
      std::cout << email << endl;
    }
  }
  return;
}

// Print Each student in a given degree program
void Roster::PrintByDegreeProgram(Degree degreeProgram) {
  int i;
  for (i=0; i < currentCount; ++i) {
    if(classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
      classRosterArray[i]->Print();
    }
  }
  return;
}


// Print information for all students
void Roster::PrintAll() const {
  int i;
  for (i=0; i < currentCount; ++i) {
    classRosterArray[i]->Print();
  }
}

int main()  {

  string iD, first, last, email, temp;
  int i, age, course1, course2, course3;
  Degree degree;
  Roster* classRoster;
  classRoster = new Roster;

  std::cout << "Course C867:  Scripting and Programming - Applications" << endl;
  std::cout << "Written in: C++" << endl;
  std::cout << "Student ID: 000928628" << endl;
  std::cout << "Name: Dalton Russell" << endl;

  // Student data table
  const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Dalton,Russell,druss52@wgu.edu,25,10,15,20,SOFTWARE"};

  try {

    // This is a VERY ugly way to parse the student data.
    // Could not find a good way to convert strings of ints
    // to ints while keeping code down.
    for (i=0; i < 5; ++i) {

      istringstream ss(*(studentData+i));
      getline(ss, iD, ',');
      getline(ss, first, ',');
      getline(ss, last, ',');
      getline(ss, email, ',');
      getline(ss, temp, ',');
      age = stoi(temp);
      getline(ss, temp, ',');
      course1 = stoi(temp);
      getline(ss, temp, ',');
      course2 = stoi(temp);
      getline(ss, temp, ',');
      course3 = stoi(temp);
      getline(ss, temp, ',');

      if (temp == "SECURITY") {
        degree = SECURITY;
      }
      else if (temp == "NETWORK") {
        degree = NETWORK;

      }
      else if (temp == "SOFTWARE") {
        degree = SOFTWARE;
      }
      else {
        throw runtime_error("Invalid Degree");
      }
      //Add each student;
      classRoster->Add(iD, first, last, email, age, course1, course2, course3, degree);

    }

    // Everything from end of Task document
    classRoster->PrintAll();
    classRoster->PrintInvalidEmails();

    for (i=0; i < (classRoster->GetCount()); ++i) {
      classRoster->PrintAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());

      // In the directions for the assessment it says to loop through the array and do these
      // However, PrintByDegreeProgram would return the same thing each time
      // and Remove would stop the loop after executing the second time (throws exception),
      // so I execute them outside the for loop. But they are here as
      // required in the directions.

      // classRoster->PrintByDegreeProgram(SOFTWARE);
      // classRoster->Remove("A3");
      // classRoster->Remove("A3");
    }
    classRoster->PrintByDegreeProgram(SOFTWARE);
    classRoster->Remove("A3");
    classRoster->Remove("A3");
  }
  catch (runtime_error &excpt) {
    std::cout << excpt.what() << endl;
  }

  delete classRoster;





  return 0;



}
