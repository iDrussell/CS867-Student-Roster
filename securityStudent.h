#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"

namespace StudentRoster {
    class SecurityStudent : public Student {
    public:
        const Degree GetDegreeProgram() const;
        void Print() const;
        SecurityStudent();
        SecurityStudent(std::string id, std::string first_name, std::string last_name,
                        std::string email_address, int age, int days_in_course1,
                        int days_in_course2,
                        int days_in_course3): Student(id, first_name, last_name, email_address,
                                                       age, days_in_course1, days_in_course2,
                                                       days_in_course3) {}
    private:
        const Degree degree_program_{SECURITY};
    };
} // namespace StudentRoster
#endif
