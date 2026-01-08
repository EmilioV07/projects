#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class student
{
 private:
	char* name[];
 public:
 	student(char* name[80])
 	void print();
	~student();
};
