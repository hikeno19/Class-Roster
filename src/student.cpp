#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

// Default constructor
Student::Student(){
    studentID = "null";
    firstName = "null";
    lastName = "null";
    emailAddress = "null";
    age = -1;
    daysInCourse = new int[3];
    degreeProgram = DegreeProgram::SOFTWARE;
}

//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = new int[3];
    for(i = 0; i < 3; i++){
        this->daysInCourse[i] = days[i];
    }
    this->degreeProgram = degreeProgram;
}

//deconstructor
Student::~Student(){
}

// getters
string Student::GetStudentID(){
    return this->studentID;
}
string Student::GetFirstName(){
    return this->firstName;
}
string Student::GetLastName(){
    return this->lastName;
}
string Student::GetEmailAddress(){
    return this->emailAddress;
}
int Student::GetAge(){
    return this->age;
}
int Student::GetDaysInCourse(size_t index){
    return this->daysInCourse[index];
}
DegreeProgram Student::GetDegreeProgram(){
    return this->degreeProgram;
}

// setters
void Student::SetStudentID(string studentID){
    this->studentID = studentID;
}
void Student::SetFirstName(string name){
    this->firstName = name;
}
void Student::SetLastName(string name){
    this->lastName = name;
}
void Student::SetEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
}
void Student::SetAge(int age){
    this->age = age;
}
void Student::SetDaysInCourse(int days[]){
    for(i = 0; i < 3; i++){
        this->daysInCourse[i] = days[i];
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
}

// print
void Student::print(){
    cout << studentID << " \tFirst Name: " << firstName << " \t Last Name: " << lastName;
    cout  << "\t Age: " << age << " \t daysInCourse: { ";
    for(i = 0; i < 3; i++){
        cout << this->daysInCourse[i];
        if(i != 2){
            cout << " ";
        }
    }
    cout << " } \t Degree Program: " << Degree::GetNameFromProgram(this->degreeProgram) << endl; 
}


