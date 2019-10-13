#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"
using namespace std;

class SoftwareStudent: public Student {
public:
  Degree GetDegreeProgram() const;
  void Print() const;
  SoftwareStudent();
  void SetDegreeProgram(Degree degreeProgram);
private:
  Degree degreeProgram;

};
#endif
