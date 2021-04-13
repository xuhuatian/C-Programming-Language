#include<stdio.h>

int main()
{
	int n = 20;
	int a;//中间值

	double sum = 0;//最后得到结果

	for (; n >= 1; n--)
	{
		int b = 1;//小循环的中间值

		for (a = n; a >= 1; a--)
		{
			b = b * a;	
		}

		sum += b;
	}

	printf("结果：%f\n", sum);

	return 0;
}