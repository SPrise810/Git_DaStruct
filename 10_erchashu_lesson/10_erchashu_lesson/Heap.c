#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestoty(HP* php);
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}//����
void Adjustup(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php��HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		//����
	}
	php->a[php->size] = x;
	php->size++;
	Adjustup(php->a, php->size - 1);//������ ��������д���Ѻ�С���ѵİڷŲ���ȷ���£�С��Ϊ��
}//����Ԫ��
void HeapPop(HP* php)//ɾ��Ԫ��
{
	//ɾ���Ѷ�������
	//
}
HPDataType HeapTop(HP* php);//ȡ�Ѷ�Ԫ��
bool HeapEmpty(HP* php);
int HeapSize(HP* php);