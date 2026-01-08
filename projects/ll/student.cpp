#include<iostream>
#include<cstring>
#include"student.h"
using namespace std;
student::student(char* name)
{
	strcpy(name, fullname);
}
student::student(){delete name*;}

