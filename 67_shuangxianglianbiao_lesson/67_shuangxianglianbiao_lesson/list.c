#include"list.h"
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node =(LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}
//void ListInit(LTNode** pphead)
//{		
//	*pphead = BuyListNode(-1);
//	(* pphead)->next = pphead;
//	(* pphead)->prev = pphead;
//} 
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev; //创建一个尾部指向 phead的尾部
	//tail->next = newnode;// 尾部的next为 新变量
	//newnode->prev = tail;//新变量的反向节点为 上一个节点
	//newnode->next = phead;//新变量的下一个 为头节点
	//phead->prev = newnode;//头的反向指针为 新变量
	ListInsert(phead,x);   
}
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushFront(LTNode* phead,LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;
	//phead->next = newnode;
	//newnode->next = next;
	//newnode->prev = phead;
	//next->prev = newnode;
	ListInsert(phead->next,x);
}

//这一种写法也可行，但是链表的指向链接顺序不能够更改， 好处是不用定义额外的指针，但这一点好处无关紧要
//void ListPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	LTNode* newnode = BuyListNode(x);
//
//	phead->next->prev = newnode;
//	newnode->next = phead->next;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	////assert(!ListEmpty(phead));
	//	LTNode* tail = phead->prev;
	//	LTNode* tailprev = tail->prev;
	//	free(tail);
	//	tailprev->next = phead;
	//	phead->prev = tailprev;
	ListErase(phead->prev);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead->next);
}
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	
	return phead->next = phead;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->next = pos;
	newnode->prev = prev;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
int ListSize(LTNode* phead)
{
	//能使用哨兵位的data来进行存储size呢？
	//这有一个前提条件，确定了数据类型为int 那么可以用来一试
	//但如果为double char 那么就不能保证是正确的

	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while(cur!=phead)//时间复杂度问O(n)
	{ 
		cur = cur->next;
		size++;
	}
	return size;
}
void DestoryList(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;//这句话无价值，phead的改变不会改变pilst ，想让这里有意义 用二级指针
	//但是不建议这样做，要保持函数的一致性，否则会怪怪的哈哈
	//可以在主函数中进行置空，让调用函数的人自己做这件事
}