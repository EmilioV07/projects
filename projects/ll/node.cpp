#include<iostream>
#include<cstring>
#include"node.h"
using namespace std;
node::node()
{
	delete &value;
	next = NULL;
}
node::~node(){delete //item;}
