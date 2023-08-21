#include "SList.h"


void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//malloc出来的空间不销毁
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushback(SLTNode** pphead, SLTDataType x)
{
	//1.空
	//2.找到尾之前的那个结点
	SLTNode* newnode=BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}
void SListPushfront(SLTNode** pphead, SLTDataType x)
{
	//空
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;//多画图
}
void SListPopfront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	
}