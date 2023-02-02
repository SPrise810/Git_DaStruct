#include"queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	//这里也可以使用带哨兵位的，但是没有什么必要就不做了
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next=cur->next;
		free(cur);
		cur =next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//分为两种情况 一个数据都没有 ： 有数据
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//指向
		pq->tail = newnode;//转移箭头
	}
}
void QueuePop(Queue* pq)//删除  头删
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)//只剩一个节点
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next= pq->head->next;
		free(pq->head);
		pq->head = next;
	}

}
QDataType QueueFront(Queue* pq)//读队头元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)//读队尾元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
int	QueueSize(Queue* pq)
{
	//第一种方案 提高效率 在Queue，队列的结构体当中放入一个int 类型的计数器 

	//不在意效率 ，可以直接现场计数
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}










