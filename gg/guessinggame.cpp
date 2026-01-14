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
//namespace and inclusions for random, time, and quality of life
int Guessing()//guessing function that returns validated guess to main as "guessnum"
  {
    int guess = 0;//local guess variable to Guessing()
    bool guessvalid = false;
    while (guessvalid == false)//repeats validation procedure until conditional true and returns
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
  srand(time(NULL));//seeds random in the current time for certified random random every time
  int randnum = rand()%100;//random number to guess, mod 100 to keep in the 0-100 range
  int turns = 0;//variable to keep track of how many attempts were made
  bool guessright = false;//bool to end main game loop
  char answer;//stores answer to restart or end program/game
  
  while (guessright == false)//main game loop
    {
      int guessnum = Guessing();//grabs user input/guess
      if (100 < guessnum < 0)//conditionals return feedback to user on higher, lower, or win, which prompts a new game or to end the program
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
	  cin >> answer;//gets user preference
	  if (answer == 'y')
	    {
	      guessright = true;
	      answer = '\0';
	      turns = 0;//resets turns and answer so new game has fresh score and input
	      main();//restarts game
	    }
	  else if (answer == 'n')
	    {
	      cout << "\nThanks for playing!";
	      guessright = true;//ends game loop and thanks for playing
	    }
	}
    }
  return 0;
}
