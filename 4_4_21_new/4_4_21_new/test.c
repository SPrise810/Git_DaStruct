#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("haha\n");
//	return 0;
//}
void TestSList1()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTDataType));
	assert(n1);
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTDataType));
	assert(n2);
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTDataType));
	assert(n3);
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTDataType));
	assert(n4);
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	SListPrint(n1);
	SListPushback(n1, 5);
	SListPushback(n1, 5);
	SListPushback(n1, 5);
	SListPushback(n1, 5);
	SListPrint(n1);
}
void TestSList2()
{
	SLTNode* n1 = NULL;
	SListPrint(n1);
	//SListPushfront(&n1, 1);
	//SListPushback(&n1, 5);//ȡ���ĵ�ַ   ָ��ĵ�ַ
	SListPushback(&n1, 3);

	SListPrint(n1);
	SListPopback(&n1);
	SListPrint(n1);
	//SListPopfront(&n1);
	//SListPrint(n1);
	//SListPopfront(&n1);
	//SListPrint(n1);
}
void TestSList3()
{
	SLTNode* n1 = NULL;
	SListPrint(n1);
	SListPushfront(&n1, 1);
	SListPushback(&n1, 2);//ȡ���ĵ�ַ   ָ��ĵ�ַ
	SListPushback(&n1, 3);
	SListPrint(n1);
	SLTNode* ret = SListfind(n1, 3);
	if (ret)
	{
		printf("�ҵ���\n");
		ret->data = 30;
		SListPrint(n1);
	}
}
int main()
{
	TestSList3();

	return 0;
}