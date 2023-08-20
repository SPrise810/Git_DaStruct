//�Ͻڿ�������Ҫ������ʱ�临�ӶȺ� �ռ临�Ӷ�
//1. �㷨Ч��
//1����κ���һ���㷨�ǵĺû�
//   ����ȥ���� �㷨�����д���
/*
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

//3.�ռ临�Ӷ�
//�ռ临�Ӷ�Ҳ��һ����ѧ���ʽ�����Ƕ�һ�� �㷨�����й����� ��ʱռ�ô洢�ռŰ���С������
//���� �����ĸ�����ͬ���ô�O������ʾ��
//��������ʱ��ջ�ռ��Ѿ�������ȷ�������Ը��Ӷ�ͨ����������Ŀռ���ȷ��


//�ռ临�Ӷ�ʾ��1
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
//�ռ临�Ӷ��Ƕ�����  O(1) �����������ɶ��ˣ�nice



// ����Fibonacci  ʾ��2
// ����쳲��������е�ǰn��Ŀռ临�Ӷ�
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


// ����׳˵ݹ�Fac�Ŀռ临�Ӷȣ�  ʾ��3
long long Fac(size_t N)
{
	if (N == 0)
		return 1;

	return Fac(N - 1) * N;
}
//O(N)


// ����쳲������ݹ�Fib�Ŀռ临�Ӷȣ�
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}
//��ʵ�ʽǶȳ����� ������Ϊ쳲��������в��ϵݹ�Ĺ����У��ߵ��׵�ʱ�� Fib(2) Fib(1) �����ϵĿռ䶼�����ͬʱ����
// ���غ�ռ����٣�����ʱ�ڴ���������һ�������������ڲ��ϵز���
//Ҳ����˵ �������շ���ʱ������һ��һ���ظ��ĵ��ú����ظ�����Ȼ��������
///O(N)


//ջ֡����ֲ������ͷ���ֵ

//����Ŀ
//3.2 ��ת����OJ���ӣ�https://leetcode-cn.com/problems/rotate-array/

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



//�½ڿο�ʼ���ǵ�   ˳���+������
//˳���������ܹ��ὲ��ڿ�    //��Ϊ�������ݽṹ����������ɶ��
//���Ա� �� �ǰ��Ű��ŷŵ����ݽṹ
//ͬ����Ӧ���з����Խṹ
//˳������ ���飬��� ˳�������һ�������ַ�����Ĵ洢��Ԫ ���δ洢��Ԫ���δ洢����Ԫ�ص����Խṹ
//һ������²�������洢����������������ݵ���ɾ���
//���ǻ��Թ��̵���ʽ��ʵ�����Ա�
//��������.h�ļ���  �������.c�ļ���  ����ר��дһ��test.c�ļ�
//�������ݵĴ󲿷ֽṹ������ɾ���
*/

//����˳���

//test.c��� line110
//line141
// 
//seqlist.h  line 9 
//seqlist.c  ȫ��



//��һ��  ˫ָ��������
//https://leetcode.cn/problems/remove-element/submissions/

//�ڶ��� ˫ָ��������
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/

//������ �鲢����˼·
//https://leetcode.cn/problems/merge-sorted-array/submissions/