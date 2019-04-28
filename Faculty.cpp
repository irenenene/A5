#include "Faculty.h"
#include <string>

Faculty::Faculty() : Person(), id(0), level("Default level"), department("Default department"), advisees() {

}

Faculty::Faculty(int i) : Person(), id(i), level("Default level"), department("Default department"), advisees() {

}

Faculty::Faculty(string n, int i, string l , string d) : Person(n), id(i), level(l), department(d), advisees() {

}

Faculty::Faculty(Faculty& other) : Person(other.name), id(other.id),
                                  level(other.level), department(other.department),
                                  advisees(other.advisees) {

}

Faculty& Faculty::operator= (Faculty& other) {
  name = other.name;
  id = other.id;
  level = other.level;
  department = other.department;
  advisees = other.advisees;

  return *this;
}

string Faculty::getInfo() const {
  string retString = "";
  retString = "ID: " + to_string(id) + " - " +
              "Name: " + name + " - " +
              "Level: " + level + " - " +
              "Department: " + department + " - " +
              "Num of advisees: " + to_string(advisees.size);
  return retString;
}
