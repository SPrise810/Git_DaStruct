#include"Seqlist.h"
//ʹ�÷���ʽ��� ��ֹ����͵͵ʹ�� 
//����������ʹ�õĺ���ǰ�����assert ��������ֹ���ֿ�ָ�� Ұָ��ȵ�����
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLPushBack(SL* ps, SLDataType x)//β��
{
	////�������
	//if (ps->capacity == ps->size)
	//{
	//	/*		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	//	////�ռ�һ�£� realloc  �������㹻�Ŀռ��ԭ�����ݣ�����û���㹻�Ŀռ���������
	//	////void* realloc(void* ptr,size_t size)
	//	////new size for the memory block in bytes �ռ��С���ڴ���е�λΪ �ֽڣ���������Ҫ����ת�� *sizeof(SLDataType)
	//	////����ֵΪvoid*
	//	////�������û���뵽�㹻���ڴ棬�᷵�ؿ�ָ��
	//	//		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
	//	//		//����ʧ��ʧ�����
	//	//		if (tmp == NULL)
	//	//		{
	//	//			printf("realloc fail\n");//����ʧ�ܣ�һ��ʧ�ܶ���û�ռ䣬���������������
	//	//			exit(-1);//ֱ�ӽ�������
	//	//		}
	//	//		ps->a = tmp;
	//	//		ps->capacity = newCapacity;
	//	//	}*/
	//	SLPCheckCapacity(ps);
	//}
	//	ps->a[ps->size] = x;//��������
	//	ps->size++; 
	//	//���ݸ���++
	//	//�������м�������Ƿ����
	//	//��������Ҫ�ȼ��
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
void SLPushFront(SL* ps,SLDataType x)//��ǰ������
{
	//assert(ps);
	//SLPCheckCapacity(ps);
	////����Ų������
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}
	////��������
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
		//�ռ�һ�£� realloc  �������㹻�Ŀռ��ԭ�����ݣ�����û���㹻�Ŀռ���������
		//void* realloc(void* ptr,size_t size)
		//new size for the memory block in bytes �ռ��С���ڴ���е�λΪ �ֽڣ���������Ҫ����ת�� *sizeof(SLDataType)
		//����ֵΪvoid*
		//�������û���뵽�㹻���ڴ棬�᷵�ؿ�ָ��
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}
void SLPopBack(SL* ps)
{
	//assert(ps);
	////ps->size--;//���ǲ����Ͻ�����һ���ǵ�����ɾ���ˣ�����sizeԽ�磨���ݸ�����Ϊ������
	//
	/*������*/
	////if (ps->size == 0)
	////{
	////	printf("SeqList is empty\n");
	////}
	////else
	////{
	////	ps->size--;
	////}
	//
	////������飬��һԽ��ֱ�Ӿ��Ǳ�����
	//assert(ps->size > 0);//Ϊ�پͱ��� ��Ϊ��Ͳ�����ֱ�ӹ�
	//ps->size;
	SLErase(ps, ps->size - 1);
}
void SLPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);//���
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
	//�Ӻ���ǰŲ
	//�õ�����ϰ�� �����ܿ������������� ��������
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
	//��ô����0��λ�ò��룬������PushFront��ô��Ȥ
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int begin = pos+1;
	while (begin < ps->size)//���ƺñ߽�
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