/*
Emilio Vasquez-Pettit
09/05/2025
Citations:
1. 
*/
#include <iostream>
#include <random>
using namespace std;

int Guessing()
  {
    int guess;
    bool guessvalid = false;
    while (guessvalid == false)
      {
	cout << "Enter an integer from 0 to 100 inculsive: ";
	cin >> guess;
	if (100 < guess < 0)
	  {
	    cout << "Number out of range, please choose a different number.\n";
	  }
	if (101 > guess > -1)
	  {
	    guessvalid = true;
	  }
      }
    return guess;
  }

int main()
{
  int randnum = 10;//make random later
  int turns;
  int guessnum = Guessing();
  bool guessright = false;
  
  while (guessright == false)
    {
      if (100 < guessnum < 0)
	{
	  cout << "Number out of range, guess again.\n";
	  turns += 1;
	  guessnum = Guessing();
	}
      if (guessnum > randnum)
	{
	  cout << "Number too high, guess again\n";
	  turns += 1;
	  guessnum = Guessing();
	}
      if (guessnum < randnum)
	{
	  cout << "Number too low, guess again\n";
	  turns += 1;
	  guessnum = Guessing();
	}
      if (guessnum == randnum)
	{
	  cout << "You guessed correctly, you win!\n";
	  turns += 1;
	  cout << "You took " << turns << " turns.";
	  guessright = true;
	}
    }
  return 0;
}
