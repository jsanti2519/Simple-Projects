/*
Missionaries and Cannibals Game
@author: Jonathan Santiago
April 12th, 2020
version(1)
*/

#include <iostream>
using namespace std;

int main() {

   string n;
   string rowLocation[] = {"left", "right"};
   string names[] = {"missionaries", "cannibals"};
   int q[] = {0, 0, 3, 3}, r[] = {0, 0};
   bool row = 1;

   while(true) {
      cout << "\nThe row is on the " << rowLocation[row] << ". There are ";
      if(row) cout << q[2];
      else cout << q[0];
      cout << " missionaries on the field and ";
      if(row) cout << q[3];
      else cout << q[1];
      cout << " cannibals on the field. There are " << r[0] << " missionaries and " << r[1] << " cannibals on the boat.\nSelect a choice:\n\n";

      while(true) {
         cin >> n;
         if(n[1] == 'R' && (n[0] == '0' || n[0] == '1')) {
            if(r[(int)(n[0]) - 48] == 0) cout << "There's no " << names[(int)(n[0]) - 48] << " on the boat. Select another choice. \n";
            else {
               r[(int)(n[0]) - 48]--;
               if(row) q[(int)(n[0]) - 46]++;
               else q[(int)(n[0]) - 48]++;
               break;
            }
         } 
         else if(n[0] == '0' || n[0] == '1') {
            if(row) q[(int)(n[0]) - 46]--; 
            else q[(int)(n[0]) - 48]--;
            r[(int)(n[0]) - 48]++;
            break;
         }
         else if(n == "Z" && (r[0] > 0 || r[1] > 0)) {
            row = !row;
            if(q[3] + r[1] > q[2] + r[0] || q[1] + r[1] > q[0] + r[0]) {
               cout << "You lose.";
               return 0;
            }
            break;
         }
         else cout << "You entered an invalid data. Please try again.\n";
      }
      if(q[0] == 3 && q[1] == 3) {
         cout << "You win!";
         return 0;
      }
   }
}
