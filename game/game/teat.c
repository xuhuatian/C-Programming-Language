
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
	//�׵���Ϣ�洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//��ӡ����
	/*displayboard(mine, ROW, COL);*/
	displayboard(show, ROW, COL);
	//������ɨ��
	setmine(mine,ROW,COL);
	displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine, show, ROW, COL);
}


void test()
{
	int input = 0;
	rand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	
	return 0;
}