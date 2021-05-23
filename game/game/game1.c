#include"game1.h"


void initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void displayboard(char board[ROWS][COLS], int  row, int col)
{
	int i = 1;
	int j = 1;
	printf("  ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//1-9

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] + mine[x - 1][y] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0; 
	int q = 1;
	while (q)
	{
		
		printf("�������Ų��׵����꣺");
		scanf_s("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			q = 0; 
			//1.����
			if (mine[x][y] == '1')
			{
				printf("��ȵ����ˣ�\n");
				displayboard(mine, row, col);
				break;
			}
			else//������
			{
				//����mine[x][y]��Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show, row, col);
			}



		}
		else
		{
			printf("��������Ƿ������������룡\n");
			
		}
	}



}