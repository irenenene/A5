/*
Irene Liu
irliu@chapman.edu
2313260
CPSC 350-02
Assignment 5

Used to run the database class
*/

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "Database.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** args) {
  Database db;

  while(!db.isDone){
    db.displayMenu();
    db.mainMenu();
  }


}
