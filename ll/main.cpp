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
	student* a = new student("rick");
	student* b = new student("frank");
	student* c = new student("duke");
	//node creation
	node* node1 = new node(a);
	node* node2 = new node(b);
	node* node3 = new node(c);
	//node linking
	node1->setnext(node2);
	node2->setnext(node3);
	//print checks
	cout<<"1: ";
	node1->getstudent()->print();
	cout<<"2: ";
	node2->getstudent()->print();//chases next student from node1
	cout<<"3: ";
	node3->getstudent()->print();
	node1->getnext()->getstudent()->print();//check to see if link works
	/*
	if(next!=Null)
	{
		cout<<next->getvalue()<<" ";
		print(next->getnext());
	}
	else
	{
		//do nothing
	}
	*/
	//wipe residual memory
	delete node1;
	delete node2;
	delete node3;
	delete a;
	delete b;
	delete c;
	return 0;
}
