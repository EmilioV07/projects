/*
Emilio Vasquez-Pettit

This program runs a digital media database where the user can ADD, DELETE, and SEARCH for items in said database.

Considering child classes/files are so similar in structure, practically duplicates, most commenting will be found in
media.h/.cpp and vg.h/.cpp

citations:

1. Dylan Waters
helped with class structure/syntax and file system (what needed to be included where)
2. Bradley Fusselman
provided sample code (beyond my comprehension) and lessons on constructors & destructors
*/
#include<iostream>
#include<cstring>
#include"media.h"
#include<vector>
using namespace  std;
int add()
{
	
}
int search()
{
	
}
int dl()
{
	
}
int main()
{
	vector<media*> medialist;//vector of media pointers
	while(inputting)
	{
		char op[10];
		cout<<"Enter an operation (ADD, SEARCH, DELETE): ";
		cin>>op;
		cout<<endl;
		if(strcmp(op, "ADD")==0){add();}
		else if(strcmp(op, "SEARCH")==0){search();}
		else if(strcmp(op, "DELETE")==0){dl();}
		else{cout<<"Input does not match any operation, try again."<<endl;}
				
	{
	return 0;
}
