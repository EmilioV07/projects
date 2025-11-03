/*
Emilio Vasquez-Pettit
10/14/2025

This program

Citations:
1. MS copilot
used for documentation and explaining c++ concepts & syntax
2. 

*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct stdt
  {
    char firstname[81] = {'\0'};
    char lastname[81] = {'\0'};
    int id;
    float gpa;
};

int addstdt()
{
  bool inputting = true;
  while (inputting)
    {
      char answer = '\0';
      char firstname[81] = {'\0'};
      char lastname[81] = {'\0'};
      int id;
      float gpa;
      cout << "Enter the student's first name: ";
      cin >> firstname;
      cout << endl;
      cout << "Enter the student's last name: ";
      cin >> lastname;
      cout << endl;
      cout << "Enter the student's identification number: ";
      cin >> id;
      cout << endl;
      cout << "Enter the student's grade point average (GPA): ";
      cin >> gpa;
      cout << endl;
      cout << "Name: " << firstname << " " << lastname << endl;
      cout << "ID: " << id << endl;
      cout << "GPA: " << gpa << endl;
      cout << endl;
      cout << "Is this information correct? (y/n): ";
      if(cin >> answer && answer == 'y'){inputting=false;}
    }
//create a new student using information provided
//add student to vector list
  people.pushback({firstname, lastname, id, gpa});
  cout << people;
  return 0;
}

int main()
{
  bool inputting = true;
  while(inputting){addstdt();}
  return 0;
}

/*

Vector Syntax:

add v.push_back; (at end)
remove v.pop_back(); (last element)
access v[index] or v.at
size v.size() (returns number)
check emptiness v.empty(); (returns true)
clear elements v.clear(); (empties the vector)
insert at position v.insert(v.begin() + 2, 99); (inserts 99 at index 2)
erase element v.erase(v.begin() + 1); (removes at index 1)

*/
