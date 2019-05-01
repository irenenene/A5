#include "Student.h"
#include <string>

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
  advisorID = other.advisorID;
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
