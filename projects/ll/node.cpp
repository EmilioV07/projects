#include<iostream>
#include<cstring>
#include"node.h"
using namespace std;
node::node(student* nstudent)
{
	stdt = nstudent;
	next = NULL;
}
node::~node(){}//destructor
student* node::getstudent(){return stdt;}
node* node::getnext(){return next;}
void node::setnext(node* nnext){next=nnext;}
