#include<stdio.h>

void sort(int* a,int len)
{
	int i, j, t;

	for (i = 0; i < (len - 1); i++)
	{
		for (j = 0; j < (len - 1 - i); j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int main()
{

	int a[5] = { -100,0,-9,-4,3 };

	int i = 0;

	sort(a, 5);

	for (i = 0; i <= 4; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}