/*
Emilio Vasquez-Pettit
10/02/2025

This program runs a two player game of TicTacToe in the console and keeps the score between X and O.

Citations:
1. MS Copilot
Proper syntax reference and scoping information for variables (program practically translated from AI TicTacToe assignment)
2. Existing Personal Work
Heavy logical inspiration from my own existing TicTacToe assignments (for Python and AI)
*/
#include <iostream>
#include <cstring>

using namespace std;

bool checkwin(char (&board)[3][3], int &scorex, int &scoreo)//win detection, iterates through rows and columns, then checks both diagonals manually
{
  //check horizontals and verticals
  for (int i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
	{
	  if (board[i][0] == 'X')
	    {
	      cout << "X wins!";
	      scorex +=1;
	      return true;
	    }
	  else if (board[i][0] == 'O')
	    {
	      cout << "O wins!" << endl;
	      scoreo += 1;
	      return true;
	    }
	}
      else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
	{
	  if (board[0][i] == 'X')
            {
              cout << "X wins!";
              scorex +=1;
              return true;
            }
          else if (board[0][i] == 'O')
            {
              cout << "O wins!" << endl;
              scoreo += 1;
              return true;
            }

	}
    }
  //check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board [0][0] != '-')
    {
      cout << board[0][0] << " wins!" << endl;
      return true;
    }
  else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board [0][2] != '-')
    {
      cout << board[0][2] << " wins!" << endl;
      return true;
    }
  //check tie
  return false;
}
int printboard(char (&board)[3][3], int &turn, int &scorex, int &scoreo)
  {
    cout << "Score: X:" << scorex << " O:" << scoreo << endl;
    cout << endl;
    if (turn == 1)
      {
	cout << "X's turn" << endl;
      }
    else if (turn == -1)
      {
	cout << "O's turn" << endl;
      }
    cout << "  " << "0" << " " << "1" << " " << "2" << endl;
    for (int i = 0; i < 3; i++)
      {
	cout << i << " " << board[i][0] << " " << board[i][1] << " " << board[i][2] << endl;
      }
    return 0;
  }

bool isvalidmove(char (&board)[3][3], int row, int col)//checks if the player's move choice is valid (not overwriting an existing move of either player)
{
  if (row >= 0 && row <= 2 && col >=0 && col <= 2 && board[row][col] == '-')//range check
    {
      return true;
    }
  else
    {
      return false;
    }
}
//places player mark on the board
int placeplayer(char (&board)[3][3], int row, int col, int &turn)
{
  if (turn == -1)
    {
      board[row][col] = 'O';
    }
  else if (turn == 1)
    {
      board[row][col] = 'X';
    }
  return 0;
}

int taketurn(char (&board)[3][3], int &turn, bool &winner, bool &playing, int &scorex, int &scoreo)
{ 
  while (playing == true)
    {
      int row, col;
      cout << "Enter a row (0, 1, 2): " << endl;
      cin >> row;
      cout << "Enter a column (0, 1, 2): " << endl;
      cin >> col;
      if (isvalidmove(board, row, col) == true)
        {
          placeplayer(board, row, col, turn);
	  turn = turn * -1;//goes before printboard() so that the board is printed with the correct player's turn
          printboard(board, turn, scorex, scoreo);
	  if (checkwin(board, scorex, scoreo) == true)
	    {
	      winner = true;
	      playing = false;
	    }
        }
      else
	{
	  cout << "That spot has been marked or is out of range, choose another spot" << endl;
	}
    }
  cout << "Would you like to play again?(y/n): " << endl;
  char ans;
  cin >> ans;
  if (ans == 'y')
    {
      turn = 1;
      winner = false;
      playing = true;
      //clears the board
      for (int i = 0; i < 3; i++)
	{
	  for (int j = 0; j < 3; j++)
	    {
	      board[i][j] = '-';
	    }
	}
      printboard(board, turn, scorex, scoreo);
      taketurn(board, turn, winner, playing, scorex, scoreo);
    }
  else
    {
      return 0;
    }
  return 0;
}

int main()
{
  int scorex = 0;
  int scoreo = 0;
  int turn = 1;//holds player turn as 1 r -1 (multiplied by -1 to flip)
  bool winner = false;
  bool playing = true;
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

  //function declarations
  int printboard(char (&board)[3][3], int &turn, int &scorex, int &scoreo);
  bool checkwin(char (&board)[3][3], int &scorex, int &scoreo);
  bool isvalidmove(char (&board)[3][3], int row, int col);
  int placeplayer(char (&board)[3][3], int row, int col, int &turn);
  int taketurn(char (&board)[3][3],int &turn, bool &winner, bool &playing, int &scorex, int &scoreo);
  
  //setting up the board
  turn = 1;
  winner = false;
  cout << " Welcome to Tic Tac Toe" << endl;
  printboard(board, turn, scorex, scoreo);
  taketurn(board, turn, winner, playing, scorex, scoreo);
}
