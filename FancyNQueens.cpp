/*
Fancy N-Queens Problem
@author: Jonathan Santiago
April 18th, 2020
*/

#include <iostream>
#include <cmath>
using namespace std;

typedef string box[5][7];
box wb, bb;

string bl = " ", wh = "\u2588";

box wq = {wh, wh, wh, wh, wh, wh, wh,
          wh, bl, wh, bl, wh, bl, wh,
          wh, bl, wh, bl, wh, bl, wh,
          wh, bl, bl, bl, bl, bl, wh,
          wh, wh, wh, wh, wh, wh, wh};

box bq = {bl, bl, bl, bl, bl, bl, bl,
          bl, wh, bl, wh, bl, wh, bl,
          bl, wh, bl, wh, bl, wh, bl,
          bl, wh, wh, wh, wh, wh, bl,
          bl, bl, bl, bl, bl, bl, bl};

bool ok(int q[], int c) {
  for(int i = 0; i < c; i++)
    if(q[c] == q[i] || abs(q[i] - q[c]) == c - i) return false;

  return true;
}

void print(int q[], int n) {
  static int sol = 0;
  int i, j, k, l;
  box *board[n][n];

  //setting up black and white box
  for(i = 0; i < 5; i++)
    for(j = 0; j < 7; j++) {
      bb[i][j] = bl;
      wb[i][j] = wh;
    }

  //setting up n x n board
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++){
      if((i + j) % 2 == 0) {
        if(q[j] == i) board[i][j] = &wq;
        else board[i][j] = &wb;
      } else {
        if(q[j] == i) board[i][j] = &bq;
        else board[i][j] = &bb;
      }
    }

  //printing n x n board starting with upper border
  cout << " ";
  for(i = 0; i < 7 * n; i++) cout << "\u2500";
  cout << endl;
  for(i = 0; i < n; i++){
    for(k = 0; k < 5; k++) {
      cout << "\u2502"; //left border
      for(j = 0; j < n; j++)
        for(l = 0; l < 7; l++)
          cout << (*board[i][j])[k][l];
      cout << "\u2502" << endl; //right border
    }
  }
  cout << " ";
  for(i = 0; i < 7 * n; i++) cout << "\u2500";

  cout << endl << "Solution #" << ++sol << ". (Press ENTER for next Solution)"<< endl;
  for(i = 0; i < n; i++) cout << q[i] + 1 << " ";
  cout << endl;

  cout << endl << endl << endl;
}

void nqueens(int n) {
  int *q = new int[n];
  int c = 0;
  q[c] = 0;
  while(c >= 0) {
    c++;
    if(c == n) {
      print(q, n);
      cin.get();
      c--;
    }
    else q[c] = -1;
    while(c >= 0) {
      q[c]++;
      if(q[c] == n) c--;
      else if(ok(q, c)) break;
    }
  }
  delete[] q;
}

int main() {
  int n = -1;
  cout << "Enter a number (n) to represent an (n x n) board :";
  while(n < 0) cin >> n;

  nqueens(n);
}
