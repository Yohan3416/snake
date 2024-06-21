class Home
{
public:
	Home();
	void drawMenu();
	int gettempCount();
	void settempCount(int a);
	void increaseCount();//每一次让tempCount加1，但是不超过3
	void decreaseCount();//每一次让tempCount减1，但是不小于0
private:
	int tempCount;//用于临时存储菜单的状态，按下Space调用Game.setMenuCount(menu.gettempCount());来改变菜单的显示内容
};

