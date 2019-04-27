#ifndef BST_H
#define BST_H

#include <iostream>

template <class T>
class Node {
public:
  //Node();
  Node(T d):data(d), parent(NULL), left(NULL), right(NULL) {};
  virtual ~Node();

  T data;
  Node *parent;
  Node *left;
  Node *right;
};

template <class T>
class BST {
public:
  BST();
  ~BST();

  //insert
  bool insert(T d);
  //getsuccessor
  //delete

  //helper methods
  bool isEmpty();
  void recursiveDelete(Node<T> *curr);
  //printTree
  bool contains(T d);

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
  std::cout << "Deleting the tree" << std::endl;
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
bool BST<T>::contains(T d) {
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
bool BST<T>::insert(T d) {
  if (contains(d))
    return false;

  Node<T> *newNode = new Node<T>(d);

  if(isEmpty()) {
    root = newNode;
    return true;
  }

  Node<T> *curr = root;
  Node<T> *parent;

  while(true) {
    parent = curr;
    if(d < curr->data) {
      curr = curr->left;
      if (curr == NULL)  {
        parent->left = newNode;
        return true;
      }
    }
    else {
      curr = curr->right;
      if(curr == NULL) {
        parent->right = newNode;
        return true;
      }
    }
  }


}

#endif
