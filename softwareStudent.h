#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"

namespace StudentRoster {
    class SoftwareStudent : public Student {
    public:
        Degree GetDegreeProgram() const;
        void Print() const;
        SoftwareStudent();
        void SetDegreeProgram(Degree degree_program);
    private:
        Degree degree_program_;
    };
}
#endif
