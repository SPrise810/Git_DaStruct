#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;//需要进行扩容
}HP;

void HeapInit(HP* php);//创建
void HeapPrint(HP* php);//打印
void HeapDestoty(HP* php);//销毁
void HeapPush(HP* php,HPDataType x);//输入元素
void HeapPop(HP* php);//删除元素
HPDataType HeapTop(HP* php);//取堆顶元素
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
void Swap(HPDataType* p1,HPDataType* p2);
void TestHeapSort();
void AdjustDown(HPDataType* a,int n,int x);
void fun();
void fun2();
