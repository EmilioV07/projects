/*
Emilio Vasquez-Pettit
10/14/2025

This program creates a vector list of students that can be added to ore removed from.
Student information includes their first and last name, id number, and gpa.
You can print out the entire student list or quit the program at any time.

Citations:
1. MS copilot
used for documentation and explaining c++ concepts & syntax
2. Dylan Waters
iterator and vector method syntax help

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

struct stdt//student struct declaration
  {
    char firstname[81] = {'\0'};
    char lastname[81] = {'\0'};
    int id;
    float gpa;
};

void addstdt(vector<stdt*>& students)//add a student by creating a new struct object and assigning elements, then pushing back into vector
{
  bool inputting = true;
  char answer;
  float gpa;
  stdt* student = new stdt;
  while (inputting)
    {
      cout << "Enter the student's first name: ";
      cin >> student->firstname;
      cout << endl;
      cout << "Enter the student's last name: ";
      cin >> student->lastname;
      cout << endl;
      cout << "Enter the student's identification number: ";
      cin >> student->id;
      cout << endl;
      cout << "Enter the student's grade point average (GPA): ";
      cin >> student->gpa;
      cout << endl;
      cout << "Name: " << student->firstname << " " << student->lastname << endl;
      cout << "ID: " << student->id << endl;
      cout << "GPA: " << fixed << setprecision(2) << student->gpa << endl;
      cout << endl;
      cout << "Is this information correct? (y/n): ";
      if(cin >> answer && answer == 'y'){inputting=false;}
      stdt s;
    }
//create a new student using information provided
//add student to vector list
  //students.push_back({stdt.firstname, stdt.lastname, stdt.id, stdt.gpa});
  //cout << students;
  students.push_back(student);
}

int removestdt(vector<stdt*>& students)//remove a student by id number, works by iterating through vector and checking if the student at i matches the input id
{
    int answer3;
    cout << "Who would you like to remove?(By ID): " << endl;
    cin >> answer3;
    cout << endl;
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i]->id == answer3)
            {
            cout << "Removed: " << students[i]->firstname << " " << students[i]->lastname << endl;
            students.erase(students.begin() + i);
        }
    }
    
    return 0;
}

int print(vector<stdt*>& students)//print out all students on the list by iterating through vector and outputting student data
{
    //iterator syntax aid from Dylan Waters
    for(const auto* student : students)
    {
        cout << "Name: " << student->firstname << " " << student->lastname << " " << "ID: " << student->id << " " << "GPA: " << student->gpa << endl;
    }
    return 0;
}

int main()//main loop with loop declarations and input loop
{
  bool inputting2 = true;
  char answer2[10] = {'\0'};
  vector<stdt*> students = {};
  while(inputting2)
    {
      cout << "Enter an operation (ADD, DELETE, PRINT, QUIT): " << endl;
      cin >> answer2;
      if(strcmp(answer2, "ADD") == 0){addstdt(students);}
      else if(strcmp(answer2, "DELETE") == 0){removestdt(students);}
      else if(strcmp(answer2, "QUIT") == 0){inputting2 = false;}
      else if(strcmp(answer2, "PRINT") == 0){print(students);}
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
