#include <std::string>
#include "student.h"
#include <iostream>
namespace StudentRoster {

// Constructor
    Student::Student()
    {
        id_ = "";
        first_name_ = "";
        last_name_ = "";
        email_address_ = "";
        age_ = -1;
        num_days_ = {-1, -1, -1};
    }

// mutators
    void Student::SetStudentID(std::string student_id)
    {
        id_ = studentID;
    }

    void Student::SetFirstName(std::string first_name)
    {
        first_name_ = first_name;
    }

    void Student::SetLastName(std::string last_name)
    {
        last_name_ = last_name;
    }

    void Student::SetEmailAddress(std::string email_address)
    {
        this->email_address_= email_address;
    }

    void Student::SetAge(int age)
    {
        age_ = age;
    }

    void Student::SetNumDays(int course1, int course2, int course3)
    {
        num_days_ = {course1, course2, course3};
    }

// accessors
    std::string Student::GetStudentID() const
    {
        return id_;
    }

    std::string Student::GetFirstName() const
    {
        return first_name_;
    }

    std::string Student::GetLastName() const
    {
        return last_name_;
    }

    std::string Student::GetEmailAddress() const
    {
        return email_address_;
    }

    int Student::GetAge() const
    {
        return age_;
    }

    const std::array<int, 3> Student::GetNumDays() const
    {
        return num_days_;
    }
} // namespace StudentRoster