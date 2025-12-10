#include<iostream>
#include<cstring>
#include"media.h"
using namespace std;
media::media(char* _title, int _year)//constructor
{
	title = new char[strlen(_title)+1];//allocates memory for title
	strcpy(title, _title);//copies the input title into the new memory space
	year = _year;//sets default year value
}
//getter functions
char* media::gtitle(){return title;}
int media::gyear(){return year;}
media::~media(){delete[] title;}//destructor, frees up allocated memory
