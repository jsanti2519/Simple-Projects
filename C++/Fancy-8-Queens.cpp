/*Jonathan Santiago
CS211 Fancy 8-Queens Problem
Version (1.0)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string black(8, ' '); //or white (depends on program)
    string white(8, '*'); //or black
    
    for(int i = 0; i < 8; i++) { //rows for each box
        for(int j = 0; j < 5; j++) { //rows inside each box
            for(int k = 0; k < 8; k++) { //columns
                if(i % 2 == 0) {
                    if(k % 2 == 0) cout << black;
                    else cout << white;
                }
                else {
                    if(k % 2 == 0) cout << white;
                    else cout << black;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
