
#include"game1.h"

void menu()
{
	printf("***********************\n");
	printf("******    1.play   ****\n");
	printf("******    0.exit   ****\n");
	printf("***********************\n");
}

void game()
{
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//打印棋盘
	/*displayboard(mine, ROW, COL);*/
	displayboard(show, ROW, COL);
	//布置雷扫雷
	setmine(mine,ROW,COL);
	displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine, show, ROW, COL);
}


void test()
{
	int input = 0;
	rand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏。\n");
			break;
		default:
			printf("选择错误，请重新选择。\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	
	return 0;
}