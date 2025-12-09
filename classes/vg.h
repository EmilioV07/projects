#include<media.h>
class vg : public media
{
	private:
	char publisher[80];
	int rating;

	public:
	char gpublisher();
	int grating();
};
