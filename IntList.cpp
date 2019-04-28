#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
  start = nullptr;
  size = 0;
}

IntList::~IntList() {
/*  if(!isEmpty()) {
    IntNode *curr = start;

    while (curr != NULL) {
      IntNode *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }*/
  delete start;
}

IntList::IntList(IntList& other) {
  size = other.size;
  if (size > 0) {
    IntNode* otherCurr = other.start;
    start = new IntNode(otherCurr->data);
    IntNode* curr = start;

    while(otherCurr->next != NULL) {
      curr->next = new IntNode(otherCurr->next->data);
      otherCurr = otherCurr->next;
      curr = curr->next;
    }
  }
  else
    start = nullptr;
}

IntList& IntList::operator=(IntList& other) {
  if(!isEmpty()) //clear the list so we can make a new one
    delete start;

    size = other.size;
    if (size > 0) {
      IntNode* otherCurr = other.start;
      start = new IntNode(otherCurr->data);
      IntNode* curr = start;

      while(otherCurr->next != NULL) {
        curr->next = new IntNode(otherCurr->next->data);
        otherCurr = otherCurr->next;
        curr = curr->next;
      }
    }
    else
      start = nullptr;

    return *this;
}

bool IntList::isEmpty() {
  return size == 0;
}

void IntList::insert(int d) {
  IntNode *newNode = new IntNode(d);

  if(!isEmpty()) {
    newNode->next = start;
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
