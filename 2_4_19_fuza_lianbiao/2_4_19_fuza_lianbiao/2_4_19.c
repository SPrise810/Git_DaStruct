#define _CRT_SERCURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//上节课我们主要讲解了时间复杂度和 空间复杂度
//1. 算法效率
//1）如何衡量一个算法是的好坏
//   我们去计算 算法的运行次数

//示例7
// 计算阶乘递归Fac的时间复杂度？
long long Fac(size_t N)
{
	if (0 == N)
		return 1;

	return Fac(N - 1) * N;
}
//图1

// 计算斐波那契递归Fib的时间复杂度？
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//时间复杂度我们不能只看代码，要看它的逻辑思路
//图1
//斐波那契的递归写法没有意义，时间复杂度太大O(2^N)，反而写成循环的方法会更简单一点 时间复杂度为O(N)

//栈溢出问题
//int main()
//{
//	printf("%lld\n",Fac(10000));
//	return 0;
//}

// 计算BubbleSort的空间复杂度？
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