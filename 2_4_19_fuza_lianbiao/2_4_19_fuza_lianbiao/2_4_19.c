#define _CRT_SERCURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�Ͻڿ�������Ҫ������ʱ�临�ӶȺ� �ռ临�Ӷ�
//1. �㷨Ч��
//1����κ���һ���㷨�ǵĺû�
//   ����ȥ���� �㷨�����д���

//ʾ��7
// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
long long Fac(size_t N)
{
	if (0 == N)
		return 1;

	return Fac(N - 1) * N;
}
//ͼ1

// ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//ʱ�临�Ӷ����ǲ���ֻ�����룬Ҫ�������߼�˼·
//ͼ1
//쳲������ĵݹ�д��û�����壬ʱ�临�Ӷ�̫��O(2^N)������д��ѭ���ķ��������һ�� ʱ�临�Ӷ�ΪO(N)

//ջ�������
//int main()
//{
//	printf("%lld\n",Fac(10000));
//	return 0;
//}

// ����BubbleSort�Ŀռ临�Ӷȣ�
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)

{
	int exchange = 0;
	for (size_t i = 1; i < end; ++i)
	{
		if (a[i - 1] > a[i])
		{
			Swap(&a[i - 1], &a[i]);
			exchange = 1;
		}
	}
	if (exchange == 0)
		break;
}
}