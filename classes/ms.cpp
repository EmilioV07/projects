#include<iostream>
#include<cstring>
#include"media.h"
#include"ms.h"

ms::ms(char* _title, char* _artist, int _year, int _duration, char* _publisher) : media(_title, _year)//initializer list to let videogame inherit title & year
{
	publisher = new char[strlen(_publisher)+1];//allocates appropriate memory to store publisher
	strcpy(publisher, _publisher);//copies publisher characters to new memory
	artist = new char[strlen(_artist)+1];
	strcpy(artist, _artist);
	duration = _duration;
}

char* ms::gpublisher(){return publisher;}
char* ms::gartist(){return artist;}
int ms::gduration(){return duration;}
ms::~ms()
{
	delete[] publisher;
	delete[] artist;
	delete[] title;
}

