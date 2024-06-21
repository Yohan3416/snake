#include "game.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Food.h"
using namespace std;

// 获取游戏当前状态
int game::getStatus(){
	return this->status;
}

// 设置游戏状态
void game::setStatus(int a){
	this->status = a;
}

// 获取菜单计数
int game::getMenuCount(){
	return this->menuCount;
}

// 设置菜单计数
void game::setMenuCount(int a){
	this->menuCount = a;
}

// 游戏类的构造函数
game::game(){
	this->status = 0; // 将状态初始化为 0
	this->menuCount = 0;// 将菜单计数初始化为 0
	this->hardLevle = 700; // 将难度级别初始化为 700ms
}

// 获取游戏的难度级别
int game::getHardLevel(){
	return this->hardLevle;
}
// 设置游戏的难度级别
void game::setHardLevel(int level){
	this->hardLevle = level;
}

// 绘制当前版本信息
void game::drawVersion() {
	COORD pos = { 13, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);  // 设置光标位置
	cout << "Press any key to exit(but not Space)";// 显示消息

	COORD pos2 = { 13, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	cout << "当前版本:";// 显示当前版本信息
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "0.1.0";// 显示游戏版本
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	if (_kbhit()) { // 检测是否有键盘输入
		system("cls");// 清空控制台屏幕
		setMenuCount(0); // 重置菜单计数,让页面跳转
	}
}

// 绘制游戏界面的边框
void game::drawBoder() {
	for (int x = 0; x < 41; x++) {
		COORD pos1 = { x, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
		// 设置控制台文本颜色为蓝色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
		cout << '#';
		COORD pos2 = { x, 25 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
		cout << '#';
	}

	for (int y = 0; y < 26; y++) {
		COORD pos1 = { 0, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
		cout << '#';
		COORD pos2 = { 40, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
		cout << '#';
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);// 重置控制台文本颜色
}
