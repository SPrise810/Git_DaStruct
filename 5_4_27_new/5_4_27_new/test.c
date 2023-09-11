//1.先上节课收尾

////1. 删除链表中等于给定值 val 的所有节点。 OJ链接
//https://leetcode.cn/problems/remove-linked-list-elements/description/

struct ListNode* removeElements(struct ListNode* head,int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while(cur)
	{

		if (cur->val == val)//有需要删除的情况
		{
			//头删
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else//非头删
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	};
};