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
//通过指针不断地转移，从而找到其余的空间进行打印
}
SLTNode* BuySListNode(SLTDataType x)//创建节点函数  
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
void SListPushFront(SLTNode** phead, SLTDataType x)//头插
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *phead;
	*phead = newnode;
	//如果初始地址为空那么也能够进行头插操作
}
void SListPopFront(SLTNode** pphead)  
{
	assert(pphead);
	assert(*pphead);
	//防止删除空列表，进行断言
	//release版本会忽略掉断言
	SLTNode* next =  (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	//如果只有一个结点怎么办呢，这第一个结点已经free掉了，那么我们就不存在next来指向NULL了
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
		//还存在第二种写法：
//从前往后找两个结点来删
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
	printf("未找到%d!", x);
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);//防止恶意输入NULL
	assert(pphead);//
	//头插
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else//中后任意位置
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
void SListErase(SLTNode** pphead, SLTNode* pos)//删除pos位置的值
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
		prev->next = pos->next;//把pos隔断
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

	//不在乎顺序的写法
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;//额外创建一个变量存储后面的的节点信息
	//以下二者顺序随意
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