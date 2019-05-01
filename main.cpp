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
  Bob.advisees.insert(5555);
  Bob.advisees.insert(1);
  Bob.advisees.insert(2);
  Bob.advisees.insert(3);
  Bob.advisees.remove(1);
  //db.masterFaculty.insert(Bob);
  Faculty Alice (666);
  Student Adam (55);
  Student Arry (5555);
//  Student Stud (48);
  Arry.advisorID = 1234;
  Adam.advisorID = 1234;

  db.masterFaculty.insert(Bob);
  db.masterFaculty.insert(Alice);
  db.masterStudent.insert(Adam);
  db.masterStudent.insert(Arry);
//  db.masterStudent.insert(Stud);

  while(!db.isDone){
    db.displayMenu();
    db.mainMenu();
  }


}
