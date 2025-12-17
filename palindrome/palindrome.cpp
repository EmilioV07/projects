/*
Emilio Vasquez-Pettit
09/15/2025
Palindrome

This program reads a series of characters (max of 80), removes all punctuation and spaces, and returns whether or not the stripped input is a palindrome or not (same read backwards as forwards).

Citations:
1. W3 schools c++ for loop documentation
2. Classmate: Zach Tobin, class: C++ Programming DC Per. 1
<algorithm> for reversing string
3. Microsoft Copilot
documentation for strcpy, reverse() syntax, and typo pointouts not mentioned in compiler as error (ex accidental str instead of strpstr)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
  char str[81] = "\0";
  char strpstr[81] = "\0";
  char rvrsstr[81] = "\0";
  bool inputting = true;
  while (inputting == true)//GRABS & VALIDATES USER INPUT
    {
      cin >> str;
      if (strlen(str) <= 81)
	{
	  inputting = false;
	}
      else if (strlen(str) > 81)
	{
	  cout << "Input too large, please stay under 80 characters" << endl;
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

  for (int i = 0; i < strlen(str); i++)//makes stripped input all lowercase for comparison
    {
      strpstr[i] = tolower(strpstr[i]);
    }
  
  strcpy(rvrsstr, strpstr);//copies stripped input into new array to be reversed and compared
  reverse(rvrsstr, rvrsstr + strlen(rvrsstr));//reverses copied array for comparison 

  if (strcmp(strpstr, rvrsstr) == 0)//compares strings and lets the user know whether or not the input is a palindrome
    {
      cout << rvrsstr << endl;
      cout << "Palindrome" << endl;
    }
  else if (strcmp(strpstr, rvrsstr) != 0)
    {
      cout << "Not a palindrome." << endl;
    }
  
  return 0;
}
