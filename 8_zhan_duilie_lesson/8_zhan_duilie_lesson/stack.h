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
//	int top;//标识栈顶的位置
//}ST;
//
//以上为静态栈，不好

/////////////////////////////////////////////////////////////////////////////
//使用动态栈
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;//标识栈顶的位置
	int capacitity;//容量
}ST;

void StackInit(ST* ps);//初始化
void StackDestory(ST* ps);//销毁
void StackPush(ST* ps,STDataType x);//插入一个数据  (已经规定了只能在栈顶一端插入）
void StackPop(ST* ps);//删除一个数据
STDataType StackTop(ST* ps);//取栈顶元素
bool StackEmpty(ST* ps);//判断栈为不为空
int StackSize(ST* ps);//判断栈的元素个数