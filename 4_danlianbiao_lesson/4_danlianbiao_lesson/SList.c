#include"SList.h"
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
//ͨ��ָ�벻�ϵ�ת�ƣ��Ӷ��ҵ�����Ŀռ���д�ӡ
}
SLTNode* BuySListNode(SLTDataType x)//�����ڵ㺯��  
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	if(* pphead==NULL)
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
void SListPushFront(SLTNode** phead, SLTDataType x)//ͷ��
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *phead;
	*phead = newnode;
	//�����ʼ��ַΪ����ôҲ�ܹ�����ͷ�����
}
void SListPopFront(SLTNode** pphead)  
{
	assert(pphead);
	assert(*pphead);
	//��ֹɾ�����б����ж���
	//release�汾����Ե�����
	SLTNode* next =  (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//���ֻ��һ�������ô���أ����һ������Ѿ�free���ˣ���ô���ǾͲ�����next��ָ��NULL��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = NULL;
		SLTNode* next = *pphead;
		while ((next)->next != NULL)
		{
			tail = next;
			next = (next)->next;
		}
		free(next);
		tail->next = NULL;
		//�����ڵڶ���д����
//��ǰ���������������ɾ
//SLTNode* tail = *pphead;
//while (tail->next->next != NULL)
//{
//	tail = tail->next;
//}
//free(tail->next);
//tail->next = NULL;
	}
}
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
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
	printf("δ�ҵ�%d!", x);
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);//��ֹ��������NULL
	assert(pphead);//
	//ͷ��
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else//�к�����λ��
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev= prev->next;
		}
		SLTNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos)//ɾ��posλ�õ�ֵ
{
	assert(pphead);
	assert(*pphead);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;//��pos����
		free(pos);
		pos = NULL;
	}
}

void SListInsertAfter(SLTNode* pos,SLTDataType x)
{
	//assert(pos);
	//SLTNode* newnode = BuySListNode(x);
	//newnode->next = pos->next;
	//pos->next = newnode;

	//���ں�˳���д��
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;//���ⴴ��һ�������洢����ĵĽڵ���Ϣ
	//���¶���˳������
	pos->next=newnode;
	newnode->next = next;
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}