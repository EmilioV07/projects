#ifndef MEDIA
#define MEDIA
#include<iostream>
#include<cstring>
using namespace std;
class media
{
	private:
	char* title;
	int year;

	public:
	char* gtitle();
	int gyear();
	media(char* _title, int _year);
	virtual ~media();
};
#endif
