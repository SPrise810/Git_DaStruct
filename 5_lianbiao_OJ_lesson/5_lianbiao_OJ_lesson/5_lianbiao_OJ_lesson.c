//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//
////https://leetcode.cn/problems/remove-linked-list-elements/description/
////�ų�����ĵ�һ�������� �߶�����
////���Ŵ�����߼�ȥһ������
//
//
////�ڶ���������дһ���ļ���VSȥ���е���
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur)
//    {
//
//        if (cur->val == val)
//        {
//            //����ɾ��
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//int main()
//{
//    ;
//
//    return 0;
//}
//
//
////ʵ���������Ŀ������������ǵ��ڵ�����ģ��ʵ���е���ɾ��ģ�
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            //ͷɾ
//            if (cur == head)//if(prev==NULL)
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//
//            }
//            else
//            {
//                //����ɾ��
//                prev->next = cur->next;
//                free(cur);
//                cur = prev->next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}
//
////https://leetcode.cn/problems/remove-linked-list-elements/description/
////�ڶ���˼·
////�̶��ռ䣬����  ʹ��˫ָ����в���
////����ԭ�����Ѳ���val�Ľڵ��ó�������β�嵽������
////��˼· ����ս
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* tail = NULL;
//    struct ListNode* cur = head;
//    head = NULL;//���[7,7,7,7]�����������head��ָ�� ͷ�ڵ�Ϊ7 ��Ұָ��
//    while (cur)
//    {
//        //ɾ��
//        if (cur->val == val)
//        {
//
//            struct ListNode* del = cur;
//            cur = cur->next;
//            free(del);
//        }
//        else
//        {
//            //β��
//            if (tail == NULL)
//            {
//                head = tail = cur;
//            }
//            else
//            {
//                tail->next = cur;
//                tail = tail->next;
//            }
//            cur = cur->next;
//        }
//    }
//    if (tail)
//        tail->next = NULL;
//    return head;
//}
//
////��ȥ���ԣ� ���������Ǳر�����
//
//
////��ʽ�⣺��������ڱ�λ�Ľڵ㣡   ��ô�������ͻ�õ�����ĸ���
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* tail = NULL;
//    struct ListNode* cur = head;
//    // �ڱ�λ��ͷ�ڵ�
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = NULL;
//    while (cur)
//    {
//        //ɾ��
//        if (cur->val == val)
//        {
//
//            struct ListNode* del = cur;
//            cur = cur->next;
//            free(del);
//        }
//        else
//        {
//            // //β��
//            // if(tail==NULL)
//            // {
//            //     head=tail=cur;
//            // }
//
//            //�����ڱ�ֱ�Ӹɾ����ˣ���Ϊ��һ���ڵ��Ѿ�Ϊ����
//            // else
//            // {
//            tail->next = cur;
//            tail = tail->next;
//            // }
//            cur = cur->next;
//        }
//    }
//tail->next = NULL;
//struct ListNode* del = head;
//head = head->next;
//free(del);
//    return head;
//}
//
////2. ��תһ�������� https://leetcode.cn/problems/reverse-linked-list/description/
//
////��ת�������ֽ������õ�����
//
//// �úû�ͼ�������������������������������������������������� 
////������ ����������ֱ�ӽ���ͷ��
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* cur = head;
//    struct ListNode* nehead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//       
//        //�����������ܵ�����
//        cur->next = nehead;//cur->next=NULL
//        nehead = cur;
//
// 
//
//        cur = next;
//        //     if(nehead==NULL)
//        //     {
//        //         nehead=cur;
//        //     }
//        // nehead->next=cur;
//        // next=cur->next;
//        // cur=next;
//    }
//    return nehead;
//}
//
//
////˼·����  ���� ���� ����
////��ָ��ķ���ߵ��أ�
////      ����ѭ����ݹ�  �ݹ�����ը���������Ϳ��ſ��ԣ����ǵ�˼��ȽϷ�����˼��
//
// /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* reverseList(struct ListNode* head) {
//    if (!head)//�������Ϊ��
//        return NULL;
//    //          NULL cur next
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        //����ָ��
//        n2->next = n1;
//        //����
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//
//    return n1;
//}
//
////3.����һ������ͷ��� head �ķǿյ���������������м��㡣
//// ����������м��㣬�򷵻صڶ����м��㡣
////https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
//
////���ÿ���ָ��
////��ָ��һ����һ��
////��ָ��һ��������
////����ָ���ߵ�β��ʱ����ָ������м�ڵ�
////��Ϊ�˼��Ƕ�����ѽ��������
////���������ѽ
////ż����������λ�� ����λ�� ����λ��  ��ĿҪ�����Ƿ��صڶ����ڵ�
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//
////������
////4. ����һ����������������е�����k����㡣
////https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//
////����slow ��fast�ľ���Ϊk, ��ô��fast Ϊ��ʱ��slow��ָ��Ϊ������k���ڵ�
//
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// * };
// */
//
// /**
//  *
//  * @param pListHead ListNode��
//  * @param k int����
//  * @return ListNode��
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code heres
//    struct ListNode* slow, * fast;
//    slow = fast = pListHead;
//    while (k--)
//    {
//        if (fast == NULL)//˵��fast��û���߳�K��������������K����ô��
//        {
//            return fast;
//        }
//        fast = fast->next;
//
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}
//
////5. ��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ����
////�ġ�
//
////OJ:https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
//
//
////�鲢˼�룺ȡС��Ԫ��β�嵽������
//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* head, * tail;
//    head = tail = NULL;
//    if (list1 == NULL)
//        return list2;
//    if (list2 == NULL)
//        return list1;
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            if (tail == NULL)
//            {
//                head = tail = list1;
//            }
//            else
//            {
//                tail->next = list1;
//                tail = tail->next;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                head = tail = list2;
//            }
//            else
//            {
//                tail->next = list2;
//                tail = tail->next;
//            }
//            list2 = list2->next;
//        }
//    }
//    if (list1)
//        tail->next = list1;
//    if (list2)
//        tail->next = list2;
//    return head;
//}
//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    //�ڱ�λд����
//    struct ListNode* head, * tail;
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    //�ڱ�λ�ĵĽڵ㲻�洢��Ч����
//    tail->next = NULL;
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//
//            tail->next = list1;
//            tail = tail->next;
//
//            list1 = list1->next;
//        }
//        else
//        {
//
//            tail->next = list2;
//            tail = tail->next;
//
//            list2 = list2->next;
//        }
//    }
//    if (list1)
//        tail->next = list1;
//    if (list2)
//        tail->next = list2;
//    struct ListNode* list = head->next;
//    free(head);
//    return list;
//}
//
//
////6. ��д����
////�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ ��
////https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//
////�����ֻ�����ڱ�λ�������û���ڱ�λ�Ƚ���д���ܶ�������������ù�
//
////��xС��β�� ����һ������
////��x���β�� ���ڶ�������
//
////��һ�δ��룺
//
////���˳��������
////1.����xС
////2.����x��
////3.�д���С
//
//ListNode* partition(ListNode* pHead, int x) {
//    //�����Ժ���OJ��Ŀ Ҫ��������
//    // ���˱߽�
//    //�������Ժ�����Կ��Թ����У�����Ҳ�����в���������������
//    //��Ϊ�ڲ��Ե�ʱ����ܻ���� ֪�����������Դ���ƭ�ֵ����
//    struct ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
//    greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode*));
//    lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode*));
//    greatertail->next = NULL;
//    lesstail->next = NULL;
//    struct ListNode* cur = pHead;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            lesstail->next = cur;
//            lesstail = lesstail->next;
//        }
//        else
//        {
//            greatertail->next = cur;
//            greatertail = greatertail->next;
//        }
//        cur = cur->next;
//    }
//    lesstail->next = greaterhead->next;
//    struct ListNode* head = lesshead->next;
//    free(lesshead);
//    free(greaterhead);
//    return head;
//}
//
////���հ汾�� 
////����һ��  greatertail->next = NULL;
//
//
//ListNode* partition(ListNode* pHead, int x) {
//    //�����Ժ���OJ��Ŀ Ҫ��������
//    // ���˱߽�
//    //�������Ժ�����Կ��Թ����У�����Ҳ�����в���������������
//    //��Ϊ�ڲ��Ե�ʱ����ܻ���� ֪�����������Դ���ƭ�ֵ����
//    struct ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
//    greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode*));
//    lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode*));
//    greatertail->next = NULL;
//    lesstail->next = NULL;
//    struct ListNode* cur = pHead;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            lesstail->next = cur;
//            lesstail = lesstail->next;
//        }
//        else
//        {
//            greatertail->next = cur;
//            greatertail = greatertail->next;
//        }
//        cur = cur->next;
//    }
//    lesstail->next = greaterhead->next;
//    greatertail->next = NULL;
//    struct ListNode* head = lesshead->next;
//    free(lesshead);
//    free(greaterhead);
//    return head;
//}
//
////���Ҫ��VS���������ǵĳ��򣬵������ǵ�OJ�������������C++
////����ֱ�Ӱ���д��һ��������OK��
//
//ListNode* partition(ListNode* pHead, int x) {
//
//struct ListNode* partition(struct ListNode * pHead, int x) {
//
////��7��
//
//    //7. ����Ļ��Ľṹ��
////https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-rankingk
//    //���Ǽ򵥽���һ�� ���Ľṹ  ����ʵ���Ľṹ�������ǵ� �Գ�����
//    //�������������Ļ�����ô�������м�Ū��ָ�룬�������Գ�������߱��ж�
////1.�ÿ���ָ���ҵ��м�ڵ�
////2.Ȼ�����ú��������
////Ȼ�����ǿ�ʼ���бȽ�  ���Һ����ö�ѧ�����¸¼�
//
////  ������벻�õĵ��� ����ʽ��̣��ƻ���ԭ�ȵ�����ṹ����Щ��Ŀ����ʹ������ʽ���
//
////
//    /*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//    class PalindromeList {
//    public:
//        struct ListNode* middleNode(struct ListNode* head) {
//            struct ListNode* slow, * fast;
//            slow = fast = head;
//            while (fast && fast->next)
//            {
//                slow = slow->next;
//                fast = fast->next->next;
//            }
//            return slow;
//        }
//
//        struct ListNode* reverseList(struct ListNode* head) {
//            if (!head)//�������Ϊ��
//                return NULL;
//            //          NULL cur next
//            struct ListNode* n1, * n2, * n3;
//            n1 = NULL;
//            n2 = head;
//            n3 = n2->next;
//            while (n2)
//            {
//                //����ָ��
//                n2->next = n1;
//                //����
//                n1 = n2;
//                n2 = n3;
//                if (n3)
//                    n3 = n3->next;
//            }
//
//            return n1;
//        }
//        bool chkPalindrome(ListNode* A) {
//            // write code here
//            struct ListNode* head = A;
//            struct ListNode* mid = middleNode(head);
//            struct ListNode* rhead = reverseList(mid);
//            while (head && rhead)
//            {
//                if (head->val != rhead->val)
//                {
//                    return false;
//                }
//                else
//                {
//                    head = head->next;
//                    rhead = rhead->next;
//                }
//            }
//            return true;
//        }
//    };
//
//
//    //�ڰ��⣺
////8. �������������ҳ����ǵĵ�һ���������
////https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//
////�ж�����������û���ཻ����������ཻ��ָ ��������ָ�����ͬһ���ڵ㣩
////a��������нڵ���b�Ľڵ���Աȣ�һ����  �ԱȽڵ�ĵ�ַ��
////���ȫ���ȶ�һ�飬ʱ�临�Ӷ�ΪO(n^2),����������������û�й�ͬ����
////����һ���������forѭ�������Ϊa,�ڲ�Ϊb���¸¾��ǶԱ�
////��������˼·������
//
//    //���a�ĳ��� ����5
//    //���b�ĳ��� ����3
//    //����A���߲�ಽ2��Ȼ��ͬһ�� ����λ�� �ڵ㣨ͬһ��㣩��ͬ��,��һ��ʱ�临�Ӷ�ΪO��n)
////������ʵ�����д����
////�ؼ�����˼·������������
//
//    /**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//        struct ListNode* curA = headA, * curB = headB;
//        int lenA = 0, lenB = 0;
//        //�յĲ������û�и�,�����Ǹ���д�����ɻ��ǣ��Ͻ�����ľ���һ���Ͻ�
//        if(headA||headB==NULL)
//        {
//            return NULL;
//        while (curA->next)
//        {
//            curA = curA->next;
//            lenA++;
//        }
//        while (curB->next)
//        {
//            curB = curB->next;
//            lenB++;
//        }
//        if (curA != curB)
//        {
//            return NULL;
//        }
//
//        //���һ������
//        struct ListNode* shortList = headA;
//        struct ListNode* longList = headB;
//        if (lenA > lenB)
//        {
//            shortList = headB;
//            longList = headA;
//        }
//        int gap = abs(lenA - lenB);
//        //���곤�Ȳ�����
//
//        //��������gap��
//        while (gap--)
//        {
//            longList = longList->next;
//        }
//        while (shortList != longList)
//        {
//            shortList = shortList->next;
//            longList = longList->next;
//        }
//        return shortList;
//    }
//
//
////�ھ���
//
////��������
//        //9. ����һ�������ж��������Ƿ��л���
////https://leetcode.cn/problems/linked-list-cycle/description/
//
////��ͬѧ˵ ���Ǽ�¼���еĽڵ㣬Ȼ����б���������û���ظ���
////������ʵ���ԣ����ǿռ临�ӶȱȽϴ�
//
////��������ʹ�ÿ���ָ�룬 ����һ��׷�����⣬ 
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//        bool hasCycle(struct ListNode* head) {
//            struct ListNode* fast = head, * slow = head;
//            while (fast && fast->next)
//            {
//                slow = slow->next;
//                fast = fast->next->next;
//                if (slow == fast)
//                {
//                    return true;
//                }
//            }
//            return false;
//        }
//
////��ʮ��
//
//        //10. ����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
////https://leetcode.cn/problems/linked-list-cycle-ii/description/
//
////����ҵ�������ڵ㣿
//
////���ϵĴ����õ�����ָ�룬���ǿ������Ǽ�Ϊ�ĳ��� �����������ô�¶�
////��������ָ�룬һ����headͷָ�룬��һ����meetָ�룬���ǻ��ڻ������������
//
////���裺 ������ �뻷ǰ��һ��ΪL��slow����������x
//
////��������Ҫ˵��һ�㣬slow������fast�ڶ�Ȧ֮�ڣ�һ��׷����slow
//        //Ϊʲô�أ�
////����֮��������Ծ������һȦ��һ�㣬 ��slow����߰�Ȧ��fast��׷��slow��
////fast�ߵ�·���� ..NC+L+X     N=1��2��3... ��N>=1
////��2*��L+X)=L+X+NC
////L=NC-X;
////L=(N-1)*C+(C-x);�� ������+N��Ȧ ��ͷ�ڵ�һ���� ���ջ���·������
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//        bool hasCycle(struct ListNode* head) {
//            struct ListNode* fast = head, * slow = head;
//            while (fast && fast->next)
//            {
//                slow = slow->next;
//                fast = fast->next->next;
//                if (slow == fast)
//                {
//                    struct ListNode* met = slow;
//                    while (met != head)
//                    {
//                        met = met->next;
//                        head = head->next;
//                    }
//                    return met;
//                }
//            }
//            return NULL;
//        }
//
////��˼·�� head������ ��newhead������ཻ����
////���head�ĳ��ȣ���� newhead�ĳ��ȣ��������� �������֮����ͬʱ��


int removeElement(int* nums, int numsSize, int val)
{
    int* ret = nums;
    int* p = nums;
    int* tmp = nums;
    int i = 0;
    while (tmp)
    {
        if (*tmp != val)
        {
            *p = *tmp;
            p++;
            tmp++;
        }
        else
        {
            tmp++;
        }
    }
    return ret;
}
int main()
{
    int nums[4] = { 3,2,2,3 };
    removeElement(nums, 4, 3);
}

//11. ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻�����������ȿ�����
//https://leetcode.cn/problems/copy-list-with-random-pointer/description/

//��ʵ��� �е�ƫ����C++�ĸ���
// 
//���µ���˼����ȫ�Ŀ��������������Ľṹ����ʽ��ȫ��һģһ������

 //�������ȥ������һ�������Ľڵ㣬Ȼ�����random���� 


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)//����copy;
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    cur = head;//�ָ�ͷ�ڵ�ָ��
    while (cur)//��copy����randomָ�򿽱�
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
            //����randomָ��ĸ�ֵ
        }
        cur = copy->next;
    }

    //3.�ֳ�ԭ����͸������� ���ָ�ָ��
    cur = head;
    struct Node* copyhead, * copytail;
    copyhead = copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        //�Ը����������β���ϣ�ͬʱ����������
        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}






