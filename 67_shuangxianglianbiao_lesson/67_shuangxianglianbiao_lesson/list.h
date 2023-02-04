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

//void ListInit(LTNode* pphead);//���ﻹ�����÷���ֵ�����
LTNode* BuyListNode(LTDataType x);
LTNode* ListInit();
void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead,LTDataType x);//��������û���ö���ָ����Ϊ������ͷ�ڵ�
//����������ô����������޸ģ�����������޸�ͷ����λ�ã����Ƕ�ͷ����next���и���
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);//

bool ListEmpty(LTNode* phead);// ��������BOOL
void ListInsert(LTNode* pos, LTDataType x);//����
void ListErase(LTNode* pos);//ɾ��
int ListSize(LTNode* phead);
void DestoryList(LTNode* phead);





