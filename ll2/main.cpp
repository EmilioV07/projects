#include<iostream>
#include<cstring>
#include"Node.h"
#include"Student.h"
using namespace std;
/*
PRINT prints name id and gpa
ADD adds a student to the list with a corresponding node | PROMPT FIRST LAST ID GPA, SORT LEAST TO GREASTEST ID NUMBER, RECURSION
DELETE deletes a student and node from the list
CARE FOR EMPTY LIST
*/
void printAll(Node* current){//to have head inputted
	if(current->getNext()==nullptr){
		current->getStudent()->print();//prints last element
		return;
	}
	else if(current->getNext()!=nullptr){
		current->getStudent()->print();
		printAll(current->getNext());
	}
}
void addStudent(Node*& h, Node* current, char _firstname[32], char _lastname[32], int _id, float _gpa){//ADDS STUDENT BASED ON ID NUMBER WITH INPUTS FOR NAMES ID AND GPA
	if(current == nullptr){//if the list is empty
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		h = n;
		cout<<"Student Added"<<endl;
	}
	else if(current->getStudent()->getID()==_id){
		cout<<"Error, no two students can have the same ID"<<endl;
		return;
	}
	else if(current->getStudent()->getID() < _id && current->getNext()==nullptr){//if current ID is smaller and there is no next
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		current->setNext(n);
		cout<<"Student Added"<<endl;
	}
	else if(current->getStudent()->getID() < _id && current->getNext()->getStudent()->getID() > _id){//if current ID is smaller and next ID is bigger
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		n->setNext(current->getNext());
		current->setNext(n);
		cout<<"Student Added"<<endl;
	}
	else if(current->getNext()==nullptr){
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		n->setNext(current->getNext());
		current->setNext(n);
		cout<<"Student Added"<<endl;
		//addStudent(h, current->getNext(), _firstname, _lastname, _id, _gpa)
	}
	else{
		
	}
}
void deleteStudent(Node*& h, Node* current, int target){//DELETES STUDENT, TAKES HEAD/CURRENT AND TARGET ID NUMBER
	if(current->getNext() != nullptr && current->getStudent()->getID()==target){//if item 1 is the target
		h = current->getNext();//move list head to next element
		delete current;//delete target
	}
	else if(current->getNext()!=nullptr && current->getStudent()->getID()!=target){//if the list goes on and the current is not the target
		deleteStudent(h, current->getNext(), target);//recurse to next student
	}
	else if(current->getNext()->getStudent()->getID()==target){//if the next student in the list is the target
		current->setNext(current->getNext()->getNext);//set current next to student after next (next is target), stitches list
		delete current->getNext();//delete the next student
	}
}

int main()
{
	//object creation
	char input[10];
	Node* h = nullptr;
	bool working = true;
	while(working){
		cout<<"Enter an operation (ADD, DELETE, PRINT, QUIT): ";cin>>input;cout<<endl;
		if(strcmp(input,"ADD")==0){
			char _firstname[32];
			char _lastname[32];
			int _id;
			float _gpa;
			cout<<"Enter the student's first name: ";cin>>_firstname;cout<<endl;
			cout<<"Enter the student's last name: ";cin>>_lastname;cout<<endl;
			cout<<"Enter the student's ID number: ";cin>>_id;cout<<endl;
			cout<<"Enter the student's GPA: ";cin>>_gpa;cout<<endl;
			addStudent(h, h, _firstname, _lastname, _id, _gpa);
		}
		else if(strcmp(input,"DELETE")==0){
			int target;
			cout<<"Enter a target ID number (6-digit): ";cin>>target;cout<<endl;
			deleteStudent(h, h, target);
		}
		else if(strcmp(input,"PRINT")==0){
			printAll(h);
		}
		else if(strcmp(input,"QUIT")==0){
			working = false;
		}
		else{
			cout<<"Invalid input, please try again"<<endl;
		}
	}
	//DELETE ALL | FREE MEMORY
	return 0;
}

