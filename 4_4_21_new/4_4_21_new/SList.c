#include "SList.h"

void TestSList1()
{
	SLTNode* n1 =(SLTNode*) malloc(sizeof(SLTDataType));
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
}
int main()
{
	TestSList1();
	return 0;
}