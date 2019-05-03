/*
Irene Liu
irliu@chapman.edu
2313260
CPSC 350-02
Assignment 5

Contains the database implementation and methods for user interaction
*/
#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Database::Database() {
  isDone = false;
  initialize();
}

void Database::initialize() {
  /*
  check the current directory for the existence of 2 files
  facultyTable and studentTable
  if either doesn't exist, initialize both tables as blank.
  */
  //ifstream inputFile;

  // Faculty Table begin //
  ifstream facultyStream;
  facultyStream.open("facultyTable");
  bool noFaculty = false; //flag will be set if error encountered

  if(facultyStream.is_open()) {
    string fileIn = "";
    try {
      while(getline(facultyStream, fileIn)) { //get the name first
        Faculty newFac; //scope should only be within this block.

        newFac.name = fileIn;
        getline(facultyStream, fileIn); //get the ID num
        newFac.id = stoi(fileIn);
        getline(facultyStream, fileIn); //get the level
        newFac.level = fileIn;
        getline(facultyStream, fileIn); //get the department
        newFac.department = fileIn;
        getline(facultyStream, fileIn); //get the number of advisees
        int numAdv = stoi(fileIn);

        for(int i = 0; i < numAdv; i++) { //add studentID to advisees list
          cout << "Adding a student." << endl;
          getline(facultyStream, fileIn);
          int tempSID = stoi(fileIn);
          newFac.advisees.insert(tempSID);
        }

        cout << newFac << endl;
        //ADD THE NEW FACULTY MEMBER TO THE TABLE
        masterFaculty.insert(newFac);
        noFaculty = false;
      }
    }
    catch (const ifstream::failure& e) { //should catch a fail bit if trying to read past eof
      cout << "Tried to read past EOF" << endl;
      noFaculty = true;
    }
    catch (const invalid_argument &e) { //catches failed casts that can result from a corrupted file
      cout << "Error reading from file." << endl;
      noFaculty = true;
    }

    facultyStream.close();
  }
  else {
    cout << "facultyTable does not exist." << endl;
    noFaculty = true;
  }

  // Faculty Table end //

  // Student Table begin //
  ifstream studentStream;
  studentStream.open("studentTable");
  bool noStudent = true;

  if(studentStream.is_open()) {
    string fileString = "";
    try {
      while(getline(studentStream, fileString)) { //get the name first
        Student newStu;

        newStu.name = fileString;
        getline(studentStream, fileString); //get the ID number
        newStu.id = stoi(fileString);
        getline(studentStream, fileString); //get the level
        newStu.level = fileString;
        getline(studentStream, fileString); //get the Major
        newStu.major = fileString;
        getline(studentStream, fileString); //get the gpa and cast to double.
        newStu.gpa = stod(fileString);
        getline(studentStream, fileString); //get the advisor ID
        newStu.advisorID = stoi(fileString);
        cout << "here.";
        cout << newStu << endl;
        //ADD THE NEW STUDENT TO THE TABLE
        masterStudent.insert(newStu);
        noStudent = false;
      }
    }
    catch (const ifstream::failure& e) { //should catch a fail bit if trying to read past eof
      cout << "Tried to read past EOF" << endl;
      noStudent = true;
    }
    catch (const invalid_argument &e) { //catches failed casts that can result from a corrupted file
      cout << "Error reading from file." << endl;
      noStudent = true;
    }
  }
  else {
    cout << "studentTable does not exist." << endl;
    noStudent = true;
  }
  // Student Table End //

  //START TESTING OF READING FROM FILE *********************

  //check if there were any problems with either the faculty or student table
  //if so, clear BOTH tables.
  cout << noStudent << endl;
  cout << noFaculty << endl;
  if (noStudent || noFaculty) {
    cout << "Error reading from files. Starting with blank tables." << endl;
    masterFaculty.recursiveDelete(masterFaculty.getRoot());
    masterStudent.recursiveDelete(masterStudent.getRoot());
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
  Student temp(i);
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

void Database::addStudent() {
  string userInput;
  cout << "Enter the student's ID number: ";
  getline(cin, userInput);

  try {
    int sID = stoi(userInput);

    if(findBySID(sID) == NULL) { //if that ID is not being used
      string sName;
      string sLevel;
      string sMajor;
      double sGPA;

      cout << "Enter the student's name: ";
      getline(cin, sName);
      cout << "Enter the student's level: ";
      getline(cin, sLevel);
      cout << "Enter the student's major: ";
      getline(cin, sMajor);
      cout << "Enter the student's GPA: ";
      getline(cin, userInput);
      sGPA = stod(userInput);
      Student *newStudent = new Student(sName, sID, sLevel, sMajor, sGPA, 0);
      masterStudent.insert(*newStudent);
      cout << "Done." << endl;

      //for rollback
      Command c(7, *newStudent);
      commands.push(c);

      delete newStudent;
    }
    else {
      cout << "That ID number is already being used." << endl;
    }

  }
  catch (const invalid_argument &e) {
    cout << "You entered an invalid number." << endl;
  }
}

void Database::findAdvisor() {
  string userInput;
  cout << "Enter a student ID number: ";
  getline(cin, userInput);

  try {
    int sID = stoi(userInput);

    Student* advisee = findBySID(sID);
    if(advisee != NULL) { //if the student exists
      if(advisee->advisorID > 0) { //if valid facultyID
        int fID = advisee->advisorID;
        Faculty* advisor = findByFID(fID);

        if(advisor != NULL) { //if the advisor exists
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

void Database::deleteStudent() {
  string userInput;
  cout << "Enter the student ID number: ";
  getline(cin, userInput);

  try {
    int searchID = stoi(userInput);

    Student *theStudent = findBySID(searchID);
    if(theStudent != NULL) { //if the student is in the system
      //remove reference of the student from advisor
      int advID = theStudent->advisorID;
      if(advID > 0) {
        Faculty *theAdvisor = findByFID(advID);
        if(theAdvisor != NULL) {
          theAdvisor->advisees.remove(searchID);
        }
      }

      //for rollback
      Command c(8, *theStudent);
      commands.push(c);

      masterStudent.deleteNode(*theStudent);
      cout << "Done." << endl;
    }
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

void Database::addFaculty() {
  string userInput;
  cout << "Enter the new faculty's ID number: ";
  getline(cin, userInput);

  try {
    int aID = stoi(userInput);

    if(aID == 0)
      cout << "You can not use that ID number." << endl;

    if(findByFID(aID) == NULL && aID > 0) { //if that ID is not being used
      string level;
      string department;
      string name;
      cout << "Enter the faculty member's name: ";
      getline(cin, name);
      cout << "Enter the faculty member's level: ";
      getline(cin, level);
      cout << "Enter the faculty member's department: ";
      getline(cin, department);

      Faculty *newFaculty = new Faculty(name, aID, level, department);
      masterFaculty.insert(*newFaculty);

      //for rollback
      Command c(9, *newFaculty);
      commands.push(c);

      cout << "Done." << endl;
      delete newFaculty;
    }
    else {
      cout << "That ID number is already being used." << endl;
    }
  }
  catch (const invalid_argument &e) {
    cout << "You entered an invalid number." << endl;
  }
}

void Database::deleteFaculty() {
  string userInput;
  cout << "Please enter the faculty ID number: ";
  getline(cin, userInput);

  try {
    int idNum = stoi(userInput);

    Faculty *theFaculty = findByFID(idNum);
    if (theFaculty != NULL) { //if the faculty member exists
      //iterate through their advisee list
      for( IntList::Iterator iter = theFaculty->advisees.begin(); iter != theFaculty->advisees.end(); iter++) {
        //for each advisee, update their advisor reference.
        //cout << *iter << " ";
        int sID = *iter;

        Student* theStudent = findBySID(sID);
        if(theStudent != NULL) { //if that student exists
          //update their advisor
          theStudent->advisorID = 0;
        }
      }

      //for rollback
      Command c(10, *theFaculty);
      commands.push(c);

      masterFaculty.deleteNode(*theFaculty);
      cout << "Done." << endl;
    }
    else {
      cout << "Could not locate a faculty member with that ID number." << endl;
    }
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

void Database::changeAdvisor() {
  string userInput;
  cout << "Enter a student ID number: ";
  getline(cin, userInput);

  try {
    int sID = stoi(userInput);

    Student *theStudent = findBySID(sID);
    if(theStudent != NULL) { //if the student is in the system
      cout << "Enter a new advisor ID: ";
      getline(cin, userInput);
      int aID = stoi(userInput);

      Faculty *theFaculty = findByFID(aID);
      if(theFaculty != NULL) {
        if(theStudent->advisorID > 0) {//if the student had an advisor
          Faculty *prevAdvisor = findByFID(theStudent->advisorID);
          //remove the student from the previous advisee
          if(prevAdvisor != NULL) {
            prevAdvisor->advisees.remove(sID);
            cout << "Removed the reference from the previous advisor." << endl;
          }
        }

        //update the new advisor's advisee list
        if(!theFaculty->advisees.contains(sID)) {
          theFaculty->advisees.insert(sID);
        }
        else {
          cout << "That student id is already in that faculty's advisee list" << endl;
        }

        //for rollback
        //NOTE: Rollback saves a copy of the student with the OLD advisor ID and then a copy of the NEW faculty member.
        //This way, the rollback/command object can have a reference to all 3.
        //It is also assumed that you can not change TO advisorID 0, but you can change FROM advisorID 0.
        Command c(11, *theStudent, *theFaculty);
        commands.push(c);

        //update the student's advisor number
        theStudent->advisorID = aID;
        cout << "Done." << endl;
      }
      else {
        cout << "That faculty member is not in the system." << endl;
      }
    }
    else {
      cout << "Could not find a student with that ID number. " << endl;
    }
  }
  catch (const invalid_argument &e) {
    cout << "You did not enter a valid number." << endl;
  }
}

void Database::removeAdvisee() {
  string userInput;
  cout << "Enter a faculty ID number: ";
  getline(cin, userInput);

  try {
    int advID = stoi(userInput);

    Faculty *advisor = findByFID(advID);
    if(advisor != NULL) {
      cout << "Advisees for advisor #:" << advID << endl;
      for( IntList::Iterator iter = advisor->advisees.begin(); iter != advisor->advisees.end(); iter++) {
        //display their advisees
        cout << *iter << endl;
      }

      cout << "Which advisee would you like to remove: ";
      getline(cin, userInput);
      int sID = stoi(userInput);

      Student* theStudent = findBySID(sID);
      if(theStudent != NULL) { //if the student exists
        if(advisor->advisees.contains(sID)) { //if the student is in the advisor's list
          theStudent->advisorID = 0;
          advisor->advisees.remove(sID);

          //for rollback
          Command c(12, *theStudent, *advisor);
          commands.push(c);

          cout << "Done." << endl;
        }
        else {
          cout << "That student is not an advisee of this advisor." << endl;
        }
      }
      else {
        cout << "That student does not exist in the system." << endl;
      }
    }
    else {
      cout << "Could not find an advisor with that ID number." << endl;
    }
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
  else if(userInput == "7") {
    addStudent();
  }
  else if(userInput == "8") {
    deleteStudent();
  }
  else if(userInput == "9") {
    addFaculty();
  }
  else if(userInput == "10") {
    deleteFaculty();
  }
  else if(userInput == "11") {
    changeAdvisor();
  }
  else if(userInput == "12") {
    removeAdvisee();
  }
  else if(userInput == "13") {
    rollback();
  }
  else if(userInput == "14") {
    isDone = true;

    //writing both BSTs to their respective files.
    cout << "Writing to file..." << endl;
    ofstream out("facultyTable", fstream::out);
    if(out.is_open()) {
      masterFaculty.writeTree(out);
      out.close();
    }

    ofstream studentOut("studentTable", fstream::out);
    if(studentOut.is_open()) {
      masterStudent.writeTree(studentOut);
      studentOut.close();
    }
  }
  else {
    cout << "You did not make a valid selection." << endl;
  }
}

void Database::rollback() {
  bool hasCommand = true;
  Command lastCommand;
  try {
    lastCommand = commands.pop();
  }
  catch (const GenStack<Command>::EmptyStackException &e) {
    cout << "No commands to roll back." << endl;
    hasCommand = false;
  }

  if(hasCommand) {
    if(lastCommand.num == 7) { //undo add student
      cout << "Undo: Add" << endl;
      masterStudent.deleteNode(lastCommand.s);
    }
    else if(lastCommand.num == 8) { //undo delete student
      cout << "Undo: Delete" << endl;
      masterStudent.insert(lastCommand.s);

      if(lastCommand.s.advisorID > 0) { //if the student had an advisor
        //update the advisor with the student.
        Faculty *oldAdvisor = findByFID(lastCommand.s.advisorID);
        oldAdvisor->advisees.insert(lastCommand.s.id);
      }
    }
    else if(lastCommand.num == 9) { //undo add Faculty
      cout << "Undo: Add" << endl;
      masterFaculty.deleteNode(lastCommand.f);
    }
    else if(lastCommand.num == 10) { //undo delete Faculty
      cout << "Undo: Delete" << endl;
      masterFaculty.insert(lastCommand.f);

      for( IntList::Iterator iter = lastCommand.f.advisees.begin(); iter != lastCommand.f.advisees.end(); iter++) {
        //update advisor for each student
        int sID = *iter;
        Student* theStudent = findBySID(sID);
        theStudent->advisorID = lastCommand.f.id;
      }
    }
    else if(lastCommand.num == 11) { //undo change advisor
      cout << "Undo: Change Advisor" << endl;
      //Remember that the Command obj's Student has the OLD advisor
      //and Faculty is the NEW advisor.

      //remove the advisee from the "new" advisor.
      cout << "1" << endl;
      Faculty *newAdv = findByFID(lastCommand.f.id);
      cout << *newAdv << endl;
      cout << "2" << endl;
      newAdv->advisees.remove(lastCommand.s.id);
      //add the student back to the "old" advisor.
      Faculty *oldAdv = findByFID(lastCommand.s.advisorID);
      if(oldAdv != NULL) { //if previous advisor wasn't "unassigned", then update
      cout << "3" << endl;
        oldAdv->advisees.insert(lastCommand.s.id);
      }
      //change the student's advisor ID.
      Student *theStudent = findBySID(lastCommand.s.id);
      cout << "4" << endl;
      theStudent->advisorID = lastCommand.s.advisorID;
    }
    else if(lastCommand.num == 12) { //undo remove advisee
      cout << "Undo: Remove advisee" << endl;
      //change the student's advisor ID
      Student *theStudent = findBySID(lastCommand.s.id);
      theStudent->advisorID = lastCommand.f.id;
      //add student back to the advisor's list
      Faculty *theFaculty = findByFID(lastCommand.f.id);
      theFaculty->advisees.insert(lastCommand.s.id);
    }

  }
}
