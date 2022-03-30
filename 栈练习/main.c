#include"head.h"


int main()
{
	ST ps;
	StackInit(&ps);

	//插入数据
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);

	//输出数据
	while (!StackEmpty(&ps))
	{
		printf("%d ", StackTop(&ps));
		StackPop(&ps);
	}
	printf("\n");

	//销毁栈
	StackDetory(&ps);
	return 0;
}