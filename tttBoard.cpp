#include "tttBoard.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//----------------------------------------------------------------------
// Constructor: initialize board.
//----------------------------------------------------------------------
tttBoard :: tttBoard()   
{
   BoardSize = 3;
   numMoves = 0;
   gameWon = false;
   moveFailed = false;
   for (int r=0; r<BoardSize; r++)
      for (int c=0; c<BoardSize; c++)
         Board[r][c] = ' ';
}

//----------------------------------------------------------------------
// Constructor: initialize board.
//----------------------------------------------------------------------
tttBoard :: tttBoard(int boardsize)   
{
   BoardSize = boardsize;
   numMoves = 0;
   gameWon = false;
   moveFailed = false;
   for (int r=0; r<BoardSize; r++)
      for (int c=0; c<BoardSize; c++)
         Board[r][c] = ' ';
}

//----------------------------------------------------------------------
// Function: Write board to output stream.
//----------------------------------------------------------------------
void tttBoard :: Show(ostream & outF, string tabString)
{
   string divider = tabString;
   for (int m=1; m<BoardSize; m++)
       divider += "---+";
   divider += "---";

   outF << endl; 
   for (int r=0; r<BoardSize; r++)
   {
      outF << divider << endl;
      outF << tabString; 
      for (int c=0; c<BoardSize-1; c++)
      {
         outF << " " << Board[r][c] << " |";
      }
      outF << " " << Board[r][BoardSize-1] << " " << endl;
   }
   outF << divider << endl;

}
 
//----------------------------------------------------------------------
// Function: Return true if player can place a mark at specified position,
//           e.g., if position is empty.
//----------------------------------------------------------------------
void tttBoard :: Mark(char playerMark, int row, int col)
{
   moveFailed = false;

   if ( (row < 1 || row > BoardSize) || (col<1 || col>BoardSize) )
   {
      cout << "\nMark: BAD BOARD POSITION: (" << row << "," 
           << col << ") -- Move ignored." << endl;
      moveFailed = true;
      return;
   }
 
   if ( Board[row-1][col-1] != ' ')
   {
      cout << "\nMark: BAD MARK: POSITION (" << row << "," << col 
           << ") OCCUPIED by mark " << Board[row-1][col-1] << endl;
      moveFailed = true;
      return;
   }

   Board[row-1][col-1] = playerMark;
   numMoves++;
}
 
 
//----------------------------------------------------------------------
// Function: Determine whether player with specified mark has won. 
//----------------------------------------------------------------------
bool tttBoard :: isWinner(char playerMark)
{
   bool winner;
   int row, col; 

   //-| -------------------------------------------------------
   //-| Test each winning configuration. If match, return true.
   //-| -------------------------------------------------------
   //-|  1. Row winner.: 
   //-|  2. Column winner.
   //-|  3. Major diagonal winner.
   //-|  4. Minor diagonal winner.

   //-| Check row winner.
   for (row=0; row<BoardSize; row++)
   {   
       winner = true;
       for (col=0; winner && col<BoardSize; col++)
       {
           winner = winner && (Board[row][col] == playerMark);
       } 
       if (winner) return true;
   }//Winner_row

   //-| Check column winner.
   for (col=0; col<BoardSize; col++)
   {   
       winner = true;
       for (row=0; row<BoardSize; row++)
       {
           winner = winner && (Board[row][col] == playerMark);
       } 
       if (winner) return true;
   }//Winner_row

   //-| Check major diagonal winner.
   winner = true;
   for (int k=0; k<BoardSize; k++)
   {   
       winner = winner && (Board[k][k] == playerMark);
   }//Winner_major_Diagonal
   if (winner) return true;

   //-| Check mino2r diagonal winner.
   winner = true;
   col = BoardSize - 1;
   for (int k=0; winner && k<BoardSize; k++)
   {   
       winner = winner && (Board[k][col--] == playerMark);
   }//Winner_minor_Diagonal

   gameWon = gameWon || winner;

   return winner;

}//isWinner

 
//----------------------------------------------------------------------
// Function: Determine whether there is a draw. 
//----------------------------------------------------------------------
bool tttBoard :: isDraw()
{
   return (! gameWon && numMoves >= BoardSize*BoardSize);
}

 
//----------------------------------------------------------------------
// Function: Return outcome of previous move/mark.
//----------------------------------------------------------------------
bool tttBoard :: MoveFailed()
{
   return moveFailed;
}


//----------------------------------------------------------------------
// Function: Reset the board to empty.
//----------------------------------------------------------------------
void tttBoard :: Clear()
{
   int r,c;   // Loop variables.
   numMoves = 0;
   gameWon = false;
   moveFailed = false;

   for (r=0; r<BoardSize; r++)
      for (c=0; c<BoardSize; c++)
         Board[r][c] = ' ';
}

//----------------------------------------------------------------------
// Function: Return size of board.
//----------------------------------------------------------------------
int tttBoard :: Size()
{
   return BoardSize;
}

//----------------------------------------------------------------------
// Function: Return true if player has mark in row,col position.
//----------------------------------------------------------------------
bool tttBoard :: isMarked(char playerMark, int row, int col)
{
   if ( (row < 1 || row > BoardSize) || (col<1 || col>BoardSize) )
      return false;
   else
      return (Board[row-1][col-1] == playerMark);
}

//----------------------------------------------------------------------
// Function: Return true if NO MARK in row,col position.
//----------------------------------------------------------------------
bool tttBoard :: isUnmarked(int row, int col)
{
   if ( (row < 1 || row > BoardSize) || (col<1 || col>BoardSize) )
      return false;
   else
      return (Board[row-1][col-1] == ' ');
   
}

//----------------------------------------------------------------------
// Function: Return #valid moves made on board.
//----------------------------------------------------------------------
int tttBoard :: MovesMade()
{
   return numMoves;
}

 
//----------------------------------------------------------------------
// Function: Return true if board is empty.
//----------------------------------------------------------------------
bool tttBoard :: isEmpty()
{
   return (numMoves == 0);
}
 
//----------------------------------------------------------------------
// Function: Return true if board is filled.
//----------------------------------------------------------------------
bool tttBoard :: isFull()
{
   return (numMoves == BoardSize*BoardSize);
}
