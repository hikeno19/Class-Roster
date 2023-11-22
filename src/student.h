#include <string>
#include "degree.h"
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
    public:
        // default constructor
        Student(
        );

        // constructor
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);

        // deconstructor destructor

        ~Student();

        // getter
        string GetStudentID();
        string GetFirstName();
        string GetLastName();
        string GetEmailAddress();
        int GetAge();
        int GetDaysInCourse(size_t index);
        DegreeProgram GetDegreeProgram();

        // setters
        void SetStudentID(string studentID);
        void SetFirstName(string name);
        void SetLastName(string name);
        void SetEmailAddress(string email);
        void SetAge(int age);
        void SetDaysInCourse(int days[]);
        void SetDegreeProgram(DegreeProgram degreeProgram);

        // print
        void print();

    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        string::size_type i;
        int* daysInCourse;
        DegreeProgram degreeProgram;
};
#endif