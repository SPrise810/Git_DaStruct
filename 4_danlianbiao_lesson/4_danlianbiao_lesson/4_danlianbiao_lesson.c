//˳�����ʵ����һ�����飬����ģ��ʵ�ֲ���ӹ���
//˳�������� ��
// 1. ������֯���ǵ����ݣ�����������������
//2.�±���������
//����/ȱ�㣺
//1.Ҫ������ռ��������ռ䲻����Ҫ���ݣ�������һ�����������ģ����Ҵ������ݺ�Ŀռ��˷�
//2.ͷ�������м�λ�ò���ɾ��Ч�ʵ��¡�

//��ν�����������أ�  ���ǵ�����Ӧ�˶���

//���Ʒ�����  1.���� ������ͷſռ� 
//2.ͷ�����м�λ�ý��в���ɾ��������ҪŲ������
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
	n1->next = n2;//���ṹ��n2���ĵ�ַ��ֵ��n1��nextָ��
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
void TestSList5()//�ô���֤�����ҵĸ������þ����޸�
//ֱ�Ӿ����ҵ����ǵ�ָ���ڵ� ���б�������
{
	SLTNode* plist = NULL;
	int x = 0;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	printf("������Ҫ�ı��ֵ��");
	scanf("%d", &x);
	int y = 0;
	SLTNode* ret = SListFind(plist, x);
	if (ret)
	{
		printf("�ҵ���\n������Ҫ�޸ĵ�ֵ��");
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
//������һϵ�еĲ��ԣ����Ƿ��� ��ʵ�������βɾ��β����ʵ ʱ�临�Ӷ���ȻΪO(n) Ч�ʵ���
//���õ��ģ�����Ҳ���кܶ��ֽṹ��
//�ܹ�8�ֽṹ
//�������ȥ����Щ����

// ��Ϊʲô��Ҫѧ���fw������
//�������кܶ�������Ե��⣬�������ǵ�����ṹ�� 
//���������Ϊ�Ժ���������ݽṹ���ӽṹ����ϣͰ��ͼ���ٽӱ�
int main()
{
	TestSList6();
	return 0;
}






































//����china
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX_LIST 50
//typedef struct
//{
//	int* elem;//��Ԫ����Ϊ����
//	int length;
//}sqlist;
//void CreateSearchList(sqlist *ST)
//{
//	int i = 0;
//	ST->elem = (int*)malloc(MAX_LIST * sizeof(int));
//	printf("��������ұ�ĳ��ȣ�\n");
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
//	printf("˳����е�Ԫ��Ϊ��\n");
//	print(ST);
//	printf("\n������˳����ң�\n������Ҫ���ҵĹؼ��֣�\n");
//	scanf("%d", &x);
//	loc = Search(ST, x);
//	if (loc)
//		printf("���ҳɹ���,λ��Ϊ��%d", loc);
//	else
//		printf("δ���ҵ�ָ���ؼ���");
//	Sort(ST);
//	printf("�������۰���ң�\n");
//	printf("\n����Ҫ���ҵĹؼ���:\n");
//	scanf("%d", x);
//	loc = Search(ST,x);
//	if (loc)
//			printf("���ҳɹ���,λ��Ϊ��%d",loc);
//		else
//			printf("δ���ҵ�ָ���ؼ���");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define MAX_LIST 10
//typedef struct
//{
//	int* elem;//��Ԫ����Ϊ����
//	int length;
//}sqlist;
//void CreateSearchList(sqlist &ST)
//{
//	int i = 1;
//	int n,m=0;
//	ST.length=0;
//	int flag=1; 
//	printf("������m �� n��Ϊ������ݱ߽�\n");
//	scanf("%d %d",&m,&n);
//	int len=n-m;
//	ST.elem = (int*)malloc(len * sizeof(int));
//	srand((int)time(NULL));
//	printf("\n�������һ�����ݣ�\n");
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
// 		printf("��Ѱ��%d��!\n",count); 
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
//	printf("˳����е�Ԫ��Ϊ��\n");
//	print(ST);
//	printf("\n˳����ң�\n������Ҫ���ҵĹؼ��֣�\n");
//	scanf("%d", &x);
//	loc = Search_first(ST,x);
//	if (loc)
//		printf("���ҳɹ���  λ��Ϊ��%d\n", loc);
//	else
//		printf("δ���ҵ�ָ���ؼ���");
//	Sort(ST);
//	printf("��˳�������ݽ����������������£�\n"); 
//	print(ST);
//	printf("��ʼ�����۰���ң�\n");
//	printf("\n����Ҫ���ҵĹؼ���:\n");
//	scanf("%d",&x);
//	loc=search_zheban(ST,x); 
//	if(loc)
//		printf("���ҳɹ��� λ��Ϊ��%d",loc);
//	else
//		printf("δ���ҵ�ָ���ؼ���");
//	return 0;
//}