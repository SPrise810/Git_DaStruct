#pragma once
#define _CRT_SEUCRE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int QDataType;
// ��ʽ�ṹ�� ��ʾ����
typedef struct QueueNode
{
	struct  QueueNOde* next;
	QDataType data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* head;
	QNode* tail;   
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int	QueueSize(Queue* pq);

