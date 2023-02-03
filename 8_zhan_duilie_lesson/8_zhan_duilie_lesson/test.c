#include"stack.h"
void test()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 4);
	//printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	StackDestory(&st);
}
int main()
{
	test();
	return 0;
}
//问题1： 入栈是12345
//出栈一定是54321么？

//不一定，也可能是54321
//入一个出一个不就得了！    入一个1 出一个 1  入一个 2 出一个 2
//所以我们这个后进先出原则其实是相对而言的，不是确定的，完全看你自己怎么操作

//栈在实际当中真正的运用为 模拟非递归
//比如说我们递归改非递归， 二叉树应用等等啥的


