#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
#include<array>
namespace StudentRoster {
    class Student {
    public:
        // constructor and destructor
        Student();
        Student(std::string student_id, std::string first_name, std::string last_name,
                std::string email_address, int age, int course1, int course2,
                int course3): id_(student_id), first_name_(first_name), last_name_(last_name),
                email_address_(email_address), age_(age), num_days_({course1, course2, course3})
                {}

        // mutators
        void SetStudentID(std::string studentID);
        void SetFirstName(std::string firstName);
        void SetLastName(std::string lastName);
        void SetEmailAddress(std::string emailAddress);
        void SetAge(int age);
        void SetNumDays(int course1, int course2, int course3);
        virtual void SetDegreeProgram(Degree degreeProgram) = 0;

        // accessors
        std::string GetStudentID() const;
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetEmailAddress() const;
        int GetAge() const;
        const std::array<int, 3> GetNumDays() const;
        virtual Degree GetDegreeProgram() const = 0;

        // print
        virtual void Print() const = 0;

    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string email_address_;
        int age_;
        std::array<int, 3> num_days_;
    };
} // namespace StudentRoster


#endif
