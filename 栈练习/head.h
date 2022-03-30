#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int STDateType;


typedef struct Stack
{
	STDateType* a;	//存储数据
	int top;		//已存储的数据量
	int capacity;	//当前的数据容量
}ST;

void StackInit(ST* ps);//初始化栈
void StackDetory(ST* ps);//销毁栈

void StackPush(ST* ps,STDateType x);//插入数据到栈顶
void StackPop(ST* ps);//删除栈顶数据

STDateType StackTop(ST* ps);//得到栈顶数据

int StackSize(ST* ps);//当前存储是数据量
int StackEmpty(ST* ps);//栈是否为空