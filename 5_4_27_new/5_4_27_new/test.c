//1.���Ͻڿ���β

////1. ɾ�������е��ڸ���ֵ val �����нڵ㡣 OJ����
//https://leetcode.cn/problems/remove-linked-list-elements/description/

struct ListNode* removeElements(struct ListNode* head,int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while(cur)
	{

		if (cur->val == val)//����Ҫɾ�������
		{
			//ͷɾ
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else//��ͷɾ
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