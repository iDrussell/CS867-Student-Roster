#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>

namespace StudentRoster {
//Destructor
Roster::~Roster() {
    int i;

    std::cout << "Deleting Roster\n";
    for (auto student: class_roster_) {
        delete student;
    }
}

// Adds student to roster array
void Roster::Add(const std::string& student_id, const std::string& first_name, const std::string& last_name, const std::string& email_address,
                 int age, int days_in_course1, int days_in_course2, int days_in_course3,
                 Degree degree_program)
{

    // check degree program to create student object and add
    // TODO: Need to find something better than ptrs
    switch (degree_program) {
        case SECURITY: {
            SecurityStudent* ptr;
            ptr = new SecurityStudent(student_id, first_name, last_name,
                                      email_address, age, days_in_course1,
                                      days_in_course2, days_in_course3);
            class_roster_.push_back(ptr);
        }
        case NETWORK: {
            NetworkStudent* ptr;
            ptr = new NetworkStudent(student_id, first_name, last_name,
                                     email_address, age, days_in_course1,
                                     days_in_course2, days_in_course3);
            class_roster_.push_back(ptr);
        }
        case SOFTWARE: {
            SoftwareStudent* ptr;
            ptr = new SoftwareStudent(student_id, first_name, last_name,
                                      email_address, age, days_in_course1,
                                      days_in_course2, days_in_course3);
            class_roster_.push_back(ptr);
        }
        default:
            throw std::runtime_error("Invalid degree program\n");
    };
}

// Remove student by student ID
void Roster::Remove(const std::string& student_id) {
    for (auto student: class_roster_) {
        if (student->GetStudentID() == student_id)
            delete student;
    }
}

// Print the average days by student
void Roster::PrintAverageDaysInCourse(const std::string& student_id) const {
    for (auto student: class_roster_) {
        if (student->GetStudentID() == student_id) {
            float total_days = std::accumulate(student->GetNumDays().begin(), student->GetNumDays().end(), 0);
            std::cout << (total_days/student->GetNumDays().size()) << "\n";
        }
    }
}

// Print invalid emails
void Roster::PrintInvalidEmails() const {
    std::string email;
    for (auto student: class_roster_) {
        email = student->GetEmailAddress();
        if ((email.find(' ') != std::string::npos) || (email.find('@') == std::string::npos) || (email.find('.') == std::string::npos))
            std::cout << email << "\n";
    }
}

// Print Each student in a given degree program
void Roster::PrintByDegreeProgram(Degree degree_program) const {
    for (auto student: class_roster_) {
        if (student->GetDegreeProgram() == degree_program)
            student->Print();
    }
}

// Print information for days_in_course1all students
void Roster::PrintAll() const {
    for (auto student: class_roster_) {
        student->Print();
    }
}

} // namespace StudentRoster

int main() {

    string iD, first, last, email, temp;
    int i, age, course1, course2, course3;
    Degree degree;
    Roster *classRoster;
    classRoster = new Roster;

    std::cout << "Course C867:  Scripting and Programming - Applications" << endl;
    std::cout << "Written in: C++" << endl;
    std::cout << "Student ID: 000928628" << endl;
    std::cout << "Name: Dalton Russell" << endl;

    // Student data table
    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Dalton,Russell,druss52@wgu.edu,25,10,15,20,SOFTWARE"};

    try {

        // This is a VERY ugly way to parse the student data.
        // Could not find a good way to convert strings of ints
        // to ints while keeping code down.
        for (i = 0; i < 5; ++i) {

            istringstream ss(*(studentData + i));
            getline(ss, iD, ',');
            getline(ss, first, ',');
            getline(ss, last, ',');
            getline(ss, email, ',');
            getline(ss, temp, ',');
            age = stoi(temp);
            getline(ss, temp, ',');
            course1 = stoi(temp);
            getline(ss, temp, ',');
            course2 = stoi(temp);
            getline(ss, temp, ',');
            course3 = stoi(temp);
            getline(ss, temp, ',');

            if (temp == "SECURITY") {
                degree = SECURITY;
            } else if (temp == "NETWORK") {
                degree = NETWORK;

            } else if (temp == "SOFTWARE") {
                degree = SOFTWARE;
            } else {
                throw runtime_error("Invalid Degree");
            }
            //Add each student;
            classRoster->Add(iD, first, last, email, age, course1, course2, course3, degree);
        }

        // Everything from end of Task document
        classRoster->PrintAll();
        classRoster->PrintInvalidEmails();

        for (i = 0; i < (classRoster->GetCount()); ++i) {
            classRoster->PrintAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());

            // In the directions for the assessment it says to loop through the array and do these
            // However, PrintByDegreeProgram would return the same thing each time
            // and Remove would stop the loop after executing the second time (throws exception),
            // so I execute them outside the for loop. But they are here as
            // required in the directions.

            // classRoster->PrintByDegreeProgram(SOFTWARE);
            // classRoster->Remove("A3");
            // classRoster->Remove("A3");
        }
        classRoster->PrintByDegreeProgram(SOFTWARE);
        classRoster->Remove("A3");
        classRoster->Remove("A3");
    } catch (runtime_error &excpt) {
        std::cout << excpt.what() << endl;
    }

    delete classRoster;


    return 0;
}
