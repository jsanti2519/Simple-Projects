#include <iostream>
using namespace std;

static int mp[3][3] = {0, 2, 1,
                       0, 2, 1,
                       1, 2, 0};

static int wp[3][3] = {2, 1, 0,
                       0, 1, 2,
                       2, 0, 1};
                       
bool ok(int q[], int c) {
    //check to test if woman is married
    for(int i = 0; i < c; i++) 
        if(q[i] == q[c]) return false;
    
    //check to test if woman i has feelings towards man c more than her husband i and if man c has more feelings towards woman i than his wife c.
    for(int i = 0; i < c; i++) 
        if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
        
    //check to test if man i has feelings towards woman c more than his wife i and if woman c has more feelings towards man i than her husband c.
    for(int i = 0; i < c; i++)
        if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
        
    return true;
}


void print(int q[], int n) {
    for(int i = 0; i < n; i++) 
        cout << i << "\t" << q[i] << endl;
    cout << endl;
}       
        
void nmarriage(int n) {
    
    int *q = new int[n];
    int c = 0;
    q[c] = 0;
    while(c >= 0) {
        c++;
        if(c == n) {
            print(q, n);
            c--;
        } else q[c] = -1;
        while(c >= 0) {
            q[c]++;
            if(q[c] == n) c--;
            else if(ok(q, c)) break;
        }
    }
    
    delete[] q;
}

int main() {
    nmarriage(3);
}
