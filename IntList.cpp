#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
  start = NULL;
  size = 0;
}

IntList::~IntList() {
  if(!isEmpty()) {
    IntNode *curr = start;

    while (curr != NULL) {
      IntNode *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}

bool IntList::isEmpty() {
  return size == 0;
}

void IntList::insert(int d) {
  IntNode *newNode = new IntNode(d);

  if(!isEmpty()) {
    newNode->next = start->next;
  }
  start = newNode;
  size++;
}

void IntList::remove(int d) {
  if(!isEmpty())
  {
    if(size == 1) {
      delete start;
      start = NULL;
      size--;
    }
    else {
      IntNode *curr = start;
      IntNode *temp;

      while (curr != NULL) {
        if(curr->data != d) {
          temp = curr;
          curr = curr->next;
        }
        else { //data was found
          temp->next = curr->next;
          delete curr;
          size--;
          break;
        }
      } //traversed entire list without finding
    }
  }
}
