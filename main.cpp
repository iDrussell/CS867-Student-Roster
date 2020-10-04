//
// Created by dalton on 10/4/20.
//
#include "roster.h"
#include <iostream>
#include <sstream>
int main() {

    std::string student_id, first_name, last_name, email_address, temp;
    int age, course1, course2, course3;
    Degree degree;
    StudentRoster::Roster roster;
    std::cout << "Course C867:  Scripting and Programming - Applications\n";
    std::cout << "Written in: C++\n";
    std::cout << "Student ID: 000928628\n";
    std::cout << "Name: Dalton Russell\n";

    // Student data table
    const std::vector<std::string> student_data{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Dalton,Russell,druss52@wgu.edu,25,10,15,20,SOFTWARE"};

    try {

        // This is a VERY ugly way to parse the student data.
        // Could not find a good way to convert strings of ints
        // to ints while keeping code down.
        for (const auto& data_string: student_data) {

            std::stringstream ss(data_string);
            getline(ss, student_id, ',');
            getline(ss, first_name, ',');
            getline(ss, last_name, ',');
            getline(ss, email_address, ',');
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
                throw std::runtime_error("Invalid Degree");
            }
            //Add each student;
            roster.Add(student_id, first_name, last_name, email_address, age,
                       course1, course2, course3, degree);
        }

        // Everything from end of Task document
        roster.PrintAll();
        roster.PrintInvalidEmails();
        roster.PrintAverageDaysInCourse();
        roster.PrintByDegreeProgram(SOFTWARE);
        roster.Remove("A3");
        roster.Remove("A3");
    } catch (std::runtime_error &excpt) {
        std::cout << excpt.what() << "\n";
    }
    return 0;
}