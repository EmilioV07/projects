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
	if(current==nullptr){//stops when the end of the list is reaches
		cout<<"The list is currently empty"<<endl;
		return;
	}
	current->getStudent()->print();
	printAll(current->getNext());//recurses with next element
}
void addStudent(Node*& h, Node* current, char _firstname[32], char _lastname[32], int _id, float _gpa){//ADDS STUDENT BASED ON ID NUMBER WITH INPUTS FOR NAMES ID AND GPA
	if(current==nullptr){
		return;
	}
	if(h == nullptr || _id < h->getStudent()->getID()){//if the list is empty, add new element and set as head
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		n->setNext(h);
		h = n;
		cout<<"Student Added"<<endl;
		return;
	}
	if(current->getStudent()->getID()==_id){//if the added student has a duplicate id number
		cout<<"Students cannot share the same ID, please try again."<<endl;
		return;
	}
	if(current->getNext()==nullptr){//Add to end
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		current->setNext(n);
		cout<<"Student Added"<<endl;
		return;
	}
	else if(current->getNext()->getStudent()->getID() > _id){//if next is larger (previous checks make valid, finds first element that has next as larger and stitches in before)
		Student* s = new Student(_firstname, _lastname, _id, _gpa);
		Node* n = new Node(s);
		n->setNext(current->getNext());
		current->setNext(n);
		cout<<"Student Added"<<endl;
		return;
	}
	addStudent(h,current->getNext(),_firstname,_lastname,_id,_gpa);
}
void deleteStudent(Node*& h, Node* current, int target){//DELETES STUDENT, TAKES HEAD/CURRENT AND TARGET ID NUMBER
	if(current==nullptr){//if the student was not found (current checked by now)
		cout<<"No matching ID in list, please try again."<<endl;
		return;
	}
	if(h==nullptr){
		cout<<"List is empty."<<endl;
		return;
	}
	if(current==h && current->getStudent()->getID()==target){//head deletion
		Node* t = h;
		h = h->getNext();
		delete t;
		cout<<"Student Deleted"<<endl;
		return;
	}
	if(current->getNext()==nullptr){
		cout<<"No matching ID in list, please try again."<<endl;
		return;
	}
	if(current->getNext()->getStudent()->getID()==target){//if the next student is the delete target
		Node* t = current->getNext();
		current->setNext(t->getNext());
		delete t;
		cout<<"Student Deleted"<<endl;
		return;
	}
	deleteStudent(h, current->getNext(), target);
	/*
	Old logic spaghetti
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
	*/
}

void clearMemory(Node* current){
	if(current==nullptr){
		return;
	}
	clearMemory(current->getNext());
	//delete current->getStudent();
	delete current;//recursively frees memory
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
	clearMemory(h);
	return 0;
}

