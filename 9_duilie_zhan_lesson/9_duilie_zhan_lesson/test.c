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
//������ȥ�����������ʧȥ���б���������� �Ƚ��ȳ�
	while (!QueueEmpty(&q))//ջ�Ͷ��о���Ϊ�˽�ȥ���룻����ɾ���� �������û��ֵ
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