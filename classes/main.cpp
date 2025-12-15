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
		cin>>type;
		cout<<endl;
		cout<<"Media title: ";
		cin>>title;
		cout<<endl;
		cout<<"Media year: ";
		cin>>year;
		cout<<endl;
		//individual add operations for different media types
		if(strcmp(type, "videogame")==0)//checks command
		{
			char publisher[80];//declarations of local media attributes
			int rating;
			cout<<"Publisher: ";//gathering and assigning of local media attributes
			cin>>publisher;
			cout<<endl;
			cout<<"Rating: ";
			cin>>rating;
			cout<<endl;
			media* newvg = new vg(title, year, publisher, rating);//creates object on the memory and assigns pointer
			medialist.push_back(newvg);//adds object pointer to the media list/vector
			live=false;
		}
		else if(strcmp(type, "movie")==0)//done before movie files, will not work w/o them
		{
			char director[80];
			int duration;
			int rating;
			cout<<"Director: ";
			cin>>director;
			cout<<endl;
			cout<<"Duration (minutes): ";
			cin>>director;
			cout<<endl;
			cout<<"Rating: ";
			cin>>rating;
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
			cin>>artist;
			cout<<endl;
			cout<<"Publisher: ";
			cin>>publisher;
			cout<<endl;
			cout<<"Duration (minutes): ";
			cin>>duration;
			cout<<endl;
			media* newms = new ms(title, artist, year, duration, publisher);
			medialist.push_back(newms);
			live=false;
		}
		else{cout<<"Invalid information, please try again"<<endl;}
	}
	return 0;
}
int search(vector<media*>& medialist)
{
	char type[80];
	char title[80];
	int year;
	cout<<"Search by title or year?: ";
	cin>>type;
	cout<<endl;
	if(strcmp(type, "title")==0)
	{
		cout<<"Title: ";
		cin>>title;
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given title
		{
			if(strcmp(title, media->gtitle())==0)//checks title match
			{
				cout<<"Title: "<<title<<" "<<"Year: "<<media->gyear()<<endl;
			}
		}
	}
	else if(strcmp(type, "year")==0)
	{
		cout<<"Year: ";
		cin>>year;
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given year
		{
			if(media->gyear()==year)//checks year match
			{
				cout<<"Year: "<<year<<" "<<"Title: "<<media->gtitle()<<endl;;
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
	int count=0;
	char ans;
	cout<<"Delete by title or year?: ";
	cin>>type;
	cout<<endl;
	if(strcmp(type, "title")==0)
	{
		cout<<"Title: ";
		cin>>title;
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given title
		{
			
			if(strcmp(title, media->gtitle())==0)//checks title match
			{
				cout<<"Title: "<<title<<" "<<"Year: "<<media->gyear()<<endl;
				dls.push_back(count);
			}
			count++;
		}
	}
	else if(strcmp(type, "year")==0)
	{
		cout<<"Year: ";
		cin>>year;
		cout<<endl;
		for(media* media : medialist)//iterator to look through medialist for media with given year
		{
			if(media->gyear()==year)//checks year match
			{
				cout<<"Year: "<<year<<" "<<"Title: "<<media->gtitle()<<endl;
				dls.push_back(count);
			}
			count++;
		}
	}
	cout<<"Delete item(s)(y/n)?: ";
	cin>>ans;
	cout<<endl;
	if(ans=='y')
	{
		sort(dls.rbegin(), dls.rend());//copilot sorting and deleting by index method with stored indices-to-delete
		for(int i : dls)
		{
			delete medialist[i];
			medialist.erase(medialist.begin() + i);
		}
	}//delete items
	return 0;//if no, does not delete items
}
int main()
{
	vector<media*> medialist;//vector of media object pointers
	bool inputting=true;
	while(inputting)
	{
		char op[12];
		cout<<"Note: Use media title in SEARCH and DELETE operations."<<endl;
		cout<<"Enter an operation (ADD, SEARCH, DELETE, QUIT): ";
		cin>>op;
		cout<<endl;
		if(strcmp(op, "ADD")==0){add(medialist);}
		else if(strcmp(op, "SEARCH")==0){search(medialist);}
		else if(strcmp(op, "DELETE")==0){dl(medialist);}
		else if(strcmp(op, "QUIT")==0){inputting=false;}
		else{cout<<"Input does not match any operation, try again."<<endl;}
	}
	return 0;
}

