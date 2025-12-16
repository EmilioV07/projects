/*
Emilio Vasquez-Pettit

This program runs a digital media database where the user can ADD, DELETE, and SEARCH for items in said database.

Considering child classes/files are so similar in structure, practically duplicates, most commenting will be found in
media.h/.cpp and vg.h/.cpp
g
citations:

1. Dylan Waters
helped with class structure/syntax and file system (what needed to be included where)
2. Bradley Fusselman
provided sample code (beyond my comprehension) and lessons on constructors & destructors
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<limits>
#include<typeinfo>
#include"media.h"
#include"vg.h"
#include"mv.h"
#include"ms.h"
using namespace  std;
int add(vector<media*>& medialist)//add vector passed by reference (original modification) to add media to
{
	bool live = true;
	while(live)
	{
		char type[80];//universal attribute declarations
		char title[80];
		int year;
		cout<<"Media type (videogame, movie, music): ";//universal attributes gathering and assignment
		cin.getline(type, 80);
		cout<<endl;
		cout<<"Media title: ";
		cin.getline(title, 80);
		cout<<endl;
		cout<<"Media year: ";
		cin>>year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//copilot debug for removing newline from buffer after numeric input
		cout<<endl;
		//individual add operations for different media types
		if(strcmp(type, "videogame")==0)//checks command
		{
			char publisher[80];//declarations of local media attributes
			int rating;
			cout<<"Publisher: ";//gathering and assigning of local media attributes
			cin.getline(publisher, 80);
			cout<<endl;
			cout<<"Rating: ";
			cin>>rating;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<endl;
			media* newvg = new vg(title, year, publisher, rating);//creates object on the memory and assigns pointer
			medialist.push_back(newvg);//adds object pointer to the media list/vector
			live=false;//terminates loop
		}
		else if(strcmp(type, "movie")==0)//done before movie files, will not work w/o them
		{
			char director[80];
			int duration;
			int rating;
			cout<<"Director: ";
			cin.getline(director, 80);
			cout<<endl;
			cout<<"Duration (minutes): ";
			cin>>duration;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<endl;
			cout<<"Rating: ";
			cin>>rating;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<endl;
			media* newmv = new mv(title, year, director, duration, rating);
			medialist.push_back(newmv);
			live=false;
		}
		else if(strcmp(type, "music")==0)
		{
			char artist[80];
			char publisher[80];
			int duration;
			cout<<"Artist: ";
			cin.getline(artist, 80);
			cout<<endl;
			cout<<"Publisher: ";
			cin.getline(publisher,80);
			cout<<endl;
			cout<<"Duration (minutes): ";
			cin>>duration;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<endl;
			media* newms = new ms(title, artist, year, duration, publisher);
			medialist.push_back(newms);
			live=false;
		}
		else{cout<<"Invalid information, please try again"<<endl;}
	}
	return 0;
}
int search(vector<media*>& medialist)//search function
{
	char type[80];//search type (title/year)
	char title[80];
	int year;
	cout<<"Search by title or year?: ";
	cin.getline(type, 80);
	cout<<endl;
	if(strcmp(type, "title")==0)
	{
		cout<<"Title: ";
		cin.getline(title, 80);
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given title
		{
			if(strcmp(title, media->gtitle())==0)//checks title match
			{
				//uses dynamic cast to check media type and print details accordingly
				if(auto vgo = dynamic_cast<vg*>(media)){cout<<" Title: "<<vgo->gtitle()<<" Year: "<<vgo->gyear()<<" Publisher: "<<vgo->gpublisher()<<" Rating: "<<vgo->grating()<<endl;}
				else if(auto mso = dynamic_cast<ms*>(media)){cout<<" Title: "<<mso->gtitle()<<" Artist: "<<mso->gartist()<<" Year: "<<mso->gyear()<<" Duration: "<<mso->gduration()<<" Publisher: "<<mso->gpublisher()<<endl;}
				else if(auto mvo = dynamic_cast<mv*>(media)){cout<<" Title: "<<mvo->gtitle()<<" Year: "<<mvo->gyear()<<" Director: "<<mvo->gdirector()<<" Duration: "<<mvo->gduration()<<" Rating: "<<mvo->grating()<<endl;}
			}
		}
	}
	else if(strcmp(type, "year")==0)
	{
		cout<<"Year: ";
		cin>>year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given year
		{
			if(media->gyear()==year)//checks year match
			{
				//uses dynamic cast to check media type and print details accordingly
				if(auto vgo = dynamic_cast<vg*>(media)){cout<<" Title: "<<vgo->gtitle()<<" Year: "<<vgo->gyear()<<" Publisher: "<<vgo->gpublisher()<<" Rating: "<<vgo->grating()<<endl;}
				else if(auto mso = dynamic_cast<ms*>(media)){cout<<" Title: "<<mso->gtitle()<<" Artist: "<<mso->gartist()<<" Year: "<<mso->gyear()<<" Duration: "<<mso->gduration()<<" Publisher: "<<mso->gpublisher()<<endl;}
				else if(auto mvo = dynamic_cast<mv*>(media)){cout<<" Title: "<<mvo->gtitle()<<" Year: "<<mvo->gyear()<<" Director: "<<mvo->gdirector()<<" Duration: "<<mvo->gduration()<<" Rating: "<<mvo->grating()<<endl;}
			}
		}
	}
	return 0;//use for conditional if none are found (ex Sorry, no item matched your search)
}
int dl(vector<media*>& medialist)
{
	vector<int> dls;//vector holding medialist indices to delete
	char type[80];
	char title[80];
	int year;
	int count=0;//stores index to save to delete list (resets every delete call)
	char ans;
	cout<<"Delete by title or year?: ";
	cin.getline(type, 80);
	cout<<endl;
	if(strcmp(type, "title")==0)
	{
		cout<<"Title: ";
		cin.getline(title, 80);
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given title
		{
			
			if(strcmp(title, media->gtitle())==0)//checks title match
			{
				//uses dynamic cast to check media type and print details accordingly
				if(auto vgo = dynamic_cast<vg*>(media)){cout<<" Title: "<<vgo->gtitle()<<" Year: "<<vgo->gyear()<<" Publisher: "<<vgo->gpublisher()<<" Rating: "<<vgo->grating()<<endl;}
				else if(auto mso = dynamic_cast<ms*>(media)){cout<<" Title: "<<mso->gtitle()<<" Artist: "<<mso->gartist()<<" Year: "<<mso->gyear()<<" Duration: "<<mso->gduration()<<" Publisher: "<<mso->gpublisher()<<endl;}
				else if(auto mvo = dynamic_cast<mv*>(media)){cout<<" Title: "<<mvo->gtitle()<<" Year: "<<mvo->gyear()<<" Director: "<<mvo->gdirector()<<" Duration: "<<mvo->gduration()<<" Rating: "<<mvo->grating()<<endl;}
				dls.push_back(count);//adds found index to delete list
			}
			count++;//increases count for next iteration
		}
	}
	else if(strcmp(type, "year")==0)
	{
		cout<<"Year: ";
		cin>>year;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given year
		{
			if(media->gyear()==year)//checks year match
			{
				//uses dynamic cast to check media type and print details accordingly
				if(auto vgo = dynamic_cast<vg*>(media)){cout<<" Title: "<<vgo->gtitle()<<" Year: "<<vgo->gyear()<<" Publisher: "<<vgo->gpublisher()<<" Rating: "<<vgo->grating()<<endl;}
				else if(auto mso = dynamic_cast<ms*>(media)){cout<<" Title: "<<mso->gtitle()<<" Artist: "<<mso->gartist()<<" Year: "<<mso->gyear()<<" Duration: "<<mso->gduration()<<" Publisher: "<<mso->gpublisher()<<endl;}
				else if(auto mvo = dynamic_cast<mv*>(media)){cout<<" Title: "<<mvo->gtitle()<<" Year: "<<mvo->gyear()<<" Director: "<<mvo->gdirector()<<" Duration: "<<mvo->gduration()<<" Rating: "<<mvo->grating()<<endl;}
				dls.push_back(count);
			}
			count++;
		}
	}
	cout<<"Delete item(s)(y/n)?: ";
	cin>>ans;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<endl;
	if(ans=='y')
	{
		sort(dls.rbegin(), dls.rend());//copilot sorting and deleting by index method with stored indices-to-delete
		for(int i : dls)
		{
			delete medialist[i];//clears memory item
			medialist.erase(medialist.begin() + i);//clears vector position (sorted in opposite order to avound shifts)
		}
	}//delete items
	return 0;//if no, does not delete items
}
int main()
{
	vector<media*> medialist;//vector of media object pointers
	bool inputting=true;
	while(inputting)//input loop
	{
		char op[80];
		cout<<"Note: Use media title in SEARCH and DELETE operations."<<endl;
		cout<<"Enter an operation (ADD, SEARCH, DELETE, QUIT): ";
		cin.getline(op, 80);
		cout<<endl;
		if(strcmp(op, "ADD")==0){add(medialist);}
		else if(strcmp(op, "SEARCH")==0){search(medialist);}
		else if(strcmp(op, "DELETE")==0){dl(medialist);}
		else if(strcmp(op, "QUIT")==0){inputting=false;}
		else{cout<<"Input does not match any operation, try again."<<endl;}
	}
	for(media* i : medialist)
	{
		delete i;
	}
	medialist.clear();
	return 0;
}
