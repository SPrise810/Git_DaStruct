#pragma once

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;//��Ҫ��������
}HP;

void HeapInit(HP* php);//����
void HeapDestoty(HP* php);//����
void HeapPush(HP* php��HPDataType x);//����Ԫ��
void HeapPop(HP* php);//ɾ��Ԫ��
HPDataType HeapTop(HP* php);//ȡ�Ѷ�Ԫ��
bool HeapEmpty(HP* php);
int HeapSize(HP* php);




