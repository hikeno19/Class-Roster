#include "student.h"
#include "degree.h"
#ifndef ROSTER_H
#define ROSTER_H
using namespace std;

class Roster{
    public:
        static const int numStudents = 5;
        //array of pointers to students
        Student** classRosterArray;

        //constructor
        Roster();

        // deconstructor
        ~Roster();

        //getter
        Student** GetClassRosterArray();

        // functions
        void parse(string studentData);
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        bool isValidEmail(string email);
        bool isChar(char c);

    private:
        size_t currentIndex;
        string::size_type i; 
        int numRemoved;
};

#endif