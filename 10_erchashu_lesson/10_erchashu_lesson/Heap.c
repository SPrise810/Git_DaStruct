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
}//销毁
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
void HeapPush(HP* php，HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		//扩容
	}
	php->a[php->size] = x;
	php->size++;
	Adjustup(php->a, php->size - 1);//遇到堆 排序过程中大根堆和小根堆的摆放不正确的事（小根为例
}//输入元素
void HeapPop(HP* php)//删除元素
{
	//删除堆顶的数据
	//
}
HPDataType HeapTop(HP* php);//取堆顶元素
bool HeapEmpty(HP* php);
int HeapSize(HP* php);