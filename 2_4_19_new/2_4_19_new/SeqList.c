#include"SeqList.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//学习数据结构 一定要慢慢来 一步步的调试程序，做一点调试一点程序
//要学会 边写把边编译边纠错
void SLPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	////插入前先检查顺序表容量
	//if (ps->size == ps->capacity)
	//{
	//	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	//	SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
	//	if (tmp == NULL)
	//	{
	//		printf("realloc fail\n");
	//		exit(-1); //直接结束掉程序
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
void SLCheckCapacity(SL* ps)//检查容量
{
	assert(ps);

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
	//assert(ps);

	//SLCheckCapacity(ps);
	////挪动一位数据
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
	//SLPopBack  尾删
	//
	assert(ps->size > 0);//断言 暴力检查
	ps->size--;
}
void SLDestory(SL* ps)//删除开辟的空间
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
	//头删
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)//在某个位置插入数据
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	//插入数据都要考虑越界问题
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
int SLModify(SL* ps, int pos, SLDataType x)//替换函数。应当结合 modify函数使用
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
	return 1;
}