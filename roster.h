#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include <vector>

namespace StudentRoster {

    class Roster {
    public:
        void Add(const std::string& student_id, const std::string& first_name, const std::string& last_name, const std::string& email_address,
                 int age, int days_in_course1, int days_in_course2, int days_in_course3, Degree degree_program);
        void Remove(const std::string& student_id);
        void PrintAll() const;
        void PrintAverageDaysInCourse(const std::string& student_id) const;
        void PrintInvalidEmails() const;
        void PrintByDegreeProgram(Degree degreeProgram) const;
        ~Roster();
    private:
        std::vector<Student *> class_roster_;
    };
}// namespace StudentRoster


#endif
