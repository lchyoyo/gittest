//�Գ�����߼���������������ʱ����Ϊ
//����ͬ�ط��ظ�ʹ�õĴ����ú������з�װ
//�����㷨��һ���������з�װ

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>

void init();
void gamebegin();
void gameplay();
void close();
typedef struct Point
{
	int x;
	int y;
}Point;
void drawcursor(Point p, COLORREF cl);
void drawtext(int sec);
void drawscore(int score);
Point pos;//��ǰ���λ��
Point cir[180];//ͬɫС������
int index = 0;;//ͬɫС�������
#define Key_Down(vk_c) (GetAsyncKeyState(vk_c)&0x8000)

const COLORREF color[6] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255),
RGB(255, 255, 0), RGB(255, 0, 255), RGB(0, 255, 255) };


int main()
{
	init();
	gamebegin();
	gameplay();
	close();
	return 0;
}

void init()
{
	initgraph(1000,700);
}
void gamebegin()
{
	//������
	setlinecolor(RGB(50,50,50));
	setlinestyle(PS_SOLID, 10);
	rectangle(255, 45, 745, 655);
	//����С��
	srand((unsigned) time(NULL));
	for (int i = 280; i < 760; i += 40)
	{
		for (int j = 70; j < 670; j += 40)
		{
			setlinestyle(PS_SOLID, 1);
			setlinecolor(color[rand()%6]);
			setfillcolor(color[rand() % 6]);
			fillcircle(i, j, 18);
		}
	}
	//���ƹ��
	pos.x = 480;
	pos.y = 390;
	drawcursor(pos, RGB(255, 255, 255));
	//����ʱ��
	drawtext(30);
	//���Ʒ���
	drawscore(0);
}

void gameplay()
{
	while (1)
	{
		if (Key_Down(VK_UP) && pos.y > 70)
		{
			//���۷�
			//pos.x += 40;
			drawcursor(pos, RGB(0, 0, 0));
			pos.y -= 40;
			drawcursor(pos, RGB(255, 255, 255));
		}
		if (Key_Down(VK_DOWN) && pos.y<630)
		{
			//pos.x += 40;
			drawcursor(pos, RGB(0, 0, 0));
			pos.y += 40;
			drawcursor(pos, RGB(255, 255, 255));
		}
		if (Key_Down(VK_LEFT) && pos.x>280)
		{
			drawcursor(pos, RGB(0, 0, 0));
			pos.x -= 40;
			//pos.y += 40;
			drawcursor(pos, RGB(255, 255, 255));
		}
		if (Key_Down(VK_RIGHT) && pos.x < 720)
		{
			drawcursor(pos, RGB(0, 0, 0));
			pos.x += 40;
			//pos.y += 40;
			drawcursor(pos, RGB(255, 255, 255));
		}
		//����,����֮ǰ�����۷�
		if (Key_Down(VK_SPACE) || Key_Down(VK_RETURN))
		{
			//��ù����ΧͬɫС������겢�������飬��¼����

			//�������е�Ԫ���ú�
			for (int i = 0; i < index; ++i)
			{
				setlinecolor(RGB(0, 0, 0));
				setfillcolor(RGB(0, 0, 0));
				fillcircle(cir[i].x,cir[i].y,20);
			}

			index = 0;
		}

		if (Key_Down(VK_ESCAPE))
			break;
		Sleep(80);
	}
}

void close()
{
	getch();
	closegraph();
}

void drawcursor(Point p,COLORREF cl)
{
	setlinecolor(cl);
	rectangle(p.x - 20, p.y - 20, p.x + 20,p.y + 20);
}

void drawtext(int sec)
{
	TCHAR str[40];
	settextcolor(RGB(255, 255, 0));
	settextstyle(25, 0, _T("����"));
	_stprintf(str, _T("ʣ��ʱ�䣬%d s"), sec);
	outtextxy(20,50,str);
}

void drawscore(int score)
{
	TCHAR str[40];
	settextcolor(RGB(255, 0, 0));
	settextstyle(25, 0, _T("����"));
	_stprintf(str, _T("����:%d "), score);
	outtextxy(20, 600, str);
}

void getsamecolorballs(Point p[180])
{

}