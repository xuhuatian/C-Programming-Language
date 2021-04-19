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
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);//��ֹ����
	}
	struct node* pTail = phead;
	pTail->pnext = NULL;

	printf("����������Ҫ������ڵ�ĸ�����len = ");
	scanf("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("�������%d���ڵ��ֵ��", i + 1);
		scanf("%d", &val);

		struct node* pnew = (struct node*)malloc(sizeof(struct node));
		if (NULL == pnew)
		{
			printf("����ʧ�ܣ�������ֹ��\n");
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