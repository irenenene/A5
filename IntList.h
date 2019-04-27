#ifndef INTLIST_H
#define INTLIST_H

//a very barebones list class for holding integers

#include "IntNode.h"
#include <iostream>
using namespace std;

class IntList {
public:
  IntList();
  ~IntList();
  bool isEmpty();
  void insert(int d);
  void remove(int d);

  IntNode* start;
  int size;
};
#endif
