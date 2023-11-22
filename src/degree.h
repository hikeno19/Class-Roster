#include <iostream>
#ifndef DEGREE_H
#define DEGREE_H
#define stringify(name) #name

using namespace std;

enum DegreeProgram {
    SECURITY,
    NETWORK,
    SOFTWARE
};

class Degree
{
    public:
    // getter of program from string
    static const DegreeProgram GetProgramFromName(string program)
    {
        if (program == "SECURITY")
        {
            return DegreeProgram::SECURITY;
        }
        else if (program == "SOFTWARE")
        {
            return DegreeProgram::SOFTWARE;
        }
        else if (program == "NETWORK")
        {
            return DegreeProgram::NETWORK;
        }
        else
        {
            std::cerr << "Invalid degree program name!";
            return DegreeProgram::SOFTWARE; // Default to SOFTWARE for illustration
        }
    };

    //getter of string from program
    static const string GetNameFromProgram(DegreeProgram program)
    {
        switch (program)
        {
        case DegreeProgram::SECURITY:
            return "SECURITY";
            break;
        case DegreeProgram::NETWORK:
            return "NETWORK";
            break;
        case DegreeProgram::SOFTWARE:
            return "SOFTWARE";
            break;
        default:
            std::cerr << "Invalid degree program!";
            return "";
        }
    };
};

#endif
