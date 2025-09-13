#include <iostream> // Used for basic commands like cout and endl
#include "Game.h"
#include "Drawing.h"

using namespace std;

Game::Game() {
    wordBank.selectWord(); // Get a random word and category from WordBank
    score = 0; // Set new game score to 0
}

int Game::getScore() {
    return score;
}

void Game::startGame() {
    bool playingGame = true;

    while (playingGame) {
        // Input the word and category to variables for ease of use
        string category = wordBank.getCategory();
        string word = wordBank.getWord();
        string originalWord = word; // Used for checking if the word is guessed
        int guessesRemaining = 6; // How many guesses they have before the hangman is completed
        Drawing drawing; // Used for drawing the hangman

        // Convert the word to lowercase for guessing purposes
        for (char& c : word)
            c = tolower(c);

        char guess;

        // Make an outline of the word, 1 underscore per letter
        string blank = word;
        for (int i = 0; i < blank.length(); i++) {
            if (blank[i] != ' ')
                blank[i] = '_';
        }

        while (true) {
            drawing.setStage(6 - guessesRemaining); // Set the current stage od drawing
            drawing.draw(); // Draw the hangman

            cout << "Category: " << wordBank.getCategory() << endl; // Print the category
            cout << "Score: " << score << endl; // Print current score
            cout << blank << endl; // Print the word outline

            // Take in the user's guess
            cout << "Guess a letter: ";
            cin >> guess;
            guess = tolower(guess); // Make the guess lowercase

            string copy = blank; // Copy of the outline to check if any changes occurred

            // Check if the current letter has already been guessed
            bool alreadyGuessed = false;
            for (int i = 0; i < word.length(); i++) {
                if (guess == blank[i])
                    alreadyGuessed = true;
            }

            // Search through the secret word letter by letter
            // Check if the guessed letter is in the word
            for (int i = 0; i < word.length(); i++) {
                // If the letter is in the word, reveal it
                if (guess == word[i]) {
                    // If the letter is the start of the word then capitalize it
                    if (i == 0 || word[i - 1] == ' ')
                        blank[i] = toupper(word[i]);
                    else
                        blank[i] = word[i];
                }
            }

            // If the letter was already guessed, let the user know and don't take away a guess
            if (alreadyGuessed == true) {
                cout << "You have already guessed this letter. Try again.\n" << endl;
            }
            // Otherwise, proceed normally
            else {
                // Check if the user got a letter right
                // If the copy is the same as the blank outline as before, they did not guess a letter correctly
                if (copy == blank) {
                    cout << "Incorrect.\n" << endl;
                    guessesRemaining--; // This makes the drawing update next loop
                }
                else
                    cout << "Correct!\n" << endl;
            }

            if (guessesRemaining == 0) {
                cout << "Game over! The word was: " << originalWord << endl;
                cout << "Final Score: " << score << endl;
                playingGame = false;
                break;
            }

            // If the guessed letters equal the word, then the word is solved
            if (blank == originalWord) {
                cout << "You solved the word!: " << blank << endl;
                score++;
                cout << "Score: " << score << "\n" << endl;
                
                wordBank.selectWord(); // Get a new word for next round
                break; // Break inner loop (current round) to start new round
            }

        }
    }

    
}