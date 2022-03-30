#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType a;
	
}QN;

//队列头部和尾部
typedef struct Queue
{
	QN* head;//头部
	QN* tail;//尾部
}Queue;


void QueueInit(Queue* qp);//初始化队列
void QueueDestory(Queue* qp);//销毁队列

void QueuePush(Queue* qp,QDataType x);//队尾入
void QueuePop(Queue* qp);//队首出

QDataType QueueFront(Queue* qp);//获取队首的数据
QDataType QueueBack(Queue* qp);//获取队尾的数据

int QueueSize(Queue* qp);//获取队列长度
int QueueEmpty(Queue* qp);//判断队列是否为空

