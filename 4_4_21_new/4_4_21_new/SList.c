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
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//malloc�����Ŀռ䲻����
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushback(SLTNode** pphead, SLTDataType x)
{
	//1.��
	//2.�ҵ�β֮ǰ���Ǹ����
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
	//��
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;//�໭ͼ
}
void SListPopfront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	
}
void SListPopback(SLTNode** pphead)
{
	assert(*pphead);
	assert(pphead);
	SLTNode* tail = *pphead;
	SLTNode* prev = NULL;

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}	
}
SLTNode* SListfind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("δ�ҵ�\n");
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	//ͷ��
	if (pos == *pphead)
	{
		SListPushfront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	//ͷɾ
	//֪��ǰһ����ַ
	assert(pphead);
	assert(pos);
	SLTNode* prev = NULL;
	if (*pphead == pos)
	{
		SListPopfront(pphead);
	}
	else
	{
		prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
	}
}

void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	//ͷ��
	if (pos == *pphead)
	{
		SListPushfront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		newnode->next = pos->next;
		pos->next = newnode;

	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* temp = pos->next;
		pos->next = temp->next;//pos->next=  pos->n ->n
		free(temp);//pos->nextԭλ��
		temp = NULL;
	}
}














