#include"SeqList.h"
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//学习数据结构 一定要慢慢来 一步步的调试程序，做一点调试一点程序
//要学会 边写把边编译边纠错
void SLPushBack(SL* ps, SLDataType x)
{
	//插入前先检查顺序表容量
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); //直接结束掉程序
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
void SLCheckCapacity(SL* ps)//检查容量
{
	//插入前先检查顺序表容量
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
void SLPushFront(SL* ps, SLDataType x)//头插一个数据
{
	if (SLCheckCapacity)
	{
		
	}
	//挪动一位数据
	int end = ps->size - 1;
	while(end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
