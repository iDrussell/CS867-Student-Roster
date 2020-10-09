#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>

namespace StudentRoster {
////Destructor
//Roster::~Roster() {
//    int i;
//
//    std::cout << "Deleting Roster\n";
//    for (auto student: class_roster_) {
//        delete student;
//    }
//}

// Adds student to roster array
void Roster::Add(const std::string& student_id, const std::string& first_name, const std::string& last_name, const std::string& email_address,
                 int age, int days_in_course1, int days_in_course2, int days_in_course3,
                 Degree degree_program)
{

    // check degree program to create student object and add
    switch (degree_program) {
        case SECURITY: {
            std::unique_ptr<Student> student = std::make_unique<SecurityStudent>(student_id, first_name, last_name,
                                      email_address, age, days_in_course1,
                                      days_in_course2, days_in_course3);
            class_roster_.push_back(std::move(student));
            break;
        }
        case NETWORK: {

            std::unique_ptr<Student> student = std::make_unique<NetworkStudent>(student_id, first_name, last_name,
                                     email_address, age, days_in_course1,
                                     days_in_course2, days_in_course3);
            class_roster_.push_back(std::move(student));
            break;
        }
        case SOFTWARE: {

            std::unique_ptr<Student> student = std::make_unique<SoftwareStudent>(student_id, first_name, last_name,
                                      email_address, age, days_in_course1,
                                      days_in_course2, days_in_course3);
            class_roster_.push_back(std::move(student));
            break;
        }
        default:
            throw std::runtime_error("Invalid degree program\n");
    };
}

// Remove student by student ID
void Roster::Remove(const std::string& student_id) {
    for (auto it = class_roster_.begin(); it != class_roster_.end(); ++it) {
        if ((*it)->GetStudentID() == student_id) {
            class_roster_.erase(it);
            return;
        }
    }
    throw std::runtime_error("Error no student");
}

// Print the average days by student
void Roster::PrintAverageDaysInCourse(const std::string& student_id) const {
    for (auto &student: class_roster_) {
        if (student->GetStudentID() == student_id) {
            float total_days = std::accumulate(student->GetNumDays().begin(), student->GetNumDays().end(), 0);
            std::cout << (total_days/student->GetNumDays().size()) << "\n";
        }
    }
}
void Roster::PrintAverageDaysInCourse() const {
    for (auto &student: class_roster_) {
        PrintAverageDaysInCourse(student->GetStudentID());
    }
}
// Print invalid emails
void Roster::PrintInvalidEmails() const {
    std::string email;
    for (auto &student: class_roster_) {
        email = student->GetEmailAddress();
        if ((email.find(' ') != std::string::npos) || (email.find('@') == std::string::npos) || (email.find('.') == std::string::npos))
            std::cout << email << "\n";
    }
}

// Print Each student in a given degree program
void Roster::PrintByDegreeProgram(Degree degree_program) const {
    for (auto &student: class_roster_) {
        if (student->GetDegreeProgram() == degree_program)
            student->Print();
    }
}

// Print information for days_in_course1all students
void Roster::PrintAll() const {
    for (auto &student: class_roster_) {
        student->Print();
    }
}

} // namespace StudentRoster


