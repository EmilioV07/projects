#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class student
{
 private:
	char fullname[80];
 public:
 	student(const char* name);
 	void print();
	~student();
};
#endif
