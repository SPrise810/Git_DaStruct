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
//����1�� ��ջ��12345
//��ջһ����54321ô��

//��һ����Ҳ������54321
//��һ����һ�����͵��ˣ�    ��һ��1 ��һ�� 1  ��һ�� 2 ��һ�� 2
//���������������ȳ�ԭ����ʵ����Զ��Եģ�����ȷ���ģ���ȫ�����Լ���ô����

//ջ��ʵ�ʵ�������������Ϊ ģ��ǵݹ�
//����˵���ǵݹ�ķǵݹ飬 ������Ӧ�õȵ�ɶ��


