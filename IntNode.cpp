#include "IntNode.h"
#include <iostream>
using namespace std;

IntNode::IntNode() {
  data = 0;
  next = nullptr;
}

IntNode::IntNode(int d) {
  data = d;
  next = nullptr;
}

IntNode::IntNode(IntNode& other) {
  data = other.data;
  next = nullptr;
}

IntNode::~IntNode() {
  next = nullptr;
}
