#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//void ListInit(LTNode* pphead);//这里还可以用返回值来解决
LTNode* BuyListNode(LTDataType x);
LTNode* ListInit();
void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead,LTDataType x);//这里我们没有用二级指针因为我们有头节点
//无论我们怎么对链表进行修改，都不会更改修改头结点的位置，而是对头结点的next进行更改
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);//

bool ListEmpty(LTNode* phead);// 看好了是BOOL
void ListInsert(LTNode* pos, LTDataType x);//插入
void ListErase(LTNode* pos);//删除
int ListSize(LTNode* phead);
void DestoryList(LTNode* phead);





