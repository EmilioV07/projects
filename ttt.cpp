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

bool checkwin(char board[3][3], int turn)//win detection, iterates through rows and columns, then checks both diagonals manually
{
  //check horizontals and verticals
  for (int i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] == board[i][2] && board[i][0] != '-')
	{
	  cout << board[i][0] << " wins!" << endl;
	  return true;
	}
      else if (board[0][i] == board[1][i] == board[2][i] && board[0][i] != '-')
	{
	  cout << board[0][i] << " wins!" << endl;
	  return true;
	}
    }
  //check diagonals
  if (board[0][0] == board[1][1] == board[2][2] && board [0][0] != '-')
    {
      cout << board[0][0] << " wins!" << endl;
      return true;
    }
  else if (board[0][2] == board[1][1] == board[2][0] && board [0][2] != '-')
    {
      cout << board[0][2] << " wins!" << endl;
      return true;
    }
  //check tie
  
  /*
  if "-" not in board[0][0] and "-" not in board[0][1] and "-" not in board[0][2] and "-" not in board[1][0] and "-" not in board[1][1] and "-" not in board[1][2] and "-" not in board[2][0] and "-" not in board[2][1] and "-" not in board[2][2] and winner == False:
  */
  return false;
}
int print_board(char board[3][3], int turn)
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

bool isvalidmove(row, col)//checks if the player's move choice is valid (not overwriting an existing move of either player)
{
  //add range check
  return board[row][col] == '-';//copilot simplification suggestion of an if and else compared to simply returning bool result of existing comparison
}

int main()
{
  int turn = 1;
  bool winner = false;
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

  //function declarations
  int print_board(char board[3][3], int turn);
  bool checkwin(char board[3][3], int turn);
  bool isvalidmove(row, col);
  
  //setting up the board
  while (playing == true)
    {
      turn = 1;
      winner = false;
      cout << " Welcome to Tic Tac Toe" << endl;
      print_board(board, turn);
      taketurn(board, turn);
    }
}



/*

#places player on row,col on the board
def place_player(row, col):
    global turn
    if turn == -1:
        board[row][col] = "O"
    elif turn == 1:
        board[row][col] = "X"
#Asks the user to enter a row and col until the user enters a valid location
#Adds user location to the board, and prints the board
def take_turn():
    global turn
    global winner
    while True:
        row = int(input("Enter a row (0,1,2): "))
        col = int(input("Enter a column(0,1,2): "))
        if is_valid_move(row, col) == True:
            place_player(row, col)
            turn = turn*-1
            print_board()
            if check_win() == True:
                return
                break
            elif check_win() == False:
                take_turn()
        elif is_valid_move(row, col) == False:
            print("That spot has been marked, choose another spot")
            continue
#Program Start
print(" Welcome to Tic-Tac-Toe!")
print_board()
take_turn()
*/
