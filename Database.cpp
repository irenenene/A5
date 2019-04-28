#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Database::Database() {
  //initialize();
  isDone = false;
}

void Database::initialize() {
  //check the current directory for the existence of 2 files
  //facultyTable and studentTable
  //if neither exist, initialize as new.
  //if only one exists, remove references
  ifstream inputFile;
  inputFile.open("facultyTable");

  //if the files do exist, they should be read into the appropriate variables
  //do this later
  if(inputFile.is_open()) {
    //read serialized data into masterFaculty

    inputFile.close();
  }


}

void Database::displayMenu() {
  cout << "-----Main Menu-----" << endl;
  cout << "1. Print all students and their information." << endl;
  cout << "2. Print all faculty and their information." << endl;
  cout << "3. Find and display student information" << endl;
  cout << "4. Find and display faculty information" << endl;
  cout << "5. Find advisor by student" << endl;
  cout << "6. Find students by advisor" << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student" << endl;
  cout << "9. Add new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student's advisor" << endl;
  cout << "12. Remove an advisee from advisor" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}

void Database::findStudent() {
  string userInput;
  cout << "Enter an ID number to search: ";
  getline(cin, userInput);

  try {
    int id = stoi(userInput); //note this can extract a number even if followed by a string, but not vice versa.

    Student *found = findBySID(id);
    if(found != NULL) {
      cout << "Found a student with id: " << id << endl;
      cout << *found << endl;
    }
    else
      cout << "Could not find a student with id: " << id << endl;
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

void Database::findFaculty() {
  string userInput;
  cout << "Enter an ID number to search: ";
  getline(cin, userInput);

  try {
    int id = stoi(userInput); //note this can extract a number even if followed by a string, but not vice versa.

    Faculty *found = findByFID(id);
    if(found != NULL) {
      cout << "Found a faculty member with id: " << id << endl;
      cout << *found << endl;
      found->advisees.printList(); //DEBUGGING
    }
    else
      cout << "Could not find a faculty member with id: " << id << endl;
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

void Database::findAdvisees() {
  string userInput;
  cout << "Enter a faculty ID number: ";
  getline(cin, userInput);

  try {
    int id = stoi(userInput);

    Faculty *advisor = findByFID(id);
    if(advisor != NULL) {
      cout << "Found a faculty member with id: " << id << endl;
      IntNode* curr;

      if (!advisor->advisees.isEmpty()) { //if the advisor has at least 1 advisee
        cout << "Students for advisor number: " << id << endl;
        curr = advisor->advisees.start; //set curr to the start of the advisee list
        while(curr != nullptr) { //and print the corresponding student in the student table
          Student* adv = findBySID(curr->data);

          if(adv != nullptr)
            cout << *adv << endl;
          else
            cout << "Error finding a match in student table." << endl; //DEBUG
          curr = curr->next;
        }
      }
      else
        cout << "That faculty member does not have any advisees";
    }
    else
      cout << "Could not find a faculty member with id: " << id << endl;
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

Student* Database::findBySID(int i) {
  Student temp = Student(i);
  Node<Student> *result = masterStudent.getNode(temp);
  if(result != NULL) {
    return &result->data;
  }
  else
    return nullptr;
}

Faculty* Database::findByFID(int i) {
  Faculty temp(i);
  Node<Faculty> *result = masterFaculty.getNode(temp);
  if(result != NULL) {
    return &result->data;
  }
  else
    return nullptr;
}

void Database::findAdvisor() {
  string userInput;
  cout << "Enter a student ID number: ";
  getline(cin, userInput);

  try {
    int sID = stoi(userInput);

    Student* advisee = findBySID(sID);
    if(advisee != NULL) {
      if(advisee->advisorID > 0) { //if valid facultyID
        int fID = advisee->advisorID;
        Faculty* advisor = findByFID(fID);

        if(advisor != NULL) {
          cout << "Found the advisor for student ID: " << sID << endl;
          cout << *advisor << endl;
        }
        else {
          cout << "The advisor for that student was not found." << endl;
        }
      }
      else {
        cout << "That student does not have an advisor." << endl;
      }
    }
    else
      cout << "Student not found." << endl;
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}


void Database::mainMenu() {
  //displayMenu();
  string userInput;
  cout << "Enter the number corresponding to your choice: ";
  getline(cin, userInput);

  if(userInput == "1") {
    cout << "---Students---" << endl;
    masterStudent.printTree();
  }
  else if(userInput == "2") {
    cout << "---Faculty---" << endl;
    masterFaculty.printTree();
  }
  else if(userInput == "3") {
    findStudent();
  }
  else if(userInput == "4") {
    findFaculty();
  }
  else if(userInput == "5") {
    findAdvisor();
  }
  else if(userInput == "6") {
    findAdvisees();
  }
  else if(userInput == "14") {
    isDone = true;
  }
  else {
    cout << "You did not make a valid selection." << endl;
  }
}
