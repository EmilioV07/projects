#include<media.h>
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
};
