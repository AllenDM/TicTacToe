#include "tttBoard.h"
//-| --------------------------------------------------------------
//-| Get move for player X: row and column positions.
//-| --------------------------------------------------------------
void Get_PlayerX_Move(tttBoard & B, int & row, int & col)
{
   do
   {
      cout << endl << "Player X, Enter move (row column): ";
      cin >> row >> col;
   }
   while ( row<1 || row >B.Size() || col<1 || col>B.Size() );
} //Get_PlayerX_Move


