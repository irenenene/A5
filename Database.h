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
  void findAdvisor();
  void findAdvisees();
  void addStudent();
  void deleteStudent();
  void addFaculty();
  void deleteFaculty();
  void changeAdvisor();
  void removeAdvisee();

  //helper methods utilizing the BST search
  Student* findBySID(int i);
  Faculty* findByFID(int i);
  bool isDone;
};

#endif
