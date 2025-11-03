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
#include <vector>

using namespace std;

struct stdt
  {
    char firstname[81] = {'\0'};
    char lastname[81] = {'\0'};
    int id;
    float gpa;
};

stdt addstdt(vector<stdt>& students)
{
  bool inputting = true;
  while (inputting)
    {
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
      stdt s;
    }
//create a new student using information provided
//add student to vector list
  //students.push_back({stdt.firstname, stdt.lastname, stdt.id, stdt.gpa});
  //cout << students;
  s.firstname = firstname;
  s.lastname = lastname;
  s.id = id;
  s.gpa = gpa;
  students.push_back(s)
  return s;
}

int removestdt(vector<stdt>& students)
{
  return 0;
}

int main()
{
  bool inputting2 = true;
  char answer2[10] = '\0';
  vector<stdt> students = {};
  while(inputting2)
    {
      cout << "Enter operation (add, remove, quit): " << endl;
      cin >> answer2;
      if(answer2[1] == 'a'){addstdt(vector<stdt>& students);}
      else if(answer2[1] == 'r'){removestdt();}
      else if(answer2[1] == 'q'){inputting2 = false;}
      else{cout << "Enter a valid operation" << endl;}
    }
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
