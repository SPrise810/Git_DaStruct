#include"stack.h"
void StackInit(ST* ps)//��ʼ��
{
	assert(ps);
	ps->a = NULL;
	ps->capacitity = ps->top = 0;
}
void StackDestory(ST* ps)//����
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacitity = 0;
}
void StackPush(ST* ps, STDataType x)//����һ������  (�Ѿ��涨��ֻ����ջ��һ�˲��룩
{
	assert(ps);
	if (ps->top == ps->capacitity)
	{
		int newcapacity = ps->capacitity == 0 ? 4 : ps->capacitity * 2;
		STDataType* tmp =(STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacitity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;

}
void StackPop(ST* ps)//ɾ��һ������
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;

}
STDataType StackTop(ST* ps)//ȡջ��Ԫ��
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
bool StackEmpty(ST* ps)//�ж�ջΪ��Ϊ��
{
	assert(ps);
	if (ps->top > 0)
	{
		return false;
	}
	return true;

	//Ҳ����һ�仰���
	//return ps->top == 0;
}
int StackSize(ST* ps)//�ж�ջ��Ԫ�ظ���
{
	assert(ps);
	return ps->top;
}










