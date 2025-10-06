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

int checkwin(char board[3][3], int turn)
{
  return 0;
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

int main()
{
  int turn = 1;
  bool winner = false;
  char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

  //function declarations
  int print_board(char board[3][3], int turn);
  int checkwin(char board[3][3], int turn);
  //setting up the board
  cout << "Welcome to Tic Tac Toe" << endl;
  print_board(board, turn);
  
}

/*
#Copy your functions from the previous activities here:
#Global Variables
board = [["-","-","-"], ["-","-","-"], ["-","-","-"]]#row -> column
turn = 1
winner = False
#Functions
#copy and paste your print_board function definition here!
def check_win():
    global board
    global winner
    for i in range(3):
        #check horizontal and change win counter and clear board accordingly
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] != "-":
            if board[i][0] == "O":
                print("O wins!")
                return True
            elif board[i][0] == "X":
                print("X wins!")
                return True
        #check vertical and change win counter and clear board accordingly
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] != "-":
            if board[0][i] == "O":
                print("O wins!")
                return True
            elif board[0][i] == "X":
                print("X wins!")
                return True
    #check diagonals and change win counter and clear board accordingly
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != "-":
        if board[0][0] == "O":
            print("O wins!")
            return True
        elif board[0][0] == "X":
            print("X wins!")
            return True
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != "-":
        if board[0][2] == "O":
            print("O wins!")
            return True
        elif board[0][2] == "X":
            print("X wins!")
            return True
    #check tie and clear board accordingly
    if "-" not in board[0][0] and "-" not in board[0][1] and "-" not in board[0][2] and "-" not in board[1][0] and "-" not in board[1][1] and "-" not in board[1][2] and "-" not in board[2][0] and "-" not in board[2][1] and "-" not in board[2][2] and winner == False:
        print("tie!")
def print_board():
    print("")
    global board
    global turn
    if turn == -1:
        print("O's turn")
    elif turn == 1:
        print("X's turn")
    print("  "+ "0" + " " + "1" + " " + "2")
    for i in range(3):
        print(str(i) + " " + board[i][0] + " " + board[i][1] +  " " + board[i][2])
#returns true if a row,col on the board is open
def is_valid_move(row, col):
    global board
    while True:
        if board[row][col] != "-":
            return False
        elif board[row][col] == "-":
            return True
            break#backup
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
