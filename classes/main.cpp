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
int delete()
{
	
}
int main()
{
	while(inputting)
	{
		char op[10];
		cout<<"Enter an operation (ADD, SEARCH, DELETE): ";
		cin>>op;
		cout<<endl;
		if(strcmp(op, "ADD")==0){add();}
		else if(strcmp(op, "SEARCH")==0){search();}
		else if(strcmp(op, "DELETE")==0){delete();}
		else{cout<<"Input does not match any operation, try again."<<endl;}
				
	{
	return 0;
}
