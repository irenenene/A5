#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "BST.h"

#include <iostream>

using namespace std;

class Database {
public:
  BST<Student> masterStudent;
  BST<Faculty> masterFaculty;

  Database();
  //~Database();

  void initialize(); //initialize from file
  void displayMenu();
  void mainMenu();
  void findStudent();
  void findFaculty();
};

#endif
