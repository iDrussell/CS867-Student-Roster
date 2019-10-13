#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"
using namespace std;

class SecurityStudent: public Student {
  public:

    Degree GetDegreeProgram() const;
    void Print() const;
    SecurityStudent();
    void SetDegreeProgram(Degree degreeProgram);
  private:
    Degree degreeProgram;

};
#endif
