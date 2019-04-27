#include "Student.h"
#include <string>

Student::Student() : Person() {
  id = 0;
  level = "Default level";
  major = "Default major";
  gpa = 0.0;
  advisorID = 0;
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
