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
 }//����
void Adjustup(HPDataType* a, int child)//���ϵ�������
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
		//����
		//���ǵ���ʼ����capacityֵΪ0
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
	Adjustup(php->a, php->size - 1);//������ ��������д���Ѻ�С���ѵİڷŲ���ȷ���£�С��Ϊ��
}//����Ԫ��
void AdjustDown(HPDataType* a, int size, int parent)//���µ�����
{
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	//ǰ�᣺ ��������С�ѣ�������Ҳ��С��
	
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
	int child = parent * 2 + 1;//Ĭ��������
	while (child<size)
	{
		if (child+1<size && a[child + 1] > a[child])//�ж����Һ��Ӵ�С
		{
			++child;
		}
		if (a[child] > a[parent])//���Ӻ͸��ױȽϴ�С
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

void HeapPop(HP* php)//ɾ���Ѷ�Ԫ�أ�ɾ�����ûʲô����
{
	//ɾ���Ѷ�������
	//������ ���������ڵ������λ��β�ڵ��λ�ã�Ȼ��������µ����㷨����
	assert(php);
	assert(php->size > 0);
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)//ȡ�Ѷ�Ԫ��
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