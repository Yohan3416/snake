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
	int SetCount;//������ʱ�洢�Ѷȵȼ������û����¿ո�ѡ��󣬴�������hardLevel
};
