/*
8 Numbers on a Cross (Without Functions)
@author: Jonathan Santiago
April 12th, 2020
*/

#include <iostream>
using namespace std;

int main() {
  int a[8][5] = {
    {-1},
    {0, -1},
    {0, 1, -1},
    {0, 2, -1},
    {1, 2, -1},
    {1, 2, 3, 4, -1},
    {2, 3, 5, -1},
    {4, 5, 6, -1}};

  int b[3][4] = {
    -1, 1, 4, -1,
    0, 2, 5, 7,
    -1, 3, 6, -1};
  
  bool fails;
  int c = 0, q[8], i, j;
  q[c] = 1;

  while(c >= 0) {
    c++;
    if(c == 8) {
      for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
          if(b[i][j] == -1) cout << " ";
          else cout << q[b[i][j]];
        }
        cout << endl;
      }
      cout << endl;
      c--;
    }
    else q[c] = 0;
    while(c >= 0) {
      q[c]++;
      if(q[c] > 8) c--;
      else {
        fails = false;
        //repetition test
        for(i = 0; i < c; i++) 
          if(q[c] == q[i]) {
            fails = true;
            break;
          }

        if(!fails) {
          //consecutive numbers test
          for(i = 0; a[c][i] != -1; i++)
            if(abs(q[c] - q[a[c][i]]) == 1) {
              fails = true;
              break;
            }
        }
        if(!fails) break;
      }
    }
  }
}

