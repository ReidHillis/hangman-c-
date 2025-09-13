#pragma once
#include <string>
using namespace std;

class Drawing {
private:
	int hangmanStage;
public:
	Drawing();
	void setStage(int stage);
	void draw();
	string getDrawing();
};