#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct node
{
	int date;
	struct node* pnext;
};
struct node* create_list(void);
void traverse_list(struct node*);


int main()
{
	struct node* phead = NULL;
	int val;

	phead = create_list();
	traverse_list(phead);
	
	return 0;
}
struct node* create_list(void)
{
	int len;
	int i;
	int val;

	struct node* phead = (struct node*)malloc(sizeof(struct node));
	if (NULL == phead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);//终止程序。
	}
	struct node* pTail = phead;
	pTail->pnext = NULL;

	printf("请输入您需要的链表节点的个数：len = ");
	scanf("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个节点的值：", i + 1);
		scanf("%d", &val);

		struct node* pnew = (struct node*)malloc(sizeof(struct node));
		if (NULL == pnew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pnew->date = val;
		pTail->pnext = pnew;
		pnew->pnext = NULL;
		pTail = pnew;

	}
	return phead;
}
void traverse_list(struct node* phead)
{
	struct node* p = phead->pnext;

	while (NULL != p)
	{
		printf("%d ", p->date);
		p = p->pnext;
	}
	printf("\n");

	return;

}