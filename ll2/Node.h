#ifndef NODE_H
#define NODE_H
//Include the Student class
#include "Student.h"

#include <iostream>

using namespace std;

//Node class represents a single node in a linked list
class Node{
 public:
//Constructer
  Node(Student* newStudent);
//Destructer
  ~Node();
//Returns pointer to the next node
  Node* getNext();
//Returns a pointer to the student stored in this node
  Student* getStudent();
//Set the pointer to the next pointer in the list
  void setNext(Node* newNext);
  
 private:
  Student* student;
  Node* next;
};

#endif
