#include"Seqlist.h"
//使用防御式编程 防止别人偷偷使坏 
//我们在所有使用的函数前面添加assert 断言来防止出现空指针 野指针等等问题
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLPushBack(SL* ps, SLDataType x)//尾插
{
	////检查扩容
	//if (ps->capacity == ps->size)
	//{
	//	/*		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	//	////普及一下： realloc  后面有足够的空间就原地扩容，后面没有足够的空间就异地扩容
	//	////void* realloc(void* ptr,size_t size)
	//	////new size for the memory block in bytes 空间大小在内存块中单位为 字节，所以我们要进行转换 *sizeof(SLDataType)
	//	////返回值为void*
	//	////如果函数没申请到足够的内存，会返回空指针
	//	//		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
	//	//		//扩容失败失败情况
	//	//		if (tmp == NULL)
	//	//		{
	//	//			printf("realloc fail\n");//扩容失败，一般失败都是没空间，但是这种情况极少
	//	//			exit(-1);//直接结束程序
	//	//		}
	//	//		ps->a = tmp;
	//	//		ps->capacity = newCapacity;
	//	//	}*/
	//	SLPCheckCapacity(ps);
	//}
	//	ps->a[ps->size] = x;//加入数据
	//	ps->size++; 
	//	//数据个数++
	//	//但是妹有检查容量是否溢出
	//	//所以我们要先检查
	SLInsert(ps, ps->size, x);
}
void SLPrint(SL * ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SLPushFront(SL* ps,SLDataType x)//在前面扩容
{
	//assert(ps);
	//SLPCheckCapacity(ps);
	////往后挪动数据
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}
	////插入数据
	//ps->a[0] = x;
	//ps->size++;
	SLInsert(ps, 0, x);
}
void SLPCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			//exit(-1);
			return;
		}
		//普及一下： realloc  后面有足够的空间就原地扩容，后面没有足够的空间就异地扩容
		//void* realloc(void* ptr,size_t size)
		//new size for the memory block in bytes 空间大小在内存块中单位为 字节，所以我们要进行转换 *sizeof(SLDataType)
		//返回值为void*
		//如果函数没申请到足够的内存，会返回空指针
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}
void SLPopBack(SL* ps)
{
	//assert(ps);
	////ps->size--;//还是不够严谨，万一我们的数据删多了，导致size越界（数据个数变为负数）
	//
	/*温柔检查*/
	////if (ps->size == 0)
	////{
	////	printf("SeqList is empty\n");
	////}
	////else
	////{
	////	ps->size--;
	////}
	//
	////暴力检查，万一越界直接就是报错处理
	//assert(ps->size > 0);//为假就报错 ，为真就不处理直接过
	//ps->size;
	SLErase(ps, ps->size - 1);
}
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//检查
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	++begin;
	//}
	//ps->size--;
	SLErase(ps, 0);
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLPCheckCapacity(ps);
	//从后往前挪
	//好的命名习惯 别人能看懂，代码素养 码如其人
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
	//那么我在0的位置插入，不就是PushFront了么沃趣
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos+1;
	while (begin < ps->size)//控制好边界
	{
		ps->a[begin-1] = ps->a[begin];
		begin++;
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
void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}