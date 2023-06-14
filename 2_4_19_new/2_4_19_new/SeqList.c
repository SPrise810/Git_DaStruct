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
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;
	ps->size++;
}