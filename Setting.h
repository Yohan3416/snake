#include "game.h"
class Setting
{
public:
	Setting();
	void drawSetting(game* Game);
	void setSetCount(int a);
	int getSetCount();
	int tempCount = 0;
private:
	int SetCount;//用于临时存储难度等级，当用户按下空格选择后，触发更新hardLevel
};
