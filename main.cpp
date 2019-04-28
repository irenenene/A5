#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Database.h"

#include <iostream>

using namespace std;

int main(int argc, char** args) {
  Database db;

  //BEGIN TEST
  Faculty Bob (1234);
  Bob.advisees.insert(55);
  Bob.advisees.insert(48);
  cout << Bob.getInfo();
  Bob.advisees.remove(55);
  db.masterFaculty.insert(Bob);
  cout << Bob.getInfo();
/*  Faculty Alice (666);
  Student Adam (55);
  Student Arry (5555);

  cout << Bob.getInfo() << endl;
  cout << "----" << endl;

  Bob.advisees.insert(55);
  cout << Bob.getInfo() << endl;
  //Bob.advisees.remove(55);
  //cout << "after remove: " << Bob.getInfo() << endl;

  Adam.advisorID = 666;

  db.masterFaculty.insert(Bob);
/*  db.masterFaculty.insert(Alice);
  db.masterStudent.insert(Adam);
  db.masterStudent.insert(Arry);
*/
  while(!db.isDone){
    db.displayMenu();
    db.mainMenu();
  }


}
