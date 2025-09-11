/*
Emilio Vasquez-Pettit
09/05/2025
Guessing Game

In this program, the computer chooses a random number in the range 0 - 100 inclusive, and the user has to guess the number in a series of attempts. The program will give feedback to the user regarding their guess being too high or too low, and tells the user if their guess is correct. If the user guesses correctly, they are prompted to play the game again with a new (hopefully) random number.

Citations:
1. friend: Dylan Waters, class: C++, Per. 1
Provided number randomization code.
2. All teacher help & Google Search AI provision of '\0' for setting char variables to nothing.
3. CodeHS Documentation used for syntax refresher.

3 RULES OF C++ CLASS
1. No global variables
2. No strings
3. Include <iostream> over stdio & use "new" and "delete" over "malloc" and "free"
I hope these are the three rules required.
*/
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

int Guessing()
  {
    int guess = 0;
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
  srand(time(NULL));
  int randnum = rand()%100;
  int turns = 0;
  bool guessright = false;
  char answer;
  
  while (guessright == false)
    {
      int guessnum = Guessing();
      if (100 < guessnum < 0)
	{
	  cout << "Number out of range, guess again.\n";
	  turns += 1;
	}
      else if (guessnum > randnum)
	{
	  cout << "Number too high, guess again\n";
	  turns += 1;
	}
      else if (guessnum < randnum)
	{
	  cout << "Number too low, guess again\n";
	  turns += 1;
	}
      else if (guessnum == randnum)
	{
	  cout << "You guessed correctly, you win!\n";
	  turns += 1;
	  cout << "You took " << turns << " turns.";
	  cout << "\nWould you like to play again? (y/n): ";
	  cin >> answer;
	  if (answer == 'y')
	    {
	      guessright = true;
	      answer = '\0';
	      turns = 0;
	      main();
	    }
	  else if (answer == 'n')
	    {
	      cout << "\nThanks for playing!";
	      guessright = true;
	    }
	}
    }
  return 0;
}
