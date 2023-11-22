#include "roster.h"
#include "student.h"
#include "degree.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;


int main() {
    // array of csv string data
    const std::string studentData[] = { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Hayato,Ikeno,hikeno3@wgu.com,24, 19, 30, 40,SOFTWARE" };

    // print
    cout << "\nCourse: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011376440" << endl;
    cout << "Name: Hayato Ikeno\n" << endl;

    // initialized a new class roster instance
    Roster* classRoster = new Roster();

    // iterating studentdata array and parsing student info to be inputted into class roster array.
    size_t i;
    for (i = 0; i < Roster::numStudents; i++) {
        classRoster->parse(studentData[i]);
    }

    // print all student info 
    classRoster->printAll();

    // print all invalid emails
    classRoster->printInvalidEmails();

    //loop through classRosterArray and for each element:
    Student** ptr = classRoster->GetClassRosterArray();
    for (i = 0; i < Roster::numStudents; i++) {
        Student* stu = ptr[i];
        classRoster->printAverageDaysInCourse(stu->GetStudentID());
    }

    // prints all student by SOFTWARE
    classRoster->printByDegreeProgram(SOFTWARE);

    // Removes student with id A3 from class roster array
    classRoster->remove("A3");

    // prints info of all students
    classRoster->printAll();

    // will print error message as student with student id is not found in array. 
    classRoster->remove("A3");

    // deconstuctors release memory that was allocated dynamically by roster
    delete classRoster;

    return 0;
};