#include "game.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Food.h"
using namespace std;

// ��ȡ��Ϸ��ǰ״̬
int game::getStatus(){
	return this->status;
}

// ������Ϸ״̬
void game::setStatus(int a){
	this->status = a;
}

// ��ȡ�˵�����
int game::getMenuCount(){
	return this->menuCount;
}

// ���ò˵�����
void game::setMenuCount(int a){
	this->menuCount = a;
}

// ��Ϸ��Ĺ��캯��
game::game(){
	this->status = 0; // ��״̬��ʼ��Ϊ 0
	this->menuCount = 0;// ���˵�������ʼ��Ϊ 0
	this->hardLevle = 700; // ���Ѷȼ����ʼ��Ϊ 700ms
}

// ��ȡ��Ϸ���Ѷȼ���
int game::getHardLevel(){
	return this->hardLevle;
}
// ������Ϸ���Ѷȼ���
void game::setHardLevel(int level){
	this->hardLevle = level;
}

// ���Ƶ�ǰ�汾��Ϣ
void game::drawVersion() {
	COORD pos = { 13, 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);  // ���ù��λ��
	cout << "Press any key to exit(but not Space)";// ��ʾ��Ϣ

	COORD pos2 = { 13, 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
	cout << "��ǰ�汾:";// ��ʾ��ǰ�汾��Ϣ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "0.1.0";// ��ʾ��Ϸ�汾
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	if (_kbhit()) { // ����Ƿ��м�������
		system("cls");// ��տ���̨��Ļ
		setMenuCount(0); // ���ò˵�����,��ҳ����ת
	}
}

// ������Ϸ����ı߿�
void game::drawBoder() {
	for (int x = 0; x < 41; x++) {
		COORD pos1 = { x, 0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
		// ���ÿ���̨�ı���ɫΪ��ɫ
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);// ���ÿ���̨�ı���ɫ
}
