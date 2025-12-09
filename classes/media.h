#include<iostream>
#include<cstring>
using namespace std;
class media
{
	private:
	char* title[80];
	int year;

	public:
	virtual ~media();
	
	//get methods
	char* gtitle();
	int gyear();
	//member function(s)
};
