#include"queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	//����Ҳ����ʹ�ô��ڱ�λ�ģ�����û��ʲô��Ҫ�Ͳ�����
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
	//��Ϊ������� һ�����ݶ�û�� �� ������
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
		pq->tail->next = newnode;//ָ��
		pq->tail = newnode;//ת�Ƽ�ͷ
	}
}
void QueuePop(Queue* pq)//ɾ��  ͷɾ
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)//ֻʣһ���ڵ�
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
QDataType QueueFront(Queue* pq)//����ͷԪ��
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)//����βԪ��
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
	//��һ�ַ��� ���Ч�� ��Queue�����еĽṹ�嵱�з���һ��int ���͵ļ����� 

	//������Ч�� ������ֱ���ֳ�����
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










