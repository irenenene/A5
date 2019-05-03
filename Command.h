#ifndef COMMAND_H
#define COMMAND_H

#include "Faculty.h"
#include "Student.h"

class Command {
public:
    Command() {};
    //~Command();
    Command(int comm, Student& theStudent): num(comm), s(theStudent) {};
    Command(int comm, Faculty& theFac): num(comm), f(theFac) {};

    Student s;
    Faculty f;
    int num; //number corresponding to the command
    /*
    7. Add Student
    8. Delete Student
    9. Add Faculty
    10. Delete Faculty
    11. Change Advisor
    12. Remove Advisee
    */
};

#endif
