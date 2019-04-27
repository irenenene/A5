#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person {
public:
  Student();
  Student(int i);
  Student(string n, int i, string l, string m, double g, int aID);
//  ~Student();
  string getInfo();

  int id;
  string level;
  string major;
  double gpa;
  int advisorID;

  //overloaded operators
  friend bool operator== (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id == studentTwo.id;
  }
  friend bool operator!= (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id != studentTwo.id;
  }
  friend bool operator< (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id < studentTwo.id;
  }
  friend bool operator> (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id > studentTwo.id;
  }
  friend bool operator<= (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id <= studentTwo.id;
  }
  friend bool operator>= (const Student &studentOne, const Student &studentTwo) {
    return studentOne.id >= studentTwo.id;
  }

};

#endif
