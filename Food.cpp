#include"Food.h"
#include <Windows.h>
#include <iostream>
using namespace std;
#include<cstdlib>

Food::Food() {
	// 随机生成食物的初始位置 
	x = rand() % 39 + 1;
	y = rand() % 22 + 1;
}

// 绘制食物的函数
void Food::drawFood() {
	// 设置食物位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// 设置食物的颜色为红色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << '*';
	// 恢复控制台文本颜色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int Food::getX() {
	return this->x;
}

void Food::setX(int a) {
	this->x = a;
}

int Food::getY() {
	return this->y;
}

void Food::setY(int a) {
	this->y = a;
}