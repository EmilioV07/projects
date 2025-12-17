#ifndef MV_H
#define MV_H
#include"media.h"
#include<iostream>
class mv : public media
{
	private:
	char* director;
	int rating;
	int duration;

	public:
	char* gdirector();
	int grating();
	int gduration();
	mv(char* _title, int _year, char* director, int _duration, int _rating);
	virtual ~mv();
};
#endif
