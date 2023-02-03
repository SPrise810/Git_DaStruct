#include"stack.h"
void StackInit(ST* ps)//初始化
{
	assert(ps);
	ps->a = NULL;
	ps->capacitity = ps->top = 0;
}
void StackDestory(ST* ps)//销毁
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacitity = 0;
}
void StackPush(ST* ps, STDataType x)//插入一个数据  (已经规定了只能在栈顶一端插入）
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
void StackPop(ST* ps)//删除一个数据
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;

}
STDataType StackTop(ST* ps)//取栈顶元素
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
bool StackEmpty(ST* ps)//判断栈为不为空
{
	assert(ps);
	if (ps->top > 0)
	{
		return false;
	}
	return true;

	//也可以一句话解决
	//return ps->top == 0;
}
int StackSize(ST* ps)//判断栈的元素个数
{
	assert(ps);
	return ps->top;
}










