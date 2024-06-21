#include "snake.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Food.h"
using namespace std;
// Snake��Ĺ��캯�������ó�ʼλ�úͷ��� 
Snake::Snake(int x, int y, char direction) : x(x), y(y), direction(direction){
	snakParts.push_back({ x, y });// ��ʼ������ 
}

void Snake::move(){
	int nextX = snakParts[0].x;
	int nextY = snakParts[0].y;
	// ���ݵ�ǰ���������һ��λ��
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

	// ���֮ǰ������
	for (int i = 0; i < snakParts.size(); i++)
	{
		int x = snakParts[i].x;
		int y = snakParts[i].y;
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << ' ';
	}
	// �ж���Ϸ�Ƿ����
	if (nextX <= 0 || nextX >= 40 || nextY <= 0 || nextY >= 25 || findPart(nextX, nextY)){
		this->gameOver = true;
	}
	else
	{
		// ���������λ��
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

// �����Ϸ�Ƿ����
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

// �����ߵ��ƶ�����
void Snake::setDirection(char direction){
	//�����෴���ı�ԭ����
	if ((this->direction == 'w'&&direction == 's') || (this->direction == 's'&&direction == 'w') || (this->direction == 'a'&&direction == 'd') || (this->direction == 'd'&&direction == 'a')){
		return;
	}
	this->direction = direction;
}

// ���������Ƿ����ָ��λ��
bool Snake::findPart(int x, int y){
	for (int i = 0; i < snakParts.size(); i++){
		if (snakParts[i].x == x&&snakParts[i].y == y) return true;
	}
	return false;
}

// ��ȡ��ǰ�ƶ�����
char Snake::getDirection(){
	return this->direction;
}

// Snake���Ĭ�Ϲ��캯��
Snake::Snake() {
	snakParts.push_back({ x, y }); // ��ʼ������
	this->direction = 'w';// ��ʼ����Ϊ����
	this->gameOver = false;// ��Ϸδ���� 
}

// ������
void Snake::drawSnake() {
	for (int i = 0; i < snakParts.size(); i++) {
		if (i == 0) {
			int x = snakParts[i].x;
			int y = snakParts[i].y;
			COORD pos = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			cout << '$'; // ��ͷ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else {
			int x = snakParts[i].x;
			int y = snakParts[i].y;
			COORD pos = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			cout << 'O'; // ���� 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}