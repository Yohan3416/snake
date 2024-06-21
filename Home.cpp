#include "Home.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h>
using namespace std;
Home::Home() {
	this->tempCount = 0;
}
// 绘制主页菜单的函数
void Home::drawMenu() {
	// 设置控制台光标位置及内容输出
	COORD pos = { 15, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "主页菜单";

	COORD pos2 = { 15, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	if (this->tempCount == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "开始游戏";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos3 = { 15, 6 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
	if (this->tempCount == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "难度设置";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos4 = { 15, 8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos4);
	if (this->tempCount == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "版本信息";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos5 = { 15, 10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "Press";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "Space";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "to choose options, ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "'w'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "and";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "'s'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "to change.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
// 设置tempCount的值
void Home::settempCount(int a) {
	this->tempCount = a;
}
// 获取tempCount的值
int Home::gettempCount(){
	return this->tempCount;
}
// 增加tempCount的值
void Home::increaseCount() {
	this->tempCount++;
	if (tempCount > 3) tempCount = 3;
}
// 减少tempCount的值
void Home::decreaseCount() {
	this->tempCount--;
	if (tempCount < 0) tempCount = 0;
}