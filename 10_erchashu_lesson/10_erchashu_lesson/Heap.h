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
	int capacity;//��Ҫ��������
}HP;

void HeapInit(HP* php);//����
void HeapPrint(HP* php);//��ӡ
void HeapDestoty(HP* php);//����
void HeapPush(HP* php,HPDataType x);//����Ԫ��
void HeapPop(HP* php);//ɾ��Ԫ��
HPDataType HeapTop(HP* php);//ȡ�Ѷ�Ԫ��
bool HeapEmpty(HP* php);
int HeapSize(HP* php);
void Swap(HPDataType* p1,HPDataType* p2);
void TestHeapSort();
void AdjustDown(HPDataType* a,int n,int x);
void fun();
void fun2();
