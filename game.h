#ifndef _game_
#define _game_
class game
{
public:
	game();
	int getStatus();
	void setStatus(int a);
	int getMenuCount();
	void setMenuCount(int a);
	int getHardLevel();
	void setHardLevel(int level);
	void drawVersion();
	void drawBoder();
private:
	int status;//status三个值，当status为0时为菜单页面
			   //当status为1时为游戏页面，仅仅当menuCount == 1时才会更新status为1
			   //当status为2时为失败返回页面
	int menuCount;//0:菜单页面 1:游戏页面 2:难度设置页面 3:版本信息页面
	int hardLevle;//难度等级有三个值1 2 3 默认为1；
};
#endif