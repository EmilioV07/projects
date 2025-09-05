/*
Emilio Vasquez-Pettit
09/05/2025
Citations:
1. 
*/
#include <iostream>
#include <random>
using namespace std;
int main()
{
  
  
  int number = 10;
  int turns;
  
  while (true)
    {
      int guess;
  while (true)
    {
      cout << "Enter a number from 0 to 100 inculsive: ";
      cin >> guess;
      if (100 < guess < 0)
	{
	  cout << "Number out of range, please choose a different number.";
	  continue;
	}
      
      cin >> guess;
      if (100 < guess < 0)
	{
	  cout << "Number out of range, guess again.";
	  turns += 1;
	  continue;
	}
      if (guess > number)
	{
	  cout << "Number too high, guess again";
	  turns += 1;
	  continue;
	}
      if (guess < number)
	{
	  cout << "Number too low, guess again";
	  turns += 1;
	  continue;
	}
      if (guess = number)
	{
	  cout << "You guessed correctly, you win!";
	  turns += 1;
	  cout << "You took " << turns << " turns.";
	  break;
	}
    }
  return 0;
}
