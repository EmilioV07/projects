#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
 private:
	char firstname[80];
	char lastname[80];
	int id;
	float gpa;
 public:
 	Student(char _firstname, char _lastname, int _id, float _gpa);
 	int getID();
 	void print();
	~Student();
};
#endif
