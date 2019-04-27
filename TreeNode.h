#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

template <class T>
class Node {
public:
  //Node();
  Node(T d);
  virtual ~Node();

  T data;
  Node *parent;
  Node *left;
  Node *right;
}

template <class T>
Node::Node(T d) {
  data = d;
  parent = null;
  left = null;
  right = null;
}

#endif
