// Draws the hangman's current stage

#include "Drawing.h"
#include <iostream>
using namespace std;

Drawing::Drawing() {
	hangmanStage = 0;
}

void Drawing::setStage(int hangmanStage) {
	this->hangmanStage = hangmanStage;
}

void Drawing::draw() {
	cout << getDrawing() << endl;
}

string Drawing::getDrawing() {
    if (hangmanStage == 0) {
        return  "+---+   \n"
                "|       \n"
                "|       \n"
                "|       \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 1) {
        return  "+---+   \n"
                "|   O   \n"
                "|       \n"
                "|       \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 2) {
        return  "+---+   \n"
                "|   O   \n"
                "|   |   \n"
                "|       \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 3) {
        return  "+---+   \n"
                "|   O   \n"
                "|  /|   \n"
                "|       \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 4) {
        return  "+---+   \n"
                "|   O   \n"
                "|  /|\\ \n"
                "|       \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 5) {
        return  "+---+   \n"
                "|   O   \n"
                "|  /|\\ \n"
                "|  /    \n"
                "|       \n"
                "=======   ";
    }
    else if (hangmanStage == 6) {
        return  "+---+   \n"
                "|   O   \n"
                "|  /|\\ \n"
                "|  / \\ \n"
                "|       \n"
                "=======   ";
    }
    else {
        return "";
    }

}
