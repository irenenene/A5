#ifndef INTNODE_H
#define INTNODE_H

#include <iostream>
using namespace std;

class IntNode {
public:
  IntNode();
  IntNode(int d);
  ~IntNode();

  int data;
  IntNode *next;
};

#endif
