#include "Play.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Food.h"
#include "snake.h"
#include "game.h"
#include <math.h>
#include"Setting.h"
#include"Home.h"
using namespace std;

void Play::PlayGame() {
	// ��ʼ����һ���ƶ�ʱ��Ϊ0
	DWORD lastMoveTime = 0;

	const int SCREEN_WIDTH = 41;
	const int SCREEN_HEIGHT = 26;

	// ��ʼ���ߡ�ʳ���Ϸ�����ú���ҳ����
	Snake snake(15, 15, 'd');
	Food food;
	game Game;
	Setting setting;
	Home menu;
	// �������ʳ������
	food.setX( rand() % SCREEN_WIDTH);
	food.setY( rand() % SCREEN_HEIGHT);
	while (true)
	{	// ��Ϸ״̬Ϊ������
		if (Game.getStatus() == 1) {
			Game.drawBoder();
			food.drawFood();
			snake.drawSnake();

			char key;
			if (_kbhit()) {
				key = _getch();
				snake.setDirection(key);
			}
			// �������ƶ��ٶ�
			if (GetTickCount64() - lastMoveTime >= Game.getHardLevel()) {
				snake.move();
				snake.drawSnake();
				lastMoveTime = GetTickCount64();
			}
			// ����Ե�ʳ������
			if (snake.snakParts[0].x == food.getX() && snake.snakParts[0].y == food.getY()) {
				switch (snake.getDirection())
				{
				case 'w':
					snake.snakParts.push_back({ snake.tailX, snake.tailY + 1 });
					break;
				case 's':
					snake.snakParts.push_back({ snake.tailX, snake.tailY - 1 });
					break;
				case 'a':
					snake.snakParts.push_back({ snake.tailX + 1, snake.tailY });
					break;
				case 'd':
					snake.snakParts.push_back({ snake.tailX - 1, snake.tailY });
					break;
				default:
					break;
				}
				// ��������ʳ������
				food.setX(rand() % 39 + 1);
				food.setY(rand() % 22 + 1);
			}

			// ������Ϸ�������
			if (snake.isGameOver()) {
				system("cls");
				Game.setStatus(2);
				Game.setMenuCount(0);
			}
		}
		else if (Game.getStatus() == 2) {
			cout << "ʧ���ˣ�������ճ���:" << snake.snakParts.size() << endl;
			cout << "5���ص���ҳ" << endl;
			//���»�ȡ�µ�food��snake���ı���һ��ʧ�ܵ�״̬
			food = Food();
			snake = Snake();
			Sleep(5000);
			system("cls");
			Game.setStatus(0);
		}
		else {
			// �������˵������߼�
			if (_kbhit() && Game.getMenuCount() == 0) {
				char key = _getch();
				switch (key)
				{
				case 'w':
					menu.decreaseCount();
					break;
				case 's':
					menu.increaseCount();
					break;
				case ' ':
					system("cls");
					Game.setMenuCount(menu.gettempCount());
				default:
					break;
				}
			}
			if (Game.getMenuCount() == 2) {
				setting.drawSetting(&Game); // ��ʾ���ý���
			}
			else if (Game.getMenuCount() == 1) {
				Game.setStatus(1); // ��ʾ�汾��Ϣ
			}
			else if (Game.getMenuCount() == 3) {
				Game.drawVersion(); // ��ʾ���˵�
			}
			else {
				menu.drawMenu();
			}
		}
	}

}