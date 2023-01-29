#pragma once
//Single list 单链表
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	int data;
	struct SListNode* next;

}SLTNode;
SLTNode* BuySListNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** phead, SLTDataType x);
void SListPushFront(SLTNode** phead, SLTDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** phead);
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//查找
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//O(n)
void SListErase(SLTNode** pphead, SLTNode* ps);//O(n)

//换一个在pos后面插入删除的写法：
void SListEraseAfter(SLTNode* pos);
void SListInsertAfter(SLTNode*pos,SLTDataType x);
