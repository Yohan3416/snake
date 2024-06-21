#include<iostream>
#include <vector>
#include"SnakePart.h"
using namespace std;

class Snake
{
public:
	Snake();
	Snake(int x, int y, char direction);
	void move();
	bool isGameOver();
	void setDirection(char direction);
	vector<SnakePart> snakParts;
	int x = 15;
	int y = 15;
	int tailX;
	int tailY;
	char getDirection();
	void drawSnake();
private:
	
	char direction;
	bool gameOver;
	bool findPart(int x, int y);
	
};