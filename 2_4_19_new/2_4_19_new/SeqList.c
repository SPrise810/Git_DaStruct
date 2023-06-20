#include"SeqList.h"
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//ѧϰ���ݽṹ һ��Ҫ������ һ�����ĵ��Գ�����һ�����һ�����
//Ҫѧ�� ��д�ѱ߱���߾���
void SLPushBack(SL* ps, SLDataType x)
{
	//����ǰ�ȼ��˳�������
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); //ֱ�ӽ���������
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;
	ps->size++;
}
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}
void SLCheckCapacity(SL* ps)//�������
{
	//����ǰ�ȼ��˳�������
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
void SLPushFront(SL* ps, SLDataType x)//ͷ��һ������
{
	if (SLCheckCapacity)
	{
		
	}
	//Ų��һλ����
	int end = ps->size - 1;
	while(end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
