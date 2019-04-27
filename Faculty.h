#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "Person.h"
#include "IntList.h"

using namespace std;

class Faculty : public Person {
public:
  Faculty();
  Faculty(int i);
  Faculty(string n, int i, string l, string d);
  //~Faculty();
  string getInfo() const;

  int id;
  string level;
  string department;
  IntList advisees;

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
  friend ostream& operator<< (ostream &out, const Faculty &f) {
    out << f.getInfo();
    return out;
  }
};

#endif
