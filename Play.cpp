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
	// 初始化上一次移动时间为0
	DWORD lastMoveTime = 0;

	const int SCREEN_WIDTH = 41;
	const int SCREEN_HEIGHT = 26;

	// 初始化蛇、食物、游戏、设置和主页对象
	Snake snake(15, 15, 'd');
	Food food;
	game Game;
	Setting setting;
	Home menu;
	// 生成随机食物坐标
	food.setX( rand() % SCREEN_WIDTH);
	food.setY( rand() % SCREEN_HEIGHT);
	while (true)
	{	// 游戏状态为进行中
		if (Game.getStatus() == 1) {
			Game.drawBoder();
			food.drawFood();
			snake.drawSnake();

			char key;
			if (_kbhit()) {
				key = _getch();
				snake.setDirection(key);
			}
			// 控制蛇移动速度
			if (GetTickCount64() - lastMoveTime >= Game.getHardLevel()) {
				snake.move();
				snake.drawSnake();
				lastMoveTime = GetTickCount64();
			}
			// 处理吃到食物的情况
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
				// 重新生成食物坐标
				food.setX(rand() % 39 + 1);
				food.setY(rand() % 22 + 1);
			}

			// 处理游戏结束情况
			if (snake.isGameOver()) {
				system("cls");
				Game.setStatus(2);
				Game.setMenuCount(0);
			}
		}
		else if (Game.getStatus() == 2) {
			cout << "失败了，你的最终长度:" << snake.snakParts.size() << endl;
			cout << "5秒后回到主页" << endl;
			//重新获取新的food和snake，改变上一局失败的状态
			food = Food();
			snake = Snake();
			Sleep(5000);
			system("cls");
			Game.setStatus(0);
		}
		else {
			// 处理主菜单部分逻辑
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
				setting.drawSetting(&Game); // 显示设置界面
			}
			else if (Game.getMenuCount() == 1) {
				Game.setStatus(1); // 显示版本信息
			}
			else if (Game.getMenuCount() == 3) {
				Game.drawVersion(); // 显示主菜单
			}
			else {
				menu.drawMenu();
			}
		}
	}

}