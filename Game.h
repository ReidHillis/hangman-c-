#pragma once
#include <string>
#include "WordBank.h"
#include "Drawing.h"


class Game {
private:
	WordBank wordBank;
	Drawing drawing;
	int score;
public:
	Game();
	void startGame();
	int getScore();
};
