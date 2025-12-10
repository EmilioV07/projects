#include<media.h>
#include<iostream>
class vg : public media
{
	private:
	char* publisher;
	int rating;

	public:
	char gpublisher();
	int grating();
};
