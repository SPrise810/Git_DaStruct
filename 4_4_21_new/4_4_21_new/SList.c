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
void SListPushback(SLTNode** pphead, SLTDataType x)
{
	//1.��
	//2.�ҵ�β֮ǰ���Ǹ����
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//malloc�����Ŀռ䲻����
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
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