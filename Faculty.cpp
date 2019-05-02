#include "Faculty.h"

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

//for writing to file
void Faculty::write(ostream &outs) {
  outs << name << endl;
  outs << id << endl;
  outs << level << endl;
  outs << department << endl;
  outs << advisees.size << endl;
  for (IntList::Iterator iter = advisees.begin(); iter != advisees.end(); iter++) {
    outs << *iter << endl;
  }
}

void Faculty::read(ifstream &ins) {
  try {
    getline(ins, name);
    string inputString;
    getline(ins, inputString);
    id = stoi(inputString);
    getline(ins, level);
    getline(ins, department);
    getline(ins, inputString);
    int numAdvisees = stoi(inputString);
    for(int i = 0; i < numAdvisees; i++) {
      getline(ins, inputString);
      int tempSID = stoi(inputString);
      advisees.insert(tempSID);
    }
  }
  catch (invalid_argument &e) {
    cout << e.what() << endl;
  }

}
