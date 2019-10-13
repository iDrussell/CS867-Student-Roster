#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"

class NetworkStudent: public Student {
public:
  Degree GetDegreeProgram() const;
  void Print() const;
  NetworkStudent();
  void SetDegreeProgram(Degree degreeProgram);
private:
  Degree degreeProgram;
};
#endif
