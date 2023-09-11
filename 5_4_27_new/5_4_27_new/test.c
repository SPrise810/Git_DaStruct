//1.先上节课收尾

////1. 删除链表中等于给定值 val 的所有节点。 OJ链接
//https://leetcode.cn/problems/remove-linked-list-elements/description/

//struct ListNode* removeElements(struct ListNode* head,int val)
//{
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	while(cur)
//	{
//
//		if (cur->val == val)//有需要删除的情况
//		{
//			//头删
//			if (cur == head)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else//非头删
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


//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：//思路二：
//遍历原链表， 把不是val的节点拿出来进行尾插到新链表中来
//struct ListNode* removeElements(struct ListNode* head,int val)
//{
//	struct ListNode* tail = NULL;
//	struct ListNode* cur = head;
//	head = NULL;
//	while(cur)
//	{
//		if (cur->val == val)//是val，给它踢出去
//		{
//			strcut ListNode* del = cur;
//			cur = cur->next;
//			free(del);
//		}
//		else//尾插新链表
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

//优化 ： 带哨兵位的新链表

//2.反转一个单链表
//https://leetcode.cn/problems/reverse-linked-list/description/