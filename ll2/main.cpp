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
Node* printAll(Node* current){//to have head inputted
	if(current->getNext()!=nullptr){
		current->getStudent()->print();
		cycle(current->getNext())
	}
	else if(current->getNext()==nullptr){
		return current;//returns last element
	}
}
void addStudent(Node* current, char _firstname[32], char _lastname[32], int _id, float _gpa){//ADDS STUDENT BASED ON ID NUMBER WITH INPUTS FOR NAMES ID AND GPA
	if(current->getStudent()->getID() > ){//CURRENT==NULL CASE FOR IF LIST IS EMPTY OR AT START
		
		Student* newStudent = Student(_firstname, _lastname, _id, _gpa);
		Node* n = Node(newStudent);
	}
	else if(current->getNext()!=nullptr){
		add(current->next())
	}
}
void deleteStudent(Node* current, int target){//DELETES STUDENT, TAKES HEAD/CURRENT AND TARGET ID NUMBER
	if(current->getNext()!=nullptr && current->getStudent()->getID()!=target){
		deleteStudent(current->getNext())
	}
	else if(current->getNext()->getStudent()->getID()==target){
		current->setNext(current->getNext()->getNext);
		delete current->getNext();
	}
}
void print(Node* current){//to have head inputted
	if(current->getNext()!=nullptr)[
		current->getStudent()->print();
		cycle(current->getNext())
	}
	else if(current->getNext()==nullptr){
		current->getStudent()->print();
		return current;//returns last element
	}
}

int main()
{
	//object creation
	Node* node1 = Node()
	char input[10];
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
			addStudent()
		}
		else if(strcmp(input,"DELETE")==0){
			
		}
		else if(strcmp(input,"PRINT")==0){
			
		}
		else if(strcmp(input,"QUIT")==0){
			
		}
		else{
			cout<<"Invalid input, please try again"<<endl;
		}
		return 0;
	}
}
