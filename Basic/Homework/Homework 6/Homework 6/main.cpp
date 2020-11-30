/*
 Homework #6
 Author: Juan Carbajal
 Email: juancarbajal98@gmail.com
 Course: PIC 10 Fall 2018
 Collaborators: N/A
 
 Honesty Pledge:
 
 I, Juan Carbajal, pledge that this is my independent work and abide by the guidelines of honesty outlined in the syllabus.
 
 User inputs: (3) guesses at a battleship game
 
 Output: A "game board" showing the corresponding shots from the user as well as any hits on 3 randomnly placed ships
 
 List of known bugs: none
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

/* Clears screen so only one row of text is displayed at a time
 @return thousands of lines of empty space
 */
void clearscreen()
{ for (int a = 0; a < 1000; a += 1){cout << "\n\n\n\n";}
}

int main(){

    // 3 distinct random integers between 0-9
    // Although user will enter integer between 1-10 for shot, 0-9 are the corresponding indexes of the vector we will define to store locations of ships
    srand(time(0));
    int x1 =  rand() % 10 ;
    int x2 = rand() % 10;
    while (x2 == x1)
        {x2 = rand() % 10;}
    int x3 = rand() % 10 ;
    while (x3 == x1 || x3 == x2)
        {x3 = rand() % 10 ;}

    
    //vector of 10 elements where location of 3 ships will be stored
    vector<string> ship(10);
    int i;
    
    
    // define blank board
    for (i =0; i < ship.size(); i += 1) {
        ship[i] = "___" ;
        cout << ship[i] << " " ;}
   
    
    // Round 1
    // Gather input and shift user's guess down by 1 to correspond with the correct vector index
    // Although no error message is outputted for invalid input, the user is not penalized for integers out of range
    cout << "Shot 1 Location: " ;
    int guess1 = 0;
    cin >> guess1 ;
    guess1 = guess1 - 1;
    clearscreen();
   
    // If user shoots one of three ships it is indicated on the board with "<*>"
    // If the shot is missed it is indicated on the board with " * "
    if (guess1 == x1) {
        ship[x1] = "<*>";}
    else if (guess1 == x2) {
        ship[x2] = "<*>";}
    else if (guess1 == x3){
        ship[x3] = "<*>";}
    else {ship[guess1] = " * ";}
    
    // Reprint the board that now reflects shot 1
    for (i =0; i < ship.size(); i += 1) {
            cout << ship[i] << " " ;}
    
    
    
    // Round 2 -- similar procedure to Round 1
    cout << "Shot 2 Location: " ;
    int guess2 = 0;
    cin >> guess2 ;
    guess2 = guess2 - 1;
    clearscreen();
    if (guess2 == x1) {
        ship[x1] = "<*>";}
    else if (guess2 == x2) {
        ship[x2] = "<*>";}
    else if (guess2 == x3){
        ship[x3] = "<*>";}
    else {ship[guess2] = " * ";}
    for (i =0; i < ship.size(); i += 1) {
        cout << ship[i] << " " ;}
    
    
    
    // Round 3 -- similar procedure to Round 1
    // except before we print the board now we will update it to show all ship locations regardless of whether they were all hit or not
    cout << "Shot 3 Location: " ;
    int guess3 = 0;
    cin >> guess3 ;
    guess3 = guess3 - 1;
    clearscreen();
    if (guess3 == x1) {
        ship[x1] = "<*>";}
    else if (guess3 == x2) {
        ship[x2] = "<*>";}
    else if (guess3 == x3){
        ship[x3] = "<*>";}
    else {ship[guess3] = " * ";}
    
    // show all ships for final cout of vector
    if (ship[x1] != "<*>") {ship[x1] = "<> ";}
    if (ship[x2] != "<*>") {ship[x2] = "<> ";}
    if (ship[x3] != "<*>") {ship[x3] = "<> ";}
    
    // Final print of board that now shows all ships and/or shot locations
    for (i =0; i < ship.size(); i += 1) {
        cout << ship[i] << " " ;}
    
    
    
    // construct a success vector composed solely of elements that indicate a user hit
    vector<string> success ;
    for (i=0; i< ship.size(); i += 1) {
        if (ship[i] == "<*>") {success.push_back(ship[i]);}
    }
    
    // Determine the success rate of the user's guess
    const int p = 100;
    const int rounds = 3;
    int success_rate = (success.size() * p) / rounds;
    // Guarantees 66.666667%  will not be truncated
    if (success_rate == 66) {success_rate = 67;}
    cout << "Success = " << success_rate << " %" << endl;
    
    return 0;
}

