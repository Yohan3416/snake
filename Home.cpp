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
// ������ҳ�˵��ĺ���
void Home::drawMenu() {
	// ���ÿ���̨���λ�ü��������
	COORD pos = { 15, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "��ҳ�˵�";

	COORD pos2 = { 15, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	if (this->tempCount == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "��ʼ��Ϸ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos3 = { 15, 6 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos3);
	if (this->tempCount == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "�Ѷ�����";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	COORD pos4 = { 15, 8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos4);
	if (this->tempCount == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "�汾��Ϣ";
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
// ����tempCount��ֵ
void Home::settempCount(int a) {
	this->tempCount = a;
}
// ��ȡtempCount��ֵ
int Home::gettempCount(){
	return this->tempCount;
}
// ����tempCount��ֵ
void Home::increaseCount() {
	this->tempCount++;
	if (tempCount > 3) tempCount = 3;
}
// ����tempCount��ֵ
void Home::decreaseCount() {
	this->tempCount--;
	if (tempCount < 0) tempCount = 0;
}