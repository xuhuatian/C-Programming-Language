#include<stdio.h>

int main()
{
	int n = 20;
	int a;//�м�ֵ

	double sum = 0;//���õ����

	for (; n >= 1; n--)
	{
		int b = 1;//Сѭ�����м�ֵ

		for (a = n; a >= 1; a--)
		{
			b = b * a;	
		}

		sum += b;
	}

	printf("�����%f\n", sum);

	return 0;
}