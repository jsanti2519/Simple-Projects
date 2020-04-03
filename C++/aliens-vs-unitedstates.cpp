/*
A group of three aliens arrive on Earth to dominate the U.S. President for attempting to send Voyager ships to spy on them from a galaxy far away. Using the aliens' far more advanced technology,
they are able to transport to Earth at light speed and destroy all 50 states. However, each alien gets a fair share of the number of states they get to destroy. Using this algorithm below, a
group of 3 aliens are able to have a fair share of states that they get to wipe out completely.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int states = 50;
    int alien[3], sum = 0, remainder = 0, portion, i = 0;
    while(i < 3) {
        portion = states / 3;
        alien[i++] = portion;
        sum += portion;
    }
    if(sum < states) {
        while(remainder++ != (states % 3))
            alien[rand() % 3] += 1;
    }
    
    for(i = 0; i < 3; i++) 
        cout << "Alien " << i + 1 << " invaded " << alien[i] << " states.\n";
}
