#include<iostream>
#include<cstring>
#include"media.h"
#include"mv.h"

mv::mv(char* _title, int _year, char* _director, int _duration, int _rating) : media(_title, _year)//initializer list to let videogame inherit title & year
{
	director = new char[strlen(_director)+1];
	strcpy(director, _director);
	rating = _rating;
	duration = _duration;
}

char* mv::gdirector(){return director;}
int mv::gduration(){return duration;}
int mv::grating(){return rating;}
mv::~mv(){delete[] director;}
