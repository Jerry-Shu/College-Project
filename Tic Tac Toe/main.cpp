#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

//declare function prototypes

int main()
{
    ///main is complete, nothing to do here
    char board[ROWS][COLS];
    bool playerToggle = false;

    fillBoard(board);
    showBoard(board);

    while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }

    return 0;
}

///TODO (0)
   ///Define fillBoard
   ///Use a nested for loop to Fill the 2D array with '*'s


///TODO (1)
   ///Define showBoard
   ///Use a nested for loop to print the board
   ///For each row, print the row number, then use an inner for loop to print each cell, separated by a space
   ///print a newline when the inner for loop is complete to move on to the next row


void getChoice(char b[][COLS], bool playerToggle)
{
    string player;
    char c;
    int row, col;
    
    ///TODO (2)
      ///if playerToggle is false, then set the player string and c to correspond to player 1
      ///otherwise player 2
      
      
    ///TODO (3)
      ///implement validation loop
    do
    {
        do
        {
            ///prompt the current player to enter the row
        }while();  ///range for row is invalid?

        do
        {
            ///prompt the current player to enter the column
        }while();  ///range for col is invalid?

    }while();  ///the chosen cell is an X or an O?

    ///assign the player's char to the chosen cell
    ///NOTE:  row 1, col 1 to the user is actually row 0, col 0 in the array
}

///TODO (4)
   ///implement gameOver
   
bool gameOver(char b[][COLS])
{
    bool gameOver = false;
   
    if() /// X Wins
    {
   
    }
    else if() ///O Wins
    {
   
    }
    else if() ///Tie
    {

    }
   
    return gameOver;
}

