class Home
{
public:
	Home();
	void drawMenu();
	int gettempCount();
	void settempCount(int a);
	void increaseCount();//ÿһ����tempCount��1�����ǲ�����3
	void decreaseCount();//ÿһ����tempCount��1�����ǲ�С��0
private:
	int tempCount;//������ʱ�洢�˵���״̬������Space����Game.setMenuCount(menu.gettempCount());���ı�˵�����ʾ����
};

