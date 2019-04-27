#include "Person.h"
#include "Student.h"
#include "BST.h"

#include <iostream>

using namespace std;

int main(int argc, char** args) {
  BST<Student> masterStudent;
  Student Bob (1234);


  cout << Bob.getInfo();
}
