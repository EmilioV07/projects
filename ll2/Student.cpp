#include<iostream>
#include<cstring>
#include"Student.h"
using namespace std;
Student::Student(char _firstname, char _lastname, int _id, float _gpa)
{
	strcpy(_firstname, firstname);
	strcpy(_lastname, lastname);
	id = _id;
	gpa = _gpa;
}
void Student::print(){cout<<"Name: "firstname<<" "<<lastname<<" ID: "<<id<<" GPA: "<<gpa<<endl;}
int Student::getID(){return id;}
Student::~Student(){}

