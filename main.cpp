#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Database.h"

#include <iostream>

using namespace std;

int main(int argc, char** args) {
//  BST<Student> masterStudent;
//  BST<Faculty> masterFaculty;
  Database db;


  Faculty Bob (1234);
  Faculty Alice (666);
  Student Adam (55);
  Student Arry (5555);

  cout << Bob.getInfo() << endl;
  cout << "----" << endl;

  Bob.advisees.insert(55);
  cout << Bob.getInfo() << endl;
  Bob.advisees.remove(55);
  cout << "after remove: " << Bob.getInfo() << endl;

  db.masterFaculty.insert(Bob);
  db.masterFaculty.insert(Alice);
  db.masterStudent.insert(Adam);
  db.masterStudent.insert(Arry);
  db.mainMenu();

}
