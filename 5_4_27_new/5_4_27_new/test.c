//1.���Ͻڿ���β

////1. ɾ�������е��ڸ���ֵ val �����нڵ㡣 OJ����
//https://leetcode.cn/problems/remove-linked-list-elements/description/

//struct ListNode* removeElements(struct ListNode* head,int val)
//{
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	while(cur)
//	{
//
//		if (cur->val == val)//����Ҫɾ�������
//		{
//			//ͷɾ
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else//��ͷɾ
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	};
//};


//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����//˼·����
//����ԭ���� �Ѳ���val�Ľڵ��ó�������β�嵽����������
//struct ListNode* removeElements(struct ListNode* head,int val)
//{
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//	head = NULL;
//	while(cur)
//	{
//		if (cur->val == val)//��val�������߳�ȥ
//		{
//			strcut ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else//β��������
//		{
//			if (tail == NULL)
//			{
//				head = tail = cur;
//			}
//			else
//			{
//				tail->next = cur;
//				tail = tail->next;
//			}
//		}
//		cur = cur->next;
//	};
//	if(tail!=NULL)
//		tail->next = NULL;
//	return head;
//};

//�Ż� �� ���ڱ�λ��������

//2.��תһ��������
//https://leetcode.cn/problems/reverse-linked-list/description/