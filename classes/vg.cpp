#include<iostream>
#include<cstring>
#include"media.h"
#include"vg.h"

vg::vg(char* _title, int _year, char* _publisher, int _rating) : media(_title, _year)//initializer list to let videogame inherit title & year
{
	publisher = new char[strlen(_publisher)+1];//allocates appropriate memory to store publisher
	strcpy(publisher, _publisher);//copies publisher characters to new memory
	rating = _rating;//stores rating in object
}

char* vg::gpublisher(){return publisher;}
int vg::grating(){return rating;}
vg::~vg(){delete[] publisher;}
