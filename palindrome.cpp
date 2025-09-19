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
using namespace std;

int main()
{
  //x = len(input)
  char str[80];
  cin >> str;
  for (int i = 0; i < 80; i++)
    {
      if (isalpha(str[i]) != 0)
	{
	  str[i].delete();
	}
    }
  cout << str << endl;
  //for i in range(x):
  ////str.strip()
  //for i in range(x);
  //strcmp
  return 0;
}
