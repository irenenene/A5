#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "IntList.h"

using namespace std;

class Faculty : public Person {
public:
  Faculty();
  Faculty(int i);
  Faculty(string n, int i, string l, string d);
  Faculty(Faculty& other);
  //~Faculty();
  string getInfo() const; //for console output
  string writeInfo() const; //for file output
  //void write(ostream &outs);
  void read(ifstream &ins);

  int id;
  string level;
  string department;
  IntList advisees;

  Faculty& operator= (Faculty& other);

  //overloaded operators
  friend bool operator== (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id == facultyTwo.id;
  }
  friend bool operator!= (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id != facultyTwo.id;
  }
  friend bool operator< (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id < facultyTwo.id;
  }
  friend bool operator> (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id > facultyTwo.id;
  }
  friend bool operator<= (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id <= facultyTwo.id;
  }
  friend bool operator>= (const Faculty &facultyOne, const Faculty &facultyTwo) {
    return facultyOne.id >= facultyTwo.id;
  }

  //for console output
  friend ostream& operator<< (ostream &out, const Faculty &f) {
    out << f.getInfo();
    return out;
  }

  //for file output
  friend ofstream& operator<< (ofstream &outs, const Faculty &f) {
    outs << f.writeInfo();
    return outs;
  }
};

#endif
