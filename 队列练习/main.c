#include"head.h"

void Test()
{
	QN qp;
	QueueInit(&qp);
	QueuePush(&qp, 1);
	QueuePush(&qp, 2);
	QueuePush(&qp, 3);
	QueuePush(&qp, 4);
	QueuePush(&qp, 5);
	QueuePush(&qp, 6);

	while (!QueueEmpty(&qp))
	{
		printf("%d ", QueueFront(&qp));
		QueuePop(&qp);
	}
	printf("\n");
	QueueDestory(&qp);
	return;

}

int main()
{
	Test();
	return 0;
}