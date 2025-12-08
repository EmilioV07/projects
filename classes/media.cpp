#include<iostream>
#include<cstring>
#include "media.h"
using namespace std;

media::media()//constructor
{
	title = new char[80];
	year = 0;
}
char media::gtitle()
{
	return title;
}
int media::gyear()
{
	return year;
}
/*
media::~media()//destructor
{
	//delete title;
	//delete year;?
}
*/
