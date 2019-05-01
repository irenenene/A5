#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person {
public:
  Student();
  Student(Student& other);
  Student(int i);
  Student(string n, int i, string l, string m, double g, int aID);
//  ~Student();
  string getInfo() const;

  int id; //can probably move this to person class
  string level;
  string major;
  double gpa;
  int advisorID;

  Student& operator= (Student& other);

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
  friend ostream& operator<< (ostream &out, const Student &s) {
    out << s.getInfo();
    return out;
  };

};

#endif
