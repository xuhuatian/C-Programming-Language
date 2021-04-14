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

	printf("请输入学生人数：");
	printf("len = ");
	scanf("%d", &len);
	aprr = (struct student*)malloc(len * sizeof(struct student));

	//输入
	for (a = 0; a < len; a++)
	{
		printf("请输入第%d个学生的信息:\n", a + 1);

		printf("年龄：");
		scanf("%d", &aprr[a].age);

		printf("分数：");
		scanf("%f", &aprr[a].score);

		printf("名字：");
		scanf("%s", aprr[a].name);//name是数组名，本身就已经是数组首元素的地址。

		printf("\n");
	}
	//排序
	for (a = 0; a < len - 1; a++)
	{
		for (int i = 0; i < len - 1 - a; i++)
		{
			if ((aprr + i)->score < aprr[i + 1].score)//这里填 < 就是重大到小，填 > 就是从小到大。
			{
				struct student st = aprr[i + 1];
				aprr[i + 1] = aprr[i];
				aprr[i] = st;
			}
		}
	}

	//输出
	for (a = 0; a < len; a++)
	{
		printf("成绩排第%d的学生的信息:\n", a + 1);

		printf("年龄：%d ", aprr[a].age);

		printf("分数：%f ", aprr[a].score);

		printf("名字：%s", aprr[a].name);

		printf("\n");
	}
	return 0;
}