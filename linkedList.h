/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#pragma once
#include <ostream>
using namespace std;

template<typename T>
struct Node {
  T data;
  Node* nextPtr;
};

template<typename T>
class LinkedList {
protected:
  Node<T>* headPtr;
  Node<T>* tailPtr;
public:
  // constructor and destructor
  LinkedList();
  ~LinkedList();

  // class functions
  void addNode(T data);
  void delNode(int ID);
  void printList(ostream& os) const;
  void printList(ostream& os, char key) const;
  bool isEmpty() const;
  bool matchingNodesExist(char key) const;
  T findNode(int ID) const;
};

// constructor
template<typename T>
LinkedList<T>::LinkedList() {
  headPtr = nullptr;
  tailPtr = nullptr;
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* delPtr;

  // deletes each node starting with head node
  while (headPtr != nullptr) {
    delPtr = headPtr;
    headPtr = headPtr->nextPtr;
    delete delPtr;
    delPtr = nullptr;
  }
  
  tailPtr = nullptr;
}

template<typename T>
void LinkedList<T>::addNode(T data) {
  // creates new node and sets values
  Node<T>* newNode = new Node<T>;
  newNode->data = data;
  newNode->nextPtr = nullptr;

  // list is empty
  if (headPtr == nullptr) {
    headPtr = newNode;
    tailPtr = newNode;
  }
  // list is not empty
  else {
    // new node's lastName value is less than head node's lastName value
    if (newNode->data.getLastName() < headPtr->data.getLastName()) {
      // adds new node to start of list
      newNode->nextPtr = headPtr;
      headPtr = newNode;
    }
    // new node's lastName value is not less than head node's lastName value
    else {
      Node<T>* tempPtr = headPtr;
      
      while ((tempPtr->nextPtr != nullptr) && (tempPtr->nextPtr->data.getLastName() < newNode->data.getLastName())) {
        tempPtr = tempPtr->nextPtr;
      }

      // adds new node to list
      newNode->nextPtr = tempPtr->nextPtr;
      tempPtr->nextPtr = newNode;

      if (tempPtr == tailPtr)
        tailPtr = newNode;
    }
  }
}

template <typename T>
void LinkedList<T>::delNode(int ID) {
  Node<T>* tempPtr = headPtr;
  Node<T>* delPtr;

  // head node's IDNumber equals ID
  if (tempPtr->data.getIDNumber() == ID) {
    // delete head node
    delPtr = tempPtr;
    headPtr = headPtr->nextPtr;
    delete delPtr;
    delPtr = nullptr;
  }
  // head node's IDNumber does not equal ID
  else {
    while ((tempPtr->nextPtr != nullptr) && (tempPtr->nextPtr->data.getIDNumber() != ID)) {
      tempPtr= tempPtr->nextPtr;
    }

    // current node's ID number equals ID
    if (tempPtr->nextPtr != nullptr && tempPtr->nextPtr->data.getIDNumber() == ID) {
      // delete node
      delPtr = tempPtr->nextPtr;
      tempPtr->nextPtr = delPtr->nextPtr;

      if (tempPtr->nextPtr == nullptr) {    
        tailPtr = tempPtr;
      }
      
      delete delPtr;
      delPtr = nullptr;
    }
  }
}

template<typename T>
void LinkedList<T>::printList(ostream& os) const {
  Node<T>* tempPtr = headPtr;
  
  // list is empty
  if (tempPtr == nullptr) {
    os << "List is empty." << endl;
  }
  // list is not empty
  else {
    headPtr->data.printHeader(os);
    
    // iterates through nodes and outputs each node's data
    while (tempPtr != nullptr) {
      tempPtr->data.print(os);
      tempPtr = tempPtr->nextPtr;
    }
  }
}

template<typename T>
void LinkedList<T>::printList(ostream& os, char key) const {
  Node<T>* tempPtr = headPtr;
  
  // list is empty
  if (tempPtr == nullptr){
    os << "List is empty." << endl;
  }
  // list is not empty
  else {
    headPtr->data.printHeader(os);
    
    // iterates through nodes
    while (tempPtr != nullptr) {
      // outputs data of nodes whose lastName value starts with key
      if (tempPtr->data.getLastName().at(0) == key) {
        tempPtr->data.print(os);
      }
      
      tempPtr = tempPtr->nextPtr;
    }
  }
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
  return (headPtr == nullptr);
}

template <typename T>
bool LinkedList<T>::matchingNodesExist(char key) const {
  Node<T>* tempPtr = headPtr;

  // searches for node whose lastName value starts with key
  while (tempPtr != nullptr) {
    if (tempPtr->data.getLastName().at(0) == key) {
      return true;
    }
    
    tempPtr = tempPtr->nextPtr;
  }
  
  return false;
}

template <typename T>
T LinkedList<T>::findNode(int ID) const {
  T tempData;
  Node<T>* tempPtr = headPtr;

  // searches for node whose IDNumber value equals ID
  while (tempPtr != nullptr) {
    if (tempPtr->data.getIDNumber() == ID) {
      tempData = tempPtr->data;
    }
    
    tempPtr = tempPtr->nextPtr;
  }

  return tempData;
}