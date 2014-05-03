#include "tttBoard.h"
//-| --------------------------------------------------------------
//-| Get move for player X: row and column positions.
//-| --------------------------------------------------------------
void Get_PlayerX_Move(tttBoard & B, int & row, int & col)
{
   int r, c, BoardSize;                          // Table subscripts.
   int MajorDcount = 0;
   int MinorDcount = 0;
   BoardSize = B.Size();
   int rowcount = 0;
   int columncount = 0;
   char BoardCopy[B.Size()][B.Size()];
   //-| ----------------------------------------------------
   //-| 2. Find first empty spot.
   //-| ----------------------------------------------------


//-|Places Mark in center of board if available
    
r= (B.Size()/2) +1;
c= (B.Size()/2) +1;
         
if (B.isUnmarked(r,c))
{
row = (B.Size()/2) +1 ;
 col = (B.Size()/2) +1;
return;
}
    
//-|Center_Mark


//-|---------------------
//-|GAME ENDING MOVES
//-|---------------------
    
//-|When only one space is left in a row or column to win, fill it.
//-|Fill row
for (r=1; r<=B.Size(); r++)
   {
       rowcount=0;
       for (c=1; c<=B.Size(); c++)
       {
              if(B.isMarked('X',r,c))
               { rowcount++;
               }

       }
          if (rowcount == (B.Size() - 1))
         {
             for (c=1; c<=B.Size(); c++)
            {
              if(B.isUnmarked(r,c))
               {
                  row = r;
                  col = c; 
                   return;
               }  
            }
         }
   }//Fill Row  





//-|Fill Column
for (c=1; c<=B.Size(); c++)
  {
       columncount=0;
       for (r=1; r<=B.Size(); r++)
       {
              if(B.isMarked('X',r,c))
               { columncount++;
               }
                   
       }
      if (columncount == (B.Size() - 1))
         {
             for (r=1; r<=B.Size(); r++)
       {       
              if(B.isUnmarked(r,c))
               { row = r;
                col = c;
                return;
               }
       }
         }
   }//Fill Column











   
//-|----------------------
//-| DEFENSIVE MOVES
//-|----------------------

//-| Places Mark in blocking row
// Row_Block

for (r=1; r<=B.Size(); r++)
   {
       rowcount=0;
       for (c=1; c<=B.Size(); c++)
       {      
              if(B.isMarked('O',r,c))
               { rowcount++;
               } 
        
       }  
          if (rowcount == (B.Size() - 1))
         {
             for (c=1; c<=B.Size(); c++)
            {
              if(B.isUnmarked(r,c))
               {
                  row = r;
                  col = c; 
                   return;
               }  
            }
         }
   }// Row_Block


 

//-| Places Mark in blocking column
// Column_Block
for (c=1; c<=B.Size(); c++)
   {
       columncount=0;
       for (r=1; r<=B.Size(); r++) 
       {
              if(B.isMarked('O',r,c))
               { columncount++;
               }
                
       }
      if (columncount == (B.Size() - 1))
         {
             for (r=1; r<=B.Size(); r++)
       {
              if(B.isUnmarked(r,c))
               { row = r;
                col = c;
                return;
               }
       }
         }
   }// Column_Block



 //MinorDCounter
   c = B.Size();
   for (r=1;  r<=B.Size(); r++)
   {
                
             if(B.isMarked('O',r,c))
               { MinorDcount++;
               }
       c--;
   }//MinorDCounter
              


   //-|Places blocking mark in Minor Diagonal path
   //Minor Block
   
        
  if(MinorDcount == (B.Size()-1))
 {       
   c = B.Size();  
   for (r=1;  r<=B.Size(); r++)
   {         
   
   
                  if (B.isUnmarked(r,c))
                    {
                        row = r; col = c; return;
                    }
       c--;
   }//MinorBlock
 }


 //-|Major Diagonal opponent mark counter
   //Major_D_Counter
   c = B.Size();  
       for (r=B.Size();r>=1;r--)
     {       
       if (B.isMarked('O',r,c))
             {
               MajorDcount++;
             }
          c--;
      }//MajorDCounter
       
   



  //-|Places blocking mark in Major Diagonal path
   //Major Block
   if(MajorDcount == (B.Size()-1))
 {
   c = B.Size();  
   for (r=B.Size();  r>=1; r--) 
   {         
         if (B.isUnmarked(r,c))
             {
                row = r; col = c; return;
             }
       c--;   
   }//MajorBlock
 }     
  


   //-|Minor Diagonal opponent mark counter
   //Minor_D_Counter
   c = B.Size();
   for (r=1;  r<=B.Size(); r++)
   {
    
             if(B.isMarked('O',r,c))
               { MinorDcount++;
               }
       c--;
   }//MinorDCounter





 //-| Places mark in Minor Diagonal Configuration if available
 if(MinorDcount < 1)
 {
   c = B.Size();
   for (int r=1;  r<=B.Size(); r++)
   {
        if (B.isUnmarked(r,c))
       {
              
            row = r; col = c; return;
              
       }   
       c--;
   }//MinorDiagonal_Mark
 }


 //-|Major Diagonal opponent mark counter
   //Major_D_Counter  
   c = B.Size();
       for (r=B.Size();r>=1;r--)
     {
       if (B.isMarked('O',r,c))
             {
               MajorDcount++;
             } 
          c--;
      }//Major_D_Counter         
        
       

//-|Places Mark in Major Diagonal Configuration if availible
    c = B.Size();  
  if(MajorDcount < 1)
 {
for (r=B.Size();r>=1;r--)
     {
        if (B.isUnmarked(r,c))
             {
                row = r; col = c; return;
             }
          c--;
      }
//-|MajorDiagonal_Mark
 }




//-|--------------------------
//-|COLUMN AND ROW MOVES
//-|--------------------------

//-| If diagonals are blocked, starts filling empty row.
//RowFiller
      
for (r=B.Size(); r>=1; r--)     
   {
       rowcount=0;
       for (c=B.Size(); c>=1; c--)
       {
              if(B.isMarked('O',r,c))
               { rowcount++;
               }
        
       }
          if (rowcount < 1)   
         {
             for (c=B.Size(); c>=1; c--)
            {
              if(B.isUnmarked(r,c))
               {
                  row = r;
                  col = c;      
                   return;
               }  
            }
         }
              
               
   }// RowFiller


//-|If rows are blocked, starts filling empty column
              
//ColumnFiller 

for (c=1; c<=B.Size(); c++)  
   {
       columncount=0;
       for (r=1; r<=B.Size(); r++)
       {  
              if(B.isMarked('X',r,c))
               { columncount++;
               }
       
       }
            if (columncount < 1)
            {
             for (r=1; r<=B.Size(); r++)
              {
              if(B.isUnmarked(r,c))
                {
                  row = r;
                  col = c;   
                   return;
                }
              }
            }
   }// ColumnFiller













//-| Places mark in next available spot
  for (r=1; r<=B.Size(); r++)
   {
      for (c=1; c<=B.Size(); c++)
      {
         if (B.isUnmarked(r,c))
         {
             row = r; col = c; return;
         }
      }
   }// Places mark in next available spot
              





} //Get_PlayerX_Move


