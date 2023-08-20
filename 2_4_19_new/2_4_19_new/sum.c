//上节课我们主要讲解了时间复杂度和 空间复杂度
//1. 算法效率
//1）如何衡量一个算法是的好坏
//   我们去计算 算法的运行次数
/*
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

//3.空间复杂度
//空间复杂度也是一个数学表达式，，是对一个 算法在运行过程中 临时占用存储空寂按大小的量度
//估算 变量的个数，同样用大O渐进表示法
//函数运行时的栈空间已经编译期确定，所以复杂度通过额外申请的空间来确定


//空间复杂度示例1
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
//空间复杂度是多少呢  O(1) 哈哈哈哈我蒙对了，nice



// 计算Fibonacci  示例2
// 返回斐波那契数列的前n项的空间复杂度
long long* Fibonacci(size_t n)
{
	if (n == 0)
		return NULL;

	long long* fibAr
	fibArray[1] = 1ray = (long long*)malloc((n + 1) * sizeof(long long));
	fibArray[0] = 0;;
	for (int i = 2; i <= n; ++i)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}
//O(N)


// 计算阶乘递归Fac的空间复杂度？  示例3
long long Fac(size_t N)
{
	if (N == 0)
		return 1;

	return Fac(N - 1) * N;
}
//O(N)


// 计算斐波那契递归Fib的空间复杂度？
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//从实际角度出发， 我们认为斐波那契数列不断递归的过程中，走到底的时候 Fib(2) Fib(1) 及以上的空间都是逐层同时利用
// 返回后空间销毁，调用时在创建，是在一定的有限区域内不断地操作
//也就是说 他们最终返回时，都是一层一层重复的调用函数重复利用然后在销毁
///O(N)


//栈帧保存局部变量和返回值

//上题目
//3.2 旋转数组OJ链接：https://leetcode-cn.com/problems/rotate-array/

void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
	return nums;
}



//下节课开始我们的   顺序表+单链表
//顺序表和链表总共会讲五节课    //因为讲完数据结构还会在练题啥的
//线性表 ： 是挨着挨着放的数据结构
//同样对应就有非线性结构
//顺序表就是 数组，概念： 顺序表是用一段物理地址连续的存储单元 依次存储单元依次存储数据元素的线性结构
//一般情况下才用数组存储，在数组上完成数据的增删查改
//我们会以工程的形式将实现线性表
//声明放入.h文件中  定义放入.c文件中  测试专门写一个test.c文件
//管理数据的大部分结构就是增删查改
*/

//复现顺序表

//test.c里的 line110
//line141
// 
//seqlist.h  line 9 
//seqlist.c  全部



//第一题  双指针解决问题
//https://leetcode.cn/problems/remove-element/submissions/

//第二题 双指针解决问题
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/

//第三题 归并排序思路
//https://leetcode.cn/problems/merge-sorted-array/submissions/