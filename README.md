Irene Liu  
2313260  
irliu@chapman.edu  
CPSC 350-02  
Assignment 5  

Source files: BST.h, Command.h, Database.h, Faculty.h, GenStack.h, IntList.h, IntNode.h, Person.h, Student.h,
Database.cpp, Faculty.cpp, IntList.cpp, IntNode.cpp, main.cpp, Person.cpp, Student.cpp

References used:  
https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
https://codereview.stackexchange.com/questions/192570/iterator-for-custom-list-class
https://stackoverflow.com/questions/9200827/why-does-passing-by-reference-involve-a-copy-constructor
http://www.cplusplus.com/forum/beginner/69459/


Notes:  
- Must compile/run with C++ 11 because of the use of nullptr
- References between facultyTable and studentTable are assumed if both files are read in correctly

The file input/output format for studentTable will be:  
line 1: name  
line 2: id  
line 3: level  
line 4: major  
line 5: gpa  
line 6: advisorID (0 if no advisor)  
line 7: name  
etc.  

The file input/output format for facultyTable will be:   
line 1: name  
line 2: id  
line 3: level  
line 4: department  
line 5: number of advisees  
line 6+: one line for each advisee number in the list

