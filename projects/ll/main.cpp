#include<iostream>
#include<cstring>
#include"node.h"
#include"student.h"
using namespace std;

void add(int newvalue);
void print(node* next);
int main()
{
	//object creation
	student* 1 = new student(30, "rick");
	student* 2 = new student(31, "frank");
	student* 3 = new student(32, "duke");
	//node creation
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);

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
