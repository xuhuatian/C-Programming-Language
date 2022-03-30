#include"head.h"


//初始化队列
void QueueInit(Queue* qp)
{
	assert(qp);
	qp->head = qp->tail = NULL;
}

//销毁队列
void QueueDestory(Queue* qp)
{
	assert(qp);
	
	QN* tmp = qp->head;
	while (tmp)
	{
		QN* t = tmp->next;
		free(tmp);
		tmp = t;
	}
	qp->head = qp->tail = NULL;
	
	
	
}

//队尾入
void QueuePush(Queue* qp, QDataType x)
{
	assert(qp);
	QN* tmp = (QN*)malloc(sizeof(QN));

	if (tmp == NULL)//检查创建是否成功
	{
		printf("QueuePush malloc fail\n");
		exit(-1);
	}
	tmp->next = NULL;
	tmp->a = x;

	if (qp->tail == NULL)//如果队列没有数据
	{
		qp->tail = tmp;
		qp->head = tmp;
		return;
	}
	qp->tail->next = tmp;
	qp->tail = qp->tail->next;

}

//队首出
void QueuePop(Queue* qp)
{
	assert(qp);
	if (qp->head == NULL)//如果队列本来就是空的
	{
		return;
	}
	
	if (qp->head->next == NULL)//只有一个节点
	{
		free(qp->head);
		qp->head = qp->tail = NULL;
		return;
	}
	QN* tmp = qp->head;
	qp->head = qp->head->next;
	free(tmp);
	tmp = NULL;
	
}

//获取队首的数据
QDataType QueueFront(Queue* qp)
{
	assert(qp);
	assert(qp->head);
	return qp->head->a;

}

//获取队尾的数据
QDataType QueueBack(Queue* qp)
{
	assert(qp);
	assert(qp->head);
	return qp->tail->a;
}

//获取队列长度
int QueueSize(Queue* qp)
{
	assert(qp);
	int size = 0;
	QN* tmp = qp->head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}

//判断队列是否为空
int QueueEmpty(Queue* qp)
{
	assert(qp);
	return qp->head == NULL;
}
