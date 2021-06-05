#include<stdio.h>

int main()
{
	int i = 1;
	int j = 1;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", i, j, i * j);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}