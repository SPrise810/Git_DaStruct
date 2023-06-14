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
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;
	ps->size++;
}