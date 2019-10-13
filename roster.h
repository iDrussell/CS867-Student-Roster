#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

class Roster {
  public:

    void Add(string studentID, string firstName, string lastName, string emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void Remove(string studentID);
    void PrintAll() const;
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(Degree degreeProgram);
    int GetCount() const;
    ~Roster();

    // Made these two public because I had to access the
    // because I had to access the array from
    // the main function to loop in PrintAverageDaysInCourse
    int currentCount = 0;
    Student* classRosterArray[5];
};



#endif
