// Picks a random word and corresponding category from the Words.txt list

#include "WordBank.h"
#include <iostream> // Used for basic commands
#include <fstream> // Used to work with the input file
#include <sstream> // Used for splitting the word and category apart

using namespace std;

WordBank::WordBank() {
	srand(time(0));	// Gets a random number each run
}

void WordBank::selectWord() {
	category = "";
	word = "";
	
	//Open the wordbank file and check for any errors
	ifstream words("Words.txt");
	if (words.fail()) {
		cerr << "File Words.txt failed to open";
		exit(1);
	}

	string line; // Stores each line read from input file
	int current = 0; // Counter for which line the file is on

	int target = (rand() % 200) + 1; // Random num 0-199 + 1 so 1-200


	while (getline(words, line)) { // Read file line by line
		current++;

		if (current == target) {
			stringstream ss(line); // Create a stringstream object to split the line

			// Split the category and word across the comma
			if (getline(ss, category, ',') && getline(ss, word)) {
				word.erase(0, 1); // Remove intial space from the word
			}
		}
	}

	words.close(); // Close the file after reading
}

string WordBank::getCategory() {
	return category;
}

string WordBank::getWord() {
	return word;
}