#include<stdio.h>
#include<malloc.h>

struct student
{
	int age;
	float score;
	char name[100];
};

int main()
{
	int len;
	struct student* aprr;
	int a = 0;

	printf("������ѧ��������");
	printf("len = ");
	scanf("%d", &len);
	aprr = (struct student*)malloc(len * sizeof(struct student));

	//����
	for (a = 0; a < len; a++)
	{
		printf("�������%d��ѧ������Ϣ:\n", a + 1);

		printf("���䣺");
		scanf("%d", &aprr[a].age);

		printf("������");
		scanf("%f", &aprr[a].score);

		printf("���֣�");
		scanf("%s", aprr[a].name);//name����������������Ѿ���������Ԫ�صĵ�ַ��

		printf("\n");
	}
	//����
	for (a = 0; a < len - 1; a++)
	{
		for (int i = 0; i < len - 1 - a; i++)
		{
			if ((aprr + i)->score < aprr[i + 1].score)//������ < �����ش�С���� > ���Ǵ�С����
			{
				struct student st = aprr[i + 1];
				aprr[i + 1] = aprr[i];
				aprr[i] = st;
			}
		}
	}

	//���
	for (a = 0; a < len; a++)
	{
		printf("�ɼ��ŵ�%d��ѧ������Ϣ:\n", a + 1);

		printf("���䣺%d ", aprr[a].age);

		printf("������%f ", aprr[a].score);

		printf("���֣�%s", aprr[a].name);

		printf("\n");
	}
	return 0;
}