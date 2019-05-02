#include "Student.h"

/*
The file input/output format will be
line 1: name
line 2: id
line 3: level
line 4: major
line 5: gpa
line 6: advisorID (0 if no advisor)
*/

//the implementation of student follows Faculty's implementation with just a few differences
//comments will be in Faculty.cpp

Student::Student() : Person() {
  id = 0;
  level = "Default level";
  major = "Default major";
  gpa = 0.0;
  advisorID = 0;
}

Student::Student(Student& other) : Person(other.name) {
  id = other.id;
  level = other.level;
  major = other.major;
  gpa = other.gpa;
  advisorID = other.advisorID;
}

Student::Student(int i) : Person() {
  id = i;
  level = "Default level";
  major = "Default major";
  gpa = 0.0;
  advisorID = 0;
}

Student::Student(string n, int i, string l, string m, double g, int aID) : Person(n) {
  id = i;
  level = l;
  major = m;
  gpa = g;
  advisorID = aID;
}
/*
Student::~Student() {

}*/

Student& Student::operator= (Student& other) {
  name = other.name;
  id = other.id;
  level = other.level;
  major = other.major;
  gpa = other.gpa;
  advisorID = other.advisorID;

  return *this;
}

string Student::getInfo() const {
  string retString = "";
  retString = "ID: " + to_string(id) + " - " +
              "Name: " + name + " - " +
              "Level: " + level + " - " +
              "Major: " + major + " - " +
              "GPA: " + to_string(gpa) + " - " +
              "AdvisorID: " + to_string(advisorID);
  return retString;
}

string Student::writeInfo() const{
  string retString = "";
  retString += name + '\n';
  retString += to_string(id) + '\n';
  retString += level + '\n';
  retString += major + '\n';
  retString += to_string(gpa) + '\n';
  retString += to_string(advisorID) + '\n';

  return retString;
}
