#include "Faculty.h"
#include <string>

Faculty::Faculty() : Person() {
  id = 0;
  level = "Default level";
  department = "Default department";
}

Faculty::Faculty(int i) : Person() {
  id = i;
  level = "Default level";
  department = "Default department";
}

Faculty::Faculty(string n, int i, string l , string d) : Person(n) {
  id = i;
  level = l;
  department = d;
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
