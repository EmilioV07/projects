#include<iostream>
#include<cstring>
#include"Student.h"
using namespace std;
Student::Student(const char* _firstname, const char* _lastname, int _id, float _gpa)
{
	strcpy(firstname, _firstname);
	strcpy(lastname, _lastname);
	id = _id;
	gpa = _gpa;
}
void Student::print(){cout<<"Name: "<<firstname<<" "<<lastname<<" ID: "<<id<<" GPA: "<<gpa<<endl;}
int Student::getID(){return id;}
Student::~Student(){}

