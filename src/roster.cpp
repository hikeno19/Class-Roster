#include "roster.h"
#include "degree.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

Roster::Roster(){
    classRosterArray = new Student*[numStudents];
    currentIndex = 0;
    i = 0;
    numRemoved = 0;
}
Roster::~Roster() {
    // Cleanup: Delete each dynamically allocated Student object
    for (i = 0; i < currentIndex - numRemoved; ++i) {
        delete classRosterArray[i];
    }
}
Student** Roster::GetClassRosterArray(){
    return this->classRosterArray;
}
// parses csv using stringstream and initialized into variables for arguments in add function
void Roster::parse(string studentData){
    stringstream is;
    is.clear();
    is.str(studentData);
    string id;
    getline(is, id, ',');
    string first;
    getline(is, first, ',');
    string last;
    getline(is, last, ',');
    string email;
    getline(is, email, ',');
    string age;
    getline(is, age, ',');
    string course1;
    getline(is, course1, ',');
    string course2;
    getline(is, course2, ',');
    string course3;
    getline(is, course3, ',');
    string program;
    getline(is, program, ',');
    add(id, first, last, email, stoi(age), stoi(course1), stoi(course2), stoi(course3), Degree::GetProgramFromName(program));
}
// initializes new student object and puts into current empty index of class roster array; incrementing index. 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    int days[3] = {daysInCourse1,daysInCourse2, daysInCourse3};
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
    classRosterArray[currentIndex] = student;
    currentIndex++;
}
// remove by student id 
void Roster::remove(string studentID){ 
    cout << "Attempting to remove student with ID: " << studentID << endl;
    bool removed = false;
    for (i = 0; i < numStudents-numRemoved; i++) {
        Student* student = classRosterArray[i];
        if(student->GetStudentID() == studentID){
            removed = true;
            delete student;
            while(i < numStudents-1){
                classRosterArray[i] = classRosterArray[i+1];
                i++;
            }
        }
    }
    numRemoved++;
    (removed) ? cout << "Removed student with ID: " << studentID << endl : cout << "Student with ID: " << studentID << " not found." << endl;
    cout << endl;
}
// prints all students and skips removed elements. 
void Roster::printAll(){
    cout << "Students: " << endl;
    for(i = 0; i < numStudents-numRemoved; i++){
        Student* student = classRosterArray[i];
        student->print();
    }
    cout << endl;
}
// prints invalid emails
void Roster::printInvalidEmails(){
    cout << "Invalid Emails: " << endl;
    for(i = 0; i < numStudents - numRemoved; i++){
            Student* student = classRosterArray[i];
            if (!isValidEmail(student->GetEmailAddress())) {
                cout << student->GetEmailAddress() << endl;
            }
    }
    cout << endl;
}
// checks if email is valid
bool Roster::isValidEmail(string email){
    // regex pattern
    const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

   // try to match the string with the regular expression
    return std::regex_match(email, pattern);
}
// prints student info by degree program. 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    cout << "Students in Degree Program: " << Degree::GetNameFromProgram(degreeProgram) << endl;
    for(i = 0; i < numStudents-numRemoved; i++){
            Student* student = classRosterArray[i];
            if (student->GetDegreeProgram() == degreeProgram) {
                student->print();
            }
    }
    cout << endl;
}
// print average days in courses by students id
void Roster::printAverageDaysInCourse(string studentID){
    for(i = 0; i < numStudents-numRemoved; i++){
            Student* student = classRosterArray[i];
            if (student->GetStudentID() == studentID) {
                size_t index = 0;
                double total = 0.00;
                while (index < 3) {
                    total += student->GetDaysInCourse(index);
                    index = index + 1;
                }
                cout << "Student ID: " << studentID << endl;
                cout << "Average Days in Courses: " << static_cast<int>((total / 3)) << endl;
                break;
            }
    }
    cout << endl;
}

// checker if char is within alphabet
bool Roster::isChar(char c) 
{ 
    return ((c >= 'a' && c <= 'z') 
            || (c >= 'A' && c <= 'Z')); 
} 
