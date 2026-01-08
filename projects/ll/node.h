#ifndef NODE_H
#define NODE_H
#include"student.h"
#include<iostream>
using namespace std;

class node
{
 private:
  student* student;
  node* next;
 public:
 void setvalue(newvalue);//sets node value to student
 student* getvalue();//gets the corresponding student for the current node
 void setnext(node* nnext);//sets pointer to next in chain
 node* getnext();//gets the next node in the chain
  node();//constructs node
  ~node();//destructor
};
#endif
