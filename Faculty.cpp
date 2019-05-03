#include "Faculty.h"
/*
The file input/output format will be
line 1: name
line 2: id
line 3: level
line 4: department
line 5: number of advisees
line 6+: one line for each advisee number in the list
*/

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

//used for string console output of the object.
string Faculty::getInfo() const {
  string retString = "";
  retString = "ID: " + to_string(id) + " - " +
              "Name: " + name + " - " +
              "Level: " + level + " - " +
              "Department: " + department + " - " +
              "Num of advisees: " + to_string(advisees.size);
  return retString;
}

/*
//was only used for testing. use the overload << ofstream instead
void Faculty::write(ostream &outs) {
  outs << name << endl;
  outs << id << endl;
  outs << level << endl;
  outs << department << endl;
  outs << advisees.size << endl;
  for (IntList::Iterator iter = advisees.begin(); iter != advisees.end(); iter++) {
    outs << *iter << endl;
  }
}*/

//writeInfo is used to format output to a text file
//so it can be used by the extraction operator
string Faculty::writeInfo() const{
  string retString = "";
  retString += name + '\n';
  retString += to_string(id) + '\n';
  retString += level + '\n';
  retString += department + '\n';
  retString += to_string(advisees.size) + '\n';
  for (IntList::Iterator iter = advisees.begin(); iter != advisees.end(); iter++) {
    retString += to_string(*iter) + '\n';
  }

  return retString;
}

//initializes member variables line by line
//expects the input format to adhere to the output format above
//need to do error checking with this still..
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
      //cout << "Adding a student." << endl;
      getline(ins, inputString);
      int tempSID = stoi(inputString);
      advisees.insert(tempSID);
    }
  }
  catch (invalid_argument &e) {
    cout << "Invalid argument." << endl;
  }

}
