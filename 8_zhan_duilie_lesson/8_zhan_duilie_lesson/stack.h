#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
//#define N 10
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType a[N];
//	int top;//��ʶջ����λ��
//}ST;
//
//����Ϊ��̬ջ������

/////////////////////////////////////////////////////////////////////////////
//ʹ�ö�̬ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;//��ʶջ����λ��
	int capacitity;//����
}ST;

void StackInit(ST* ps);//��ʼ��
void StackDestory(ST* ps);//����
void StackPush(ST* ps,STDataType x);//����һ������  (�Ѿ��涨��ֻ����ջ��һ�˲��룩
void StackPop(ST* ps);//ɾ��һ������
STDataType StackTop(ST* ps);//ȡջ��Ԫ��
bool StackEmpty(ST* ps);//�ж�ջΪ��Ϊ��
int StackSize(ST* ps);//�ж�ջ��Ԫ�ظ���