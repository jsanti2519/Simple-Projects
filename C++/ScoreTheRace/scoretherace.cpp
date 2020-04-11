/*
Score the Race!
April 10th, 2020
@author: Jonathan Santiago
*/

#include <iostream>
using namespace std;

//See PDF document of Project.

int main() {
    string n; //Represents the arrangement of the outcome of a race

retry:
    cout << "Enter a string of Uppercase Characters:\n";
    cin >> n;
    char letter[26];
    for(int i = 0; i < 26; i++)
        letter[i] = (char)(65 + i);

    int letterCount[26] = {0};
    for(int i = 0; i < n.length(); i++) {
        if(n[i] < 65 || n[i] > 90) {
           cout << "Invalid entry. Please try again.\n"; goto retry;
        }
        for(int j = 0; j < 26; j++) {
            if(letter[j] == n[i]) ++letterCount[j];
        }
    }

    int runners = 0;

    /* Note: Each team must have exactly an equal number of members.
    This test determines that. If there isn't an equal number of members,
    the program will require the user to re-type a valid outcome. */

    for(int i = 0; i < 26; i++) {
        if(letterCount[i] > 0) {
            runners = letterCount[i];
            for(int j = i; j < 26; j++) 
                if(letterCount[j] != runners && letterCount[j] > 0) {
                    cout << "There is not an equal number of members. Try again.\n";
                    goto retry;
                }
        }
        if(runners > 0) break; /*no need to continue iterating since inner loop
        confirms that there is an equal number of members. */
    }
        
    int teams = 0;
    cout << "There are ";
    for(int i = 0; i < 26; i++)
        if(letterCount[i] > 0) teams++;
    
    cout << teams << " teams in the race.\n\nEach team has " << runners << " runners.\n\n";

    int places[26] = {0}; //assume each letter is in a race (26).
    char letterinRace[26];
    double scores[26];

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < n.length(); j++) 
            if(letter[i] == n[j]) places[i] += (j + 1);

    int k = 0; //counter variable to count teams in the race

    //only considering the teams that ARE in the race
    for(int i = 0; i < 26; i++)
        if(letterCount[i] > 0){
            letterinRace[k] = letter[i];
            scores[k] = (double)(places[i]) / letterCount[i];
            cout << letterinRace[k] << "\t" << scores[k] << endl;
            k++;
        }

    double winningScore = scores[0];
    char winner = letterinRace[0];

    //Determining winner out of those in the race
    for(int i = 0; i < k; i++)
        if(scores[i] < winningScore) {
            winningScore = scores[i];
            winner = letterinRace[i];
        }

    cout << endl << "The winner is " << winner << " with a score of " << winningScore << ".\n";

    return EXIT_SUCCESS;
}
