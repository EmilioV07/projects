/*
Emilio Vasquez-Pettit
09/15/2025
Palindrome

This program reads a series of characters (max of 80), removes all punctuation and spaces, and returns whether or not the stripped input is a palindrome or not (same read backwards as forwards).

Citations:
1. W3 schools c++ for loop documentation
2. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>//CITE ZACH
using namespace std;

int main()
{
  char str[80] = "\0";
  char strpstr[80] = "\0";
  bool inputting = true;
  while (inputting == true)//GRABS & VALIDATES USER INPUT
    {
      cin >> str;
      if (strlen(str) > 80)
	{
	  cout << "Input too large, please stay under 80 characters";
	}
      else if (strlen(str) <= 80)
	{
	  inputting = false;
	}
    }
  int count = 0;//seperate count for adding to the strpstr array
  for (int i = 0; i < strlen(str); i++)//STRIPS/CLEANS INPUT
    {
      if (isalpha(str[i]) != 0)
	{
	  strpstr[count] = str[i];
	  count += 1;
	}
    }
  cout << strpstr << endl;
  
  //cout << reverse(strpstr)
  return 0;
}
