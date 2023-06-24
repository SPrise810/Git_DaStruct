#include"SeqList.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//ѧϰ���ݽṹ һ��Ҫ������ һ�����ĵ��Գ�����һ�����һ�����
//Ҫѧ�� ��д�ѱ߱���߾���
void SLPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	////����ǰ�ȼ��˳�������
	//if (ps->size == ps->capacity)
	//{
	//	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	//	SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
	//	if (tmp == NULL)
	//	{
	//		printf("realloc fail\n");
	//		exit(-1); //ֱ�ӽ���������
	//	}
	//	ps->a = tmp;
	//	ps->capacity = newcapacity;
	//}
	//ps->a[ps->size] = x;
	//ps->size++;

	SLInsert(ps, ps->size, x);
	
}
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}
void SLCheckCapacity(SL* ps)//�������
{
	assert(ps);

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
	//assert(ps);

	//SLCheckCapacity(ps);
	////Ų��һλ����
	//int end = ps->size - 1;
	//while(end>=0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}
	//ps->a[0] = x;
	//ps->size++;

	SLInsert(ps, 0, x);

}
void SLPopBack(SL* ps)
{
	assert(ps);
	//SLPopBack  βɾ
	//
	assert(ps->size > 0);//���� �������
	ps->size--;
}
void SLDestory(SL* ps)//ɾ�����ٵĿռ�
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;

	}
}
void SLPopFront(SL* ps)
{
	assert(ps);
	//ͷɾ
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)//��ĳ��λ�ò�������
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	//�������ݶ�Ҫ����Խ������
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;


}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (begin < ps->size-1)
	{
		ps->a[begin] = ps->a[begin+1];
		++begin;
	}
	ps->size--;
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;

}
int SLModify(SL* ps, int pos, SLDataType x)//�滻������Ӧ����� modify����ʹ��
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
	return 1;
}