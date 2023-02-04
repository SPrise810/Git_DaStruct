#include"list.h"
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node =(LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}
//void ListInit(LTNode** pphead)
//{		
//	*pphead = BuyListNode(-1);
//	(* pphead)->next = pphead;
//	(* pphead)->prev = pphead;
//} 
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev; //����һ��β��ָ�� phead��β��
	//tail->next = newnode;// β����nextΪ �±���
	//newnode->prev = tail;//�±����ķ���ڵ�Ϊ ��һ���ڵ�
	//newnode->next = phead;//�±�������һ�� Ϊͷ�ڵ�
	//phead->prev = newnode;//ͷ�ķ���ָ��Ϊ �±���
	ListInsert(phead,x);   
}
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushFront(LTNode* phead,LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;
	//phead->next = newnode;
	//newnode->next = next;
	//newnode->prev = phead;
	//next->prev = newnode;
	ListInsert(phead->next,x);
}

//��һ��д��Ҳ���У����������ָ������˳���ܹ����ģ� �ô��ǲ��ö�������ָ�룬����һ��ô��޹ؽ�Ҫ
//void ListPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	LTNode* newnode = BuyListNode(x);
//
//	phead->next->prev = newnode;
//	newnode->next = phead->next;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	////assert(!ListEmpty(phead));
	//	LTNode* tail = phead->prev;
	//	LTNode* tailprev = tail->prev;
	//	free(tail);
	//	tailprev->next = phead;
	//	phead->prev = tailprev;
	ListErase(phead->prev);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead->next);
}
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	
	return phead->next = phead;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->next = pos;
	newnode->prev = prev;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}
int ListSize(LTNode* phead)
{
	//��ʹ���ڱ�λ��data�����д洢size�أ�
	//����һ��ǰ��������ȷ������������Ϊint ��ô��������һ��
	//�����Ϊdouble char ��ô�Ͳ��ܱ�֤����ȷ��

	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while(cur!=phead)//ʱ�临�Ӷ���O(n)
	{ 
		cur = cur->next;
		size++;
	}
	return size;
}
void DestoryList(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;//��仰�޼�ֵ��phead�ĸı䲻��ı�pilst ���������������� �ö���ָ��
	//���ǲ�������������Ҫ���ֺ�����һ���ԣ������ֵֹĹ���
	//�������������н����ÿգ��õ��ú��������Լ��������
}