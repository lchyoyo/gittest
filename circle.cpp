//以程序的逻辑来表述程序运行时的行为
//程序不同地方重复使用的代码用函数进行封装
//核心算法用一个函数进行封装

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
Point pos;//当前光标位置
Point cir[180];//同色小球坐标
int index = 0;;//同色小球的索引
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
	//画矩形
	setlinecolor(RGB(50,50,50));
	setlinestyle(PS_SOLID, 10);
	rectangle(255, 45, 745, 655);
	//绘制小球
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
	//绘制光标
	pos.x = 480;
	pos.y = 390;
	drawcursor(pos, RGB(255, 255, 255));
	//绘制时间
	drawtext(30);
	//绘制分数
	drawscore(0);
}

void gameplay()
{
	while (1)
	{
		if (Key_Down(VK_UP) && pos.y > 70)
		{
			//障眼法
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
		//消除,类似之前的障眼法
		if (Key_Down(VK_SPACE) || Key_Down(VK_RETURN))
		{
			//获得光标周围同色小球的坐标并存入数组，记录索引

			//将数组中的元素置黑
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
	settextstyle(25, 0, _T("黑体"));
	_stprintf(str, _T("剩余时间，%d s"), sec);
	outtextxy(20,50,str);
}

void drawscore(int score)
{
	TCHAR str[40];
	settextcolor(RGB(255, 0, 0));
	settextstyle(25, 0, _T("黑体"));
	_stprintf(str, _T("分数:%d "), score);
	outtextxy(20, 600, str);
}

void getsamecolorballs(Point p[180])
{

}