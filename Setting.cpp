#include "Setting.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h>
using namespace std;
// �������ý��棬����ѡ���Ѷ�
void Setting::drawSetting(game* Game){
	COORD pos = { 13, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "�Ѷ�ѡ��";

	COORD pos2 = { 15, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	if (SetCount == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos3 = { 15, 6 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
	if (SetCount == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "��ͨ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos4 = { 15, 8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos4);
	if (SetCount == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "����";
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
			Game->setHardLevel(1000 - 300 * SetCount); // ����ѡ��������Ϸ�Ѷȼ���
			Game->setMenuCount(0);// ���ò˵��������л���������
			break;
		default:
			break;
		}
	}
}

// ������Ĺ��캯������ʼ���Ѷ�ֵΪ1��Ĭ��Ϊ���Ѷȣ�
Setting::Setting(){
	this->SetCount = 1;
}

// �����Ѷ�ֵ
void Setting::setSetCount(int a){
	this->SetCount = a;
}
// ��ȡ�Ѷ�ֵ
int Setting::getSetCount(){
	return this->SetCount; 
}