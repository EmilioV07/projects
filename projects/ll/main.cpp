#include<iostream>
#include<cstring>
#include"node.h"
#include"student.h"
using namespace std;

void add(int newvalue);
void print(node* next);
int main()
{
  
}
void add(int newvalue)
{
  node* current = head;
  if(current == NULL)
    {
      head = new node();
      head->setValu(newvalue);
    }
  else
    {
      while(current->getNext() != NULL)
        {
          current = current->getNext();
        }
      current->setNext(new node());
      current->getNext()->setValue(newvalue);
    }
}
void print(node* next)
{
	if(next==head)
	{
		cout << "list";
	}
	if(next!=Null)
	{
		cout<<next->getValue()<<" ";
		print(next->getNext());
	}
	else
	{
		//do nothing
	}
}
