#ifndef MS_H
#define MS_H
#include"media.h"
#include<iostream>
class ms : public media
{
	private:
	char* title;
	char* artist;
	char* publisher;
	int year;
	int duration;

	public:
	char* gpublisher();
	int gduration();
	//int gyear();
	char* gartist();
	//char* gtitle();
	ms(char* _title, char* _artist, int _year, int _duration, char* _publisher);
	virtual ~ms();
};
#endif
