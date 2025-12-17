#ifndef VG_H
#define VG_H
#include"media.h"
#include<iostream>
class vg : public media
{
	private:
	char* publisher;
	int rating;

	public:
	char* gpublisher();
	int grating();
	vg(char* _title, int _year, char* _publisher, int _rating);
	virtual ~vg();
};
#endif
