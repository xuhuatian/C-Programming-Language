#include"head.h"

//初始化栈
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDateType*)malloc(sizeof(STDateType) * 4);
	//判断是否为创建成功
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		ps->capacity = 4;
		ps->top = 0;
	}

}

//销毁栈
void StackDetory(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

//插入数据到栈顶
void StackPush(ST* ps, STDateType x)
{
	assert(ps);
	//判断剩余空间是否充足
	if (ps->capacity <= ps->top)
	{
		STDateType* tmp = (STDateType*)realloc(ps->a, sizeof(STDateType) * ps->capacity * 2);
		if (tmp != NULL)
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//删除栈顶数据
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//得到栈顶数据
STDateType StackTop(ST* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];
}

//当前存储是数据量
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

//栈是否为空
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;

}




