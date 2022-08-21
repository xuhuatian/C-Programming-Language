/*
* 贪吃蛇
* 2022.8.21
* 需要eazyx库
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<graphics.h>
#define SNAKE_NUM 500 //蛇的最大长度
#define MAP_HIGHT 640 //地图宽度
#define MAP_WITH 640 //地图宽度

//蛇的方向
enum DIR
{
	UP,DOWN,LEFT,RIGHT
};

//蛇的结构体
struct Snake
{
	int size;//蛇的长度
	enum DIR dir;//方向
	int speed;//移动速度
	POINT coor[SNAKE_NUM];//蛇的身体
}snake;
//食物结构
struct Food
{
	//位置
	int x;
	int y;
	
	bool flag;//存活状态
	int R;//食物半径
	DWORD color;//食物颜色
}food;

//数据初始化
void GameInit()
{
	//初始化图形界面
	initgraph(MAP_WITH, MAP_HIGHT,/*,SHOWCONSOLE*/);
	//设置随机种子数，用于生成食物,从开机到现在经过的时间
	srand(GetTickCount());
	snake.size = 3;//蛇的初始长度
	snake.dir = RIGHT;//蛇的初始方向
	snake.speed = 10;//蛇的速度
	//蛇的初始位置
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
	}
	//初始化食物
	food.x = rand() % MAP_WITH;
	food.y = rand() % MAP_HIGHT;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.R = rand() % 5 + 5;
	food.flag = true;
}

void GameDraw()
{
	BeginBatchDraw();//双缓冲绘图，防闪屏

	setbkcolor(RGB(28, 115, 119));//背景颜色
	cleardevice();
	//绘制蛇
	setfillcolor(RED);//蛇的颜色
	for (int i = snake.size; i >= 0; i--)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	//绘制食物
	if (food.flag)
	{
		solidcircle(food.x, food.y, food.R);
	}
	EndBatchDraw();//双缓冲绘图结束，防闪屏
}

void Snake_Move()
{
	//让后一节身体跟着前一节
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];

	}
	//蛇头移动，穿墙
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y-=snake.speed;
		if (snake.coor[0].y <= 0)
		{
			snake.coor[0].y = MAP_HIGHT;
		}
		break;
	case DOWN:
		snake.coor[0].y+= snake.speed;
		if (snake.coor[0].y > MAP_HIGHT)
		{
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:
		snake.coor[0].x-= snake.speed;
		if (snake.coor[0].x <= 0)
		{
			snake.coor[0].x = MAP_WITH;
		}
		break;
	case RIGHT:
		snake.coor[0].x+= snake.speed;
		if (snake.coor[0].x > MAP_WITH)
		{
			snake.coor[0].x = 0;
		}
		break;
	}

}

//通过按键改变蛇的移动方向
void keyControl()
{
	if (_kbhit())//判断有没有键盘输入，如果有就返回真
	{
		//改变蛇头方向，但蛇头不能反方向移动
		//72 80 75 77 上下左右的键值
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			if(snake.dir!=DOWN)
				snake.dir = UP;
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP)
				snake.dir = DOWN;
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT)
				snake.dir = LEFT;
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT)
				snake.dir = RIGHT;
			break;
		case ' '://按空格暂停游戏，再按空格开始
			while (1)
			{
				if (_getch() == ' ')
					break;
			}
			break;
		}
	}
	
}
//蛇吃食物
void EatFood()
{
	if (snake.coor[0].x >= food.x - food.R && snake.coor[0].x <= food.x + food.R &&
		snake.coor[0].y >= food.y - food.R && snake.coor[0].y <= food.y + food.R)
	{
		food.flag = false;
		snake.size++;
		 
	}
	//吃完后，食物重新生成
	if (!food.flag)
	{
		food.x = rand() % MAP_WITH;
		food.y = rand() % MAP_HIGHT;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.R = rand() % 5 + 5;
		food.flag = true;
	}
}
//蛇吃到自己死亡,或到达最大长度
void Finish()
{
	//碰到身体
	for (int i = snake.size; i > 0; i--)
	{
		if (snake.coor[0].x == snake.coor[i].x &&
			snake.coor[0].y == snake.coor[i].y)
		{
			outtextxy(MAP_WITH / 3, MAP_HIGHT / 2, L"你输了，正在退出游戏。");
			Sleep(1500);
			exit(-1);
		}
	}
	//达到最大长度
	if (snake.size >= SNAKE_NUM)
	{
		outtextxy(MAP_WITH / 3, MAP_HIGHT / 2, L"恭喜你，你赢了，正在退出游戏。");
		Sleep(1500);
		exit(-1);
	}
}
int main()
{
	GameInit();//数据初始化
	
	//GameDraw();//生成图形
	while (1)
	{
		Snake_Move();
		GameDraw();//生成图形
		keyControl();
		EatFood();
		Finish();
		Sleep(200);
	}

	return 0;
}