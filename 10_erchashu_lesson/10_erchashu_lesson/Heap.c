#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestoty(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
 }//销毁
void Adjustup(HPDataType* a, int child)//向上调整函数
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
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
void Swap(HPDataType* p1,HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void HeapPrint(HP* php)
{
	assert(php);
		for (int i = 0; i < php->size; ++i)
		{
			printf("%d ", php->a[i]);
		}
	printf("\n");
}
void HeapPush(HP* php,HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)

	{
		//扩容
		//考虑到初始化后capacity值为0
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;
	Adjustup(php->a, php->size - 1);//遇到堆 排序过程中大根堆和小根堆的摆放不正确的事（小根为例
}//输入元素
void AdjustDown(HPDataType* a, int size, int parent)//向下调整法
{
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	//前提： 左子树是小堆，右子树也是小堆
	
	//int child = 0;
	//while (child < size)
	//{
	//	int leftchild = parent * 2 + 1;
	//	int rightchild = parent * 2 + 2;
	//	child = a[leftchild] < a[rightchild] ? leftchild : rightchild;
	//	if (a[child] > a[parent])
	//	{
	//		Swap(&(a[child]), &(a[parent]));
	//	}
	//	parent = child;
	//}
	int child = parent * 2 + 1;//默认左孩子起步
	while (child<size)
	{
		if (child+1<size && a[child + 1] > a[child])//判断左右孩子大小
		{
			++child;
		}
		if (a[child] > a[parent])//孩子和父亲比较大小
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)//删除堆顶元素，删除别的没什么意义
{
	//删除堆顶的数据
	//方法： 交换根部节点和数组位置尾节点的位置，然后进行向下调整算法排序
	assert(php);
	assert(php->size > 0);
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)//取堆顶元素
{
	assert(php);
	assert(php->size > 0);
	return php->a[0]; 
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size == 0;
}






//