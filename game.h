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
	int status;//status����ֵ����statusΪ0ʱΪ�˵�ҳ��
			   //��statusΪ1ʱΪ��Ϸҳ�棬������menuCount == 1ʱ�Ż����statusΪ1
			   //��statusΪ2ʱΪʧ�ܷ���ҳ��
	int menuCount;//0:�˵�ҳ�� 1:��Ϸҳ�� 2:�Ѷ�����ҳ�� 3:�汾��Ϣҳ��
	int hardLevle;//�Ѷȵȼ�������ֵ1 2 3 Ĭ��Ϊ1��
};
#endif