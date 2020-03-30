/* Jonathan Santiago
CS211 Fancy 8-Queens Problem
Version (3.0)
Changes: Adding borders/adjusting box width
*/

#include <iostream>
using namespace std;

typedef string box[5][7];
box white, black, wq, bq, *board[8][8];

void setUp() { 
   //set up each box
   for(int i = 0; i < 5; i++) 
      for(int j = 0; j < 7; j++) {
         white[i][j] = "\u2588";
         black[i][j] = " ";
      }
}

void queensBox() {
   //drawing the sides for queen boxes
   for(int i = 0; i < 7; i++) {
      wq[0][i] = "\u2588";
      bq[0][i] = " ";
      wq[4][i] = "\u2588";
      bq[4][i] = " ";
   }
   //drawing the top and bottom
   for(int i = 1; i < 4; i++) {
      wq[i][0] = "\u2588";
      bq[i][0] = " ";
      wq[i][6] = "\u2588";
      bq[i][6] = " ";
   }

   //matching pattern inside
   for(int i = 1; i < 3; i++) {
      for(int j = 1; j < 6; j++) {
         if(j % 2 == 0) {
            wq[i][j] = "\u2588";
            bq[i][j] = " ";
         }
         else {
            wq[i][j] = " ";
            bq[i][j] = "\u2588";
         }
      }
   }
   for(int i = 1; i < 6; i++) {
      wq[3][i] = " ";
      bq[3][i] = "\u2588";
   }
}

void setBoard() {
   for(int i = 0; i < 8; i++) 
      for(int k = 0; k < 5; k++) 
         for(int j = 0; j < 8; j++) 
            for(int l = 0; l < 7; l++){
               if((i + j) % 2 == 0) board[i][j] = &white;
               else board[i][j] = &black;
            }
}

void printBoard() {
   //first, print upper border
   cout << " ";
   for(int i = 0; i < 7 * 8; i++) cout << "\u2581";
   cout << endl;

   for(int i = 0; i < 8; i++) {
      for(int k = 0; k < 5; k++) {
         cout << "\u2595";
         for(int j = 0; j < 8; j++) {
            for(int l = 0; l < 7; l++){
               cout << (*board[i][j])[k][l];
            }
         }
         cout << "\u258e"; cout << endl;
      }
   }
   cout << " ";
   for(int i = 0; i < 7 * 8; i++) cout << "\u2594";
}


int main() {
   setUp();
   queensBox();
   setBoard();
   int c = 0, r;
   board[0][0] = &wq;

newCol:
   c++;
   if(c == 8) {
      printBoard();
      cout << endl << endl << endl << endl << endl;
      goto backtrack;
   }
   r = -1;

newRow:
   r++;
   if(r == 8) goto backtrack;

   //row test
   for(int i = 0; i < c; i++)
      if(board[r][i] == &wq || board[r][i] == &bq) goto newRow;

   //upper diagonal test
   for(int i = 1; r - i >= 0 && c - i >= 0; i++)
      if(board[r - i][c - i] == &wq || board[r - i][c - i] == &bq) goto newRow;

   //lower diagonal test
   for(int i = 1; r + i < 8 && c - i >= 0; i++)
      if(board[r + i][c - i] == &wq || board[r + i][c - i] == &bq) goto newRow;

   if((r + c) % 2 == 0) board[r][c] = &wq;
   else board[r][c] = &bq;

   goto newCol;

backtrack:
   c--;
   if(c == -1) return 0;
   r = -1;
   while(true) {
      r++;
      if(board[r][c] == &wq || board[r][c] == &bq) break;
   }
   if(board[r][c] == &wq) board[r][c] = &white;
   else board[r][c] = &black;
   goto newRow;
   
}
