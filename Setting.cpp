#include "Setting.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h>
using namespace std;
// 绘制设置界面，包括选择难度
void Setting::drawSetting(game* Game){
	COORD pos = { 13, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "难度选择";

	COORD pos2 = { 15, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	if (SetCount == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "简单";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos3 = { 15, 6 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
	if (SetCount == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "普通";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos4 = { 15, 8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos4);
	if (SetCount == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "困难";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos5 = { 15, 10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "Press Space to choose";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	if (_kbhit()){
		char key = _getch();
		switch (key)
		{
		case 'w':
			SetCount--;
			SetCount = max(1, SetCount);
			break;
		case 's':
			SetCount++;
			SetCount = min(3, SetCount);
			break;
		case ' ':
			system("cls");
			Game->setHardLevel(1000 - 300 * SetCount); // 根据选择设置游戏难度级别
			Game->setMenuCount(0);// 重置菜单计数，切换到主界面
			break;
		default:
			break;
		}
	}
}

// 设置类的构造函数，初始化难度值为1（默认为简单难度）
Setting::Setting(){
	this->SetCount = 1;
}

// 设置难度值
void Setting::setSetCount(int a){
	this->SetCount = a;
}
// 获取难度值
int Setting::getSetCount(){
	return this->SetCount; 
}