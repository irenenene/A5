#include "IntNode.h"
#include <iostream>
using namespace std;

IntNode::IntNode() {
  data = 0;
  next = NULL;
}

IntNode::IntNode(int d) {
  data = d;
  next = NULL;
}

IntNode::~IntNode() {
  next = NULL;
}
