#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"

namespace StudentRoster {
    class SecurityStudent : public Student {
    public:
        Degree GetDegreeProgram() const;
        void Print() const;
        SecurityStudent();
        void SetDegreeProgram(Degree degree_program);
    private:
        Degree degree_program_;
    };
} // namespace StudentRoster
#endif
