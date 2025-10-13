/*
Emilio Vasquez-Pettit
10/02/2025

This program runs a two player game of TicTacToe in the console.

Citations:
1. MS Copilot

*/
#include <iostream>
#include <cstring>

using namespace std;

bool checkwin(char (&board)[3][3])//win detection, iterates through rows and columns, then checks both diagonals manually
{
  //check horizontals and verticals
  for (int i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
	{
	  cout << board[i][0] << " wins!" << endl;
	  return true;
	}
      else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
	{
	  cout << board[0][i] << " wins!" << endl;
	  return true;
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
int printboard(char (&board)[3][3], int &turn)
  {
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

int taketurn(char (&board)[3][3], int &turn, bool &winner, bool &playing)
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
          printboard(board, turn);
	  if (checkwin(board) == true)
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
  return 0;
}

int main()
{
  int turn = 1;//holds player turn as 1 r -1 (multiplied by -1 to flip)
  bool winner = false;
  bool playing = true;
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

  //function declarations
  int printboard(char (&board)[3][3], int &turn);
  //bool checkwin(char (&board)[3][3]);
  bool isvalidmove(char (&board)[3][3], int row, int col);
  int placeplayer(char (&board)[3][3], int row, int col, int &turn);
  int taketurn(char (&board)[3][3],int &turn, bool &winner, bool &playing);
  
  //setting up the board
  turn = 1;
  winner = false;
  cout << " Welcome to Tic Tac Toe" << endl;
  printboard(board, turn);
  taketurn(board, turn, winner, playing);
}
