#include"Food.h"
#include <Windows.h>
#include <iostream>
using namespace std;
#include<cstdlib>

Food::Food() {
	// �������ʳ��ĳ�ʼλ�� 
	x = rand() % 39 + 1;
	y = rand() % 22 + 1;
}

// ����ʳ��ĺ���
void Food::drawFood() {
	// ����ʳ��λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ����ʳ�����ɫΪ��ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << '*';
	// �ָ�����̨�ı���ɫ
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