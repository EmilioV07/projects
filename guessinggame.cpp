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
	    cout << "Number out of range, please choose a different number.";
	  }
	if (101 > guess > -1)
	  {
	    guessvalid = true;
	  }
      }
    return 0;
  }

int main()
{
  
  
  int number = 10;
  int turns;
  int guess;
  bool guessvalid = false;
  bool guessright = false;
  int guessing;
  
  while (guessright == false)
    {
      
      if (100 < guess < 0)
	{
	  cout << "Number out of range, guess again.";
	  turns += 1;
	  Guessing();
	}
      if (guess > number)
	{
	  cout << "Number too high, guess again";
	  turns += 1;
	  Guessing();
	}
      if (guess < number)
	{
	  cout << "Number too low, guess again";
	  turns += 1;
	  Guessing();
	}
      if (guess == number)
	{
	  cout << "You guessed correctly, you win!";
	  turns += 1;
	  cout << "You took " << turns << " turns.";
	  guessright = true;
	}
    }
  return 0;
}
