#include "networkStudent.h"
#include <iostream>

namespace StudentRoster {

//constructor
    NetworkStudent::NetworkStudent()
            :Student()
    {

    }

// Returns Degree
    const Degree NetworkStudent::GetDegreeProgram() const
    {
        return degree_program_;
    }

//Prints all student data
    void NetworkStudent::Print() const
    {
        std::cout << Student::GetStudentID() << "\t";
        std::cout << "First Name: " << Student::GetFirstName() << " \t";
        std::cout << "Last Name: " << Student::GetLastName() << " \t";
        std::cout << "Age: " << Student::GetAge() << " \t";
        const std::array<int, 3> days = Student::GetNumDays();
        std::cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";
        std::cout << "Degree Program: Network\n";
    }
}