#include"queue.h"
void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePop(&q);
	QueuePush(&q, 4);
//不允许去遍历，否则就失去队列本身的意义了 先进先出
	while (!QueueEmpty(&q))//栈和队列就是为了进去输入；出来删除的 遍历真的没价值
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);
}
int main()
{
	test();
	return 0;
}