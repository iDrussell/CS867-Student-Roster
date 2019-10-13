#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using namespace std;


class Student {
  public:
    // constructor and destructor
    Student();
    Student(string studentID, string firstName, string lastName,
            string emailAddress, int age, int course1, int course2,
            int course3);

    // mutators
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetNumDays(int course1, int course2, int course3);
    virtual void SetDegreeProgram(Degree degreeProgram) = 0;




    // accessors
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    const int* GetNumDays() const;
    virtual Degree GetDegreeProgram() const = 0;

    // print
    virtual void Print() const = 0;

  private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
};

#endif
