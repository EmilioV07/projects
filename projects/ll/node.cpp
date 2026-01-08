#include<iostream>
#include<cstring>
#include"node.h"
using namespace std;
node::node(student* nstudent)
{
	student = nstudent;
	next = NULL;
}
node::~node(){delete student; next = NULL}
student* node::getstudent(){return student;}
void node::setnext(node* nnext){next=nnext}
