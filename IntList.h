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
  IntList( IntList& other);
  bool isEmpty();
  void insert(int d);
  void remove(int d);
  void printList();
  bool contains(int d);

  IntNode* start;
  int size;
  IntList& operator=(IntList& other);

  //Iterator stuff

  class Iterator;

  Iterator begin() {
    return Iterator(start);
  }

  Iterator end() {
    return Iterator(nullptr);
  }

  class Iterator {
  public:
    //Iterator() : curr(start) {}
    Iterator(IntNode* theNode) : curr(theNode) {}
    Iterator& operator= (IntNode* theNode) {
      this->curr = theNode;
      return *this;
    }

    Iterator& operator++() {
      if(curr != NULL)
        curr = curr->next;
        return *this;
    }

    Iterator operator++(int) {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }

    bool operator!= (Iterator it) {
      return curr != it.curr;
    }

    int operator *() {
      return curr->data;
    };

    IntNode* curr;
  };
};
#endif
