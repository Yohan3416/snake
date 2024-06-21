#include "snake.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Food.h"
using namespace std;
// Snake类的构造函数，设置初始位置和方向 
Snake::Snake(int x, int y, char direction) : x(x), y(y), direction(direction){
	snakParts.push_back({ x, y });// 初始化蛇身 
}

void Snake::move(){
	int nextX = snakParts[0].x;
	int nextY = snakParts[0].y;
	// 根据当前方向更新下一个位置
	switch (direction)
	{
	case 'w':
		nextY--;
		break;
	case 's':
		nextY++;
		break;
	case 'a':
		nextX --;
		break;
	case 'd':
		nextX ++;
		break;
	}

	// 清空之前的蛇身
	for (int i = 0; i < snakParts.size(); i++)
	{
		int x = snakParts[i].x;
		int y = snakParts[i].y;
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << ' ';
	}
	// 判断游戏是否结束
	if (nextX <= 0 || nextX >= 40 || nextY <= 0 || nextY >= 25 || findPart(nextX, nextY)){
		this->gameOver = true;
	}
	else
	{
		// 更新蛇身的位置
		for (int i = snakParts.size() - 1; i >= 1; i--){
			snakParts[i].x = snakParts[i - 1].x;
			snakParts[i].y = snakParts[i - 1].y;
		}
		snakParts[0].x = nextX;
		snakParts[0].y = nextY;
	}
	tailX = snakParts[snakParts.size() - 1].x;
	tailY = snakParts[snakParts.size() - 1].y;
}

// 检查游戏是否结束
bool Snake::isGameOver(){
	if (gameOver) return true;
	for (int i = 1; i < this->snakParts.size(); i++)
	{
		if (snakParts[0].x == snakParts[i].x && snakParts[0].y == snakParts[i].y )
		{
			this->gameOver = true;
			return true;
		}
	}
	return false;
}

// 设置蛇的移动方向
void Snake::setDirection(char direction){
	//方向相反不改变原方向
	if ((this->direction == 'w'&&direction == 's') || (this->direction == 's'&&direction == 'w') || (this->direction == 'a'&&direction == 'd') || (this->direction == 'd'&&direction == 'a')){
		return;
	}
	this->direction = direction;
}

// 查找蛇身是否包含指定位置
bool Snake::findPart(int x, int y){
	for (int i = 0; i < snakParts.size(); i++){
		if (snakParts[i].x == x&&snakParts[i].y == y) return true;
	}
	return false;
}

// 获取当前移动方向
char Snake::getDirection(){
	return this->direction;
}

// Snake类的默认构造函数
Snake::Snake() {
	snakParts.push_back({ x, y }); // 初始化蛇身
	this->direction = 'w';// 初始方向为向上
	this->gameOver = false;// 游戏未结束 
}

// 绘制蛇
void Snake::drawSnake() {
	for (int i = 0; i < snakParts.size(); i++) {
		if (i == 0) {
			int x = snakParts[i].x;
			int y = snakParts[i].y;
			COORD pos = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			cout << '$'; // 蛇头
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else {
			int x = snakParts[i].x;
			int y = snakParts[i].y;
			COORD pos = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			cout << 'O'; // 蛇身 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}