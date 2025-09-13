#pragma once
#include <string>
using namespace std;

class WordBank {

private:
	string category;
	string word;
public:
	WordBank();
	void selectWord();

	string getWord();
	string getCategory();


};