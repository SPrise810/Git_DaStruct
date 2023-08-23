#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;

}SLTNode;
void SListPrint(SLTNode* phead);
void SListPushback(SLTNode** pphead,SLTDataType x);
void SListPushfront(SLTNode** pphead, SLTDataType x);
SLTNode* BuySListNode(SLTDataType x);
void SListPopback(SLTNode** pphead);
void SListPopfront(SLTNode** pphead);
SLTNode* SListfind(SLTNode* phead, SLTDataType x);

//��posλ��֮ǰ����
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataType x);

//ɾ��Posλ�õ�ֵ
void SListErase(SLTNode** phead, SLTNode* pos);


void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListEraseAfter(SLTNode* pos);
