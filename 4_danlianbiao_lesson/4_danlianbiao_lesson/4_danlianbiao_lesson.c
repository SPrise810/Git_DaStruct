//顺序表其实就是一个数组，我们模拟实现并添加功能
//顺序表的优势 是
// 1. 方便组织我们的数据，它物理上是连续的
//2.下标的随机访问
//劣势/缺点：
//1.要求物理空间连续，空间不够需要扩容，扩容有一定的性能消耗，并且存在扩容后的空间浪费
//2.头部或者中间位置插入删除效率低下。

//如何解决上述问题呢？  我们的链表应运而生

//改善方案：  1.按需 申请或释放空间 
//2.头部或中间位置进行插入删除，不需要挪动数据
#include"SList.h" 

void TestSList1()
{
	//struct SListNode*
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n4);
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n1->next = n2;//将结构体n2结点的地址赋值给n1的next指针
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	SListPrint(n1);
}
void TestSList2()
{
	SLTNode* n1 = NULL;
	SListPrint(n1);
	SListPushBack(&n1, 1);
	SListPushBack(&n1, 1);
	SListPushBack(&n1, 1);
	SListPushBack(&n1, 1);
	SListPushBack(&n1, 1);
	SListPrint(n1);

}
void TestSList3()
{
	SLTNode *n1 = NULL;
	SListPrint(n1);
	SListPushFront(&n1, 0);
	SListPushFront(&n1, 1);
	SListPushFront(&n1, 2);
	SListPushFront(&n1, 3);
	SListPrint(n1);
	SListPopFront(&n1);
	SListPrint(n1);
	SListPopBack(&n1);
}
void TestSList4()
{
	SLTNode* n1 = NULL;
	SListPushFront(&n1, 0);
	SListPushFront(&n1, 1);
	SListPushFront(&n1, 2);
	SListPushFront(&n1, 3);
	SListPopBack(&n1);
	SListPrint(n1);
	SListPopBack(&n1);
	SListPrint(n1);
	SListPopBack(&n1);
	SListPrint(n1);
	SListPopBack(&n1);
	SListPrint(n1);
}
void TestSList5()//用此例证明查找的附带作用就是修改
//直接就是找到我们的指定节点 进行暴力操作
{
	SLTNode* plist = NULL;
	int x = 0;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	printf("请输入要改变的值：");
	scanf("%d", &x);
	int y = 0;
	SLTNode* ret = SListFind(plist, x);
	if (ret)
	{
		printf("找到了\n请输入要修改的值：");
		scanf("%d", &y);
		ret->data = y;
		SListPrint(plist);
	}
}
void TestSList6()
{
	SLTNode* plist = NULL;
	int x = 0;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 4);
	SListInsert(&plist, pos, 4);
	SListPrint(plist);
	SListErase(&plist,pos);
	SListPrint(plist);
	pos = SListFind(plist, 4);
	SListInsertAfter(pos, 400);
	SListPrint(plist);
	SListEraseAfter(pos);
	SListPrint(plist);

}
//但经过一系列的测试，我们发现 其实单链表的尾删和尾插其实 时间复杂度仍然为O(n) 效率低下
//不用担心，链表也是有很多种结构的
//总共8种结构
//后面会逐渐去讲这些东西

// 那为什么还要学这个fw单链表？
//链表都会有很多笔试面试的题，基本都是单链表结构！ 
//单链表会作为以后更复杂数据结构的子结构（哈希桶，图的临接表）
int main()
{
	TestSList6();
	return 0;
}






































//加油china
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX_LIST 50
//typedef struct
//{
//	int* elem;//首元素作为监视
//	int length;
//}sqlist;
//void CreateSearchList(sqlist *ST)
//{
//	int i = 0;
//	ST->elem = (int*)malloc(MAX_LIST * sizeof(int));
//	printf("请输入查找表的长度：\n");
//	srand((int)time(NULL));
//	for (i = 0; i < 50; i++)
//	{
//		ST->elem[i] = rand() % 100 + 100;
//		ST->length++;
//		printf(" %d", ST->elem[i]);
//	}
//}
//int Search(sqlist ST, int x)
//{
//	int i = ST.length;
//	ST.elem[0] = x;
//	while (x != ST.elem[i])
//	{
//		i--;
//	}
//	return i;
//}
//void print(sqlist ST)
//{
//	for (int i = 1; i <= ST.length; i++)
//	{
//		printf("%d ", ST.elem[i]);
//	}
//	printf("\n");
//}
//void Sort(sqlist ST)
//{
//	int i, j, k, temp;
//	for (i = 1; i < ST.length; i++)
//	{
//		k = i;
//		for (j = i + 1; j <= ST.length; j++)
//		{
//			if (ST.elem[k] > ST.elem[j])
//			{
//				k = j;
//			}
//		}
//		if (k != i)
//		{
//			temp = ST.elem[i];
//			ST.elem[i] = ST.elem[k];
//			ST.elem[k] = temp;
//		}
//	}
//}
//int Search_zheban(sqlist ST, int x)
//{
//	int low, high, mid;
//	low = 1;
//	high = ST.length;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (x == ST.elem[mid])
//		{
//			return mid;
//		}
//		else if (x < ST.elem[mid])
//		{
//			high = mid - 1;
//		}
//		else
//			low = mid + 1;
//	}
//	return 0;
//}
//int main()
//{
//	sqlist ST;
//	int x, loc;
//	CreateSearchList(ST);
//	printf("顺序表中的元素为：\n");
//	print(ST);
//	printf("\n下面是顺序查找：\n请输入要查找的关键字：\n");
//	scanf("%d", &x);
//	loc = Search(ST, x);
//	if (loc)
//		printf("查找成功：,位置为：%d", loc);
//	else
//		printf("未查找到指定关键字");
//	Sort(ST);
//	printf("下面是折半查找：\n");
//	printf("\n输入要查找的关键字:\n");
//	scanf("%d", x);
//	loc = Search(ST,x);
//	if (loc)
//			printf("查找成功：,位置为：%d",loc);
//		else
//			printf("未查找到指定关键字");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX_LIST 10
//typedef struct
//{
//	int* elem;//首元素作为监视
//	int length;
//}sqlist;
//void CreateSearchList(sqlist &ST)
//{
//	int i = 1;
//	int n,m=0;
//	ST.length=0;
//	int flag=1; 
//	printf("请输入m 和 n作为随机数据边界\n");
//	scanf("%d %d",&m,&n);
//	int len=n-m;
//	ST.elem = (int*)malloc(len * sizeof(int));
//	srand((int)time(NULL));
//	printf("\n随机产生一组数据：\n");
//	int count;
//	while(i<len)
//	{
//		int j=(rand()+m)%n;
//		if(j<n&&j>m)
//		{
//			int flag2=0;
//			if(flag==1)
//			{                  //1 2 3...10
//				count=i;//1 2 3...10
//				while(count--)//0 1 2..9
//				{
//					if(ST.elem[count]==j)// / 1==j 2==j 1==j  	
//						flag2=1;
//				 }	
//			}
//		if(flag2)
//			continue;
//		ST.elem[i] =j;
//		ST.length++;
//		i++;
//		flag=1;
//		}
//	
//	}
//}
//void print(sqlist ST)
//{
//	for (int i = 1; i <= ST.length; i++)
//	{
//		printf("%d ", ST.elem[i]);
//	}
//	printf("\n");
//}
//void Sort(sqlist ST)
//{
//	int i, j, k, temp;
//	for (i = 1; i < ST.length; i++)
//	{
//		k = i;
//		for (j = i + 1; j <= ST.length; j++)
//		{
//			if (ST.elem[k] > ST.elem[j])
//			{
//				k = j;
//			}
//		}
//		if (k != i)
//		{
//			temp = ST.elem[i];
//			ST.elem[i] = ST.elem[k];
//			ST.elem[k] = temp;
//		}
//	}
//}
//
//int search_zheban(sqlist ST, int x)
//{
//	int low, high, mid=0;
//	low = 1;
//	high = ST.length;
//	int count=0;
//	while (low <= high)
// 	{
// 		count++;
//  		mid = (low + high) / 2;
//  		if (x < ST.elem[mid])
//  		{
//  		 high = mid;
// 	 	}
// 	 	else if (x > ST.elem[mid])
// 	 	{
//	     low = mid+1;
//		}
//  		else 
// 		{
// 		printf("共寻找%d次!\n",count); 
//  		return mid;
// 		}
//    }
//	return 0;
//}
//int Search_first(sqlist ST, int x)
//{
//	int i = ST.length;
//	ST.elem[0] = x;
//	while (x != ST.elem[i])
//	{
//		i--;
//	}
//	return i;
//}
//int main()
//{
//	sqlist ST;
//	int x=0, loc=0;
//	CreateSearchList(ST);
//	printf("顺序表中的元素为：\n");
//	print(ST);
//	printf("\n顺序查找：\n请输入要查找的关键字：\n");
//	scanf("%d", &x);
//	loc = Search_first(ST,x);
//	if (loc)
//		printf("查找成功：  位置为：%d\n", loc);
//	else
//		printf("未查找到指定关键字");
//	Sort(ST);
//	printf("对顺序表的数据进行排序，排序结果如下：\n"); 
//	print(ST);
//	printf("开始进行折半查找：\n");
//	printf("\n输入要查找的关键字:\n");
//	scanf("%d",&x);
//	loc=search_zheban(ST,x); 
//	if(loc)
//		printf("查找成功： 位置为：%d",loc);
//	else
//		printf("未查找到指定关键字");
//	return 0;
//}