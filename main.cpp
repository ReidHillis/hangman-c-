/*
* Reid Hillis
* Hangman Main Game Menu
*/

#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Hangman!" << endl;
    cout << "Guess one letter at a time to reveal the secret word." << endl;
    cout << "Solve the word before the hangman is drawn.\n" << endl;

    Game game;
    game.startGame(); // Start the game

    cout << "\nThanks for playing!" << endl;

}
