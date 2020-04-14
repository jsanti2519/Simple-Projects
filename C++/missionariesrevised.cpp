/*
Missionaries and Cannibals Game (using different representation)
@author: Jonathan Santiago
April 14th, 2020
version (1)
*/

#include <iostream>
using namespace std;

static int r[5][2] = {{0, 1}, //row positions
                      {1, 0},
                      {1, 1},
                      {0, 2},
                      {2, 0}};

bool ok(int q[]) {
   if(q[0] < q[1] || q[2] < q[3]) return false; //if there are more cannibals than missionaries
   return true;
}


int main() {
   int q[] = {0, 0, 3, 3}; // first two elements are missionaries and cannibals on the left.
   int n;
   bool row = 1;

   while(q[0] != 3 && q[1] != 3){
      n = -1;
      cout << "The row is on the ";
      if(row) cout << "right side. There are " << q[2] << " missionaries and " << q[3] << " cannibals. ";
      else cout << "left side. There are " << q[0] << " missionaries and " << q[1] << " cannibals. ";
      cout << "Enter a row number: \n";
      while(n < 0 || n >= 5) cin >> n;
      if(row){
         q[0] += r[n][0];
         q[1] += r[n][1];
         q[2] -= r[n][0];
         q[3] -= r[n][1];
      }
      else {
         q[0] -= r[n][0];
         q[1] -= r[n][1];
         q[2] += r[n][0];
         q[3] += r[n][1];
      }
      if(!ok(q)) {
         cout << "You lose";
         return 0;
      }
      row = !row;
   }
   cout << "You win!";
   return EXIT_SUCCESS;
}
