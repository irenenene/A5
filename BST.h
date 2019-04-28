#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

//NODE CLASS BEGIN
template <class T>
class Node {
public:
  //Node();
  Node(T& d):data(d), parent(NULL), left(NULL), right(NULL) {};
  virtual ~Node();

  T data;
  Node<T> *parent;
  Node<T> *left;
  Node<T> *right;
};

template <class T>
Node<T>::~Node() {
  parent = NULL;
  left = NULL;
  right = NULL;
}
//NODE CLASS END

//BST CLASS BEGIN
template <class T>
class BST {
public:
  BST();
  ~BST();

  bool insert(T& d);
  bool deleteNode(T& d);
  bool isEmpty();
  void recursiveDelete(Node<T> *curr);
  bool contains(T& d);
  Node<T>* getSuccessor(Node<T> *d); //returns left-most child of right subtree
  Node<T>* getNode(T& d);
  void recursivePrint(Node<T>* curr);
  void printTree();

private:
  Node<T> *root;
};

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
BST<T>::~BST() {
  //call recursive delete starting from root
  if(!isEmpty())
    recursiveDelete(root);
  cout << "Deleting the tree" << endl;
}

template <class T>
bool BST<T>::isEmpty() {
  return (root == NULL);
}

template <class T>
void BST<T>::recursiveDelete(Node<T> *curr) {
  if(curr != NULL) {
    if(curr->left)
      recursiveDelete(curr->left);
    if(curr->right)
      recursiveDelete(curr->right);
    delete curr;
  }
}

template <class T>
bool BST<T>::contains(T& d) {
  if(isEmpty())
    return false;

  Node<T> *curr = root;

  while(d != curr->data) { //while not found
    if (d < curr->data)
      curr = curr->left;
    else
      curr = curr->right;

    if (curr == NULL)
      return false;
  }

  return true;
}

template <class T>
bool BST<T>::insert(T& d) {
  cout << "inserting" << endl;
  if (contains(d))
    return false;

  Node<T> *newNode = new Node<T>(d); //here*********
  cout << "after new Node" << endl;
  if(isEmpty()) {
    root = newNode;
    return true;
  }

  Node<T> *curr = root;
  Node<T> *par;

  while(true) {
    par = curr;
    if(d < curr->data) {
      curr = curr->left;
      if (curr == NULL)  {
        par->left = newNode;
        newNode->parent = par;
        return true;
      }
    }
    else {
      curr = curr->right;
      if(curr == NULL) {
        par->right = newNode;
        newNode->parent = par;
        return true;
      }
    }
  }
}

//this method already assumes that d will have both children
template <class T>
Node<T>* BST<T>::getSuccessor(Node<T>* d) { //where d is the node to be deleted
  Node<T> *par = d;
  Node<T> *successor = d;
  Node<T> *curr = d->right;

  while(curr != NULL) {
    par = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right) {
    par->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

template <class T>
Node<T>* BST<T>::getNode(T& d) {
  if(contains(d)) {
    Node<T>* curr = root;

    while (curr->data != d) {
      if (d < curr->data) {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }

    return curr;
  }
  else {
    return nullptr;
  }
}

template <class T>
bool BST<T>::deleteNode(T& d) {
  Node<T>* delNode = getNode(d);
  if (delNode == nullptr) {
    return false;
  }
  else { //start here
    //if leaf node
    if(!delNode->left && !delNode->right) {
      if(delNode == root) //if they are pointing to the same place
        root = NULL;
      else if(delNode->parent->left == delNode) //else if delNode is the left child
        delNode->parent->left == NULL;
      else
        delNode->parent->right == NULL;
    }
    //one child
    else if (delNode->right == NULL) {
      if(delNode == root)
        root = delNode->left;
      else if(delNode->parent->left == delNode)
        delNode->parent->left = delNode->left;
      else
        delNode->parent->right = delNode->left;

      delNode->left->parent = delNode->parent; //update parent pointer
    }
    else if(delNode->left == NULL) {
      if(delNode == root)
        root->right = delNode->right;
      else if(delNode->parent->left == delNode)
        delNode->parent->left = delNode->right;
      else
        delNode->parent->right = delNode->right;

      delNode->right->parent = delNode->parent;
    }
    //two children
    else {
      Node<T>* successor = getSuccessor(delNode);

      if(delNode == root)
        root = successor;
      else if (delNode->parent->left == delNode)
        delNode->parent->left = successor;
      else
        delNode->parent->right = successor;

      successor->left = delNode->left;

      //update parent pointers
      successor->left->parent = successor;
      successor->right->parent = successor;
    }

    delete delNode;
    return true;
  }
}

template <class T>
void BST<T>::recursivePrint(Node<T>* c) { //in order
  Node<T>* curr = c;

  if(curr != NULL) {
    recursivePrint(curr->left);
    cout << curr->data << endl;
    recursivePrint(curr->right);
  }
}

template <class T>
void BST<T>::printTree() {
  recursivePrint(root);
}

#endif
