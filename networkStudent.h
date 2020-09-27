#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"

namespace StudentRoster {
    class NetworkStudent : public Student {
    public:
        Degree GetDegreeProgram() const;
        void Print() const;
        NetworkStudent();
        void SetDegreeProgram(Degree degree_program);
    private:
        Degree degree_program_;
    };
}
#endif
