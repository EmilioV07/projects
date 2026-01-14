#include<iostream>
#include<cstring>
#include"student.h"
using namespace std;
student::student(const char* name)
{
	strcpy(fullname, name);
}
void student::print(){cout<<fullname<<endl;}
student::~student(){}

