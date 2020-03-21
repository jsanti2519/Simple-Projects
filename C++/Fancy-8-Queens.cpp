/* Jonathan Santiago
CS211 Fancy 8-Queens Problem
Version (2.0)
Changes: Adding borders/adjusting box width
*/

#include <iostream>
using namespace std;

int main() {
  char c = ' ';

  //print upper border
  for(int i = 0; i < (7 * 8) + 1; i++) cout << '-';
  cout << endl;

  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 5; j++){
      cout << '|'; //left border
      for(int k = 0; k < 8; k++) {
        if((i + k) % 2 == 0) c = ' ';
        else c = '*';
        for(int l = 0; l < 7; l++)  //adjusting width of box
          cout << c;
      }
      cout << '|' << endl; //right border
    }

  //print lower border
  for(int i = 0; i < (7 * 8) + 1; i++) cout << '-';

  return 0;
}
