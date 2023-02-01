//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//
////https://leetcode.cn/problems/remove-linked-list-elements/description/
////排除问题的第一个方法： 走读代码
////跟着代码的逻辑去一步步走
//
//
////第二个方法，写一个文件用VS去进行调试
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
//            //进行删除
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
////实际上这个题目深度运用了我们的在单链表模拟实现中的增删查改！
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            //头删
//            if (cur == head)//if(prev==NULL)
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//
//            }
//            else
//            {
//                //进行删除
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
////第二种思路
////固定空间，连续  使用双指针进行操作
////遍历原链表，把不是val的节点拿出来进行尾插到新链表
////新思路 新挑战
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
//    head = NULL;//针对[7,7,7,7]的情况，返回head仍指向 头节点为7 的野指针
//    while (cur)
//    {
//        //删除
//        if (cur->val == val)
//        {
//
//            struct ListNode* del = cur;
//            cur = cur->next;
//            free(del);
//        }
//        else
//        {
//            //尾插
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
////多去调试， 调试现在是必备技能
//
//
////变式题：如果增加哨兵位的节点！   那么这个问题就会得到极大的改善
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* tail = NULL;
//    struct ListNode* cur = head;
//    // 哨兵位的头节点
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    tail->next = NULL;
//    while (cur)
//    {
//        //删除
//        if (cur->val == val)
//        {
//
//            struct ListNode* del = cur;
//            cur = cur->next;
//            free(del);
//        }
//        else
//        {
//            // //尾插
//            // if(tail==NULL)
//            // {
//            //     head=tail=cur;
//            // }
//
//            //有了哨兵直接干就行了，因为第一个节点已经为空了
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
////2. 反转一个单链表。 https://leetcode.cn/problems/reverse-linked-list/description/
//
////反转单链表又叫做逆置单链表
//
//// 好好画图啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
////方法： 创建新链表，直接进行头插
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* cur = head;
//    struct ListNode* nehead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//       
//        //以下两步不能调换！
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
////思路二：  逆置 逆置 逆置
////把指针的方向颠倒呢？
////      能用循环别递归  递归容易炸，二叉树和快排可以，他们的思想比较符合子思想
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
//    if (!head)//如果链表为空
//        return NULL;
//    //          NULL cur next
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        //倒置指向
//        n2->next = n1;
//        //迭代
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//
//    return n1;
//}
//
////3.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//// 如果有两个中间结点，则返回第二个中间结点。
////https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
//
////运用快慢指针
////慢指针一次走一步
////快指针一次走两步
////当快指针走到尾的时候，慢指针就是中间节点
////因为人家是二倍速呀哈哈哈哈
////巧妙，真巧妙呀
////偶数有两个中位数 上中位数 下中位数  题目要求我们返回第二个节点
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
////第四题
////4. 输入一个链表，输出该链表中倒数第k个结点。
////https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//
////保持slow 和fast的距离为k, 那么当fast 为空时，slow的指向即为倒数第k个节点
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
//  * @param pListHead ListNode类
//  * @param k int整型
//  * @return ListNode类
//  */
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code heres
//    struct ListNode* slow, * fast;
//    slow = fast = pListHead;
//    while (k--)
//    {
//        if (fast == NULL)//说明fast还没有走出K步，即链表灭有K步那么长
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
////5. 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成
////的。
//
////OJ:https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
//
//
////归并思想：取小的元素尾插到新链表
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
//    //哨兵位写法：
//    struct ListNode* head, * tail;
//    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//    //哨兵位的的节点不存储有效数据
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
////6. 编写代码
////以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。
////https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//
////这个题只能用哨兵位来解决，没有哨兵位比较难写，很多测试用例都不好过
//
////比x小的尾插 到第一个链表
////比x大的尾插 到第二个链表
//
////第一次代码：
//
////极端场景情况：
////1.都比x小
////2.都比x大
////3.有大有小
//
//ListNode* partition(ListNode* pHead, int x) {
//    //我们以后做OJ题目 要考虑他的
//    // 极端边界
//    //并且在以后的面试考试过程中，我们也不会有测试用例来给我们
//    //因为在测试的时候可能会出现 知道测试用例以此来骗分的情况
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
////最终版本： 
////多了一个  greatertail->next = NULL;
//
//
//ListNode* partition(ListNode* pHead, int x) {
//    //我们以后做OJ题目 要考虑他的
//    // 极端边界
//    //并且在以后的面试考试过程中，我们也不会有测试用例来给我们
//    //因为在测试的时候可能会出现 知道测试用例以此来骗分的情况
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
////如果要用VS来调试我们的程序，但是我们的OJ链接又是他妈的C++
////我们直接把他写成一个函数就OK了
//
//ListNode* partition(ListNode* pHead, int x) {
//
//struct ListNode* partition(struct ListNode * pHead, int x) {
//
////第7题
//
//    //7. 链表的回文结构。
////https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-rankingk
//    //我们简单解释一下 回文结构  ，其实回文结构就是我们的 对称问题
//    //如果我们是数组的话，那么我们在中间弄俩指针，让他俩对称往外边走边判断
////1.用快慢指针找到中间节点
////2.然后逆置后面的链表
////然后我们开始进行比较  查找和逆置都学过，嘎嘎简单
//
////  这个代码不好的点是 侵入式编程，破坏了原先的链表结构，有些题目不能使用侵入式编程
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
//            if (!head)//如果链表为空
//                return NULL;
//            //          NULL cur next
//            struct ListNode* n1, * n2, * n3;
//            n1 = NULL;
//            n2 = head;
//            n3 = n2->next;
//            while (n2)
//            {
//                //倒置指向
//                n2->next = n1;
//                //迭代
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
//    //第八题：
////8. 输入两个链表，找出它们的第一个公共结点
////https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//
////判断两个链表有没有相交，（这里的相交是指 两个链表指向后面同一个节点）
////a链表的所有节点与b的节点相对比，一定是  对比节点的地址！
////如果全部比对一遍，时间复杂度为O(n^2),最坏的情况，两个链表没有共同交点
////简单想一想就是两层for循环，外层为a,内层为b。嘎嘎就是对比
////所以这种思路并不好
//
//    //求出a的长度 例如5
//    //求出b的长度 例如3
//    //长的A先走差距步2，然后同一个 长度位置 节点（同一起点）共同走,噶一下时间复杂度为O（n)
////代码其实差不多能写出来
////关键就是思路！！！！！！
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
//        //空的测试情况没有给,但我们给他写出来吧还是，严谨，玩的就是一个严谨
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
//        //求第一个交点
//        struct ListNode* shortList = headA;
//        struct ListNode* longList = headB;
//        if (lenA > lenB)
//        {
//            shortList = headB;
//            longList = headA;
//        }
//        int gap = abs(lenA - lenB);
//        //求完长度差异了
//
//        //长的先走gap步
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
////第九题
//
////环形链表
//        //9. 给定一个链表，判断链表中是否有环。
////https://leetcode.cn/problems/linked-list-cycle/description/
//
////有同学说 我们记录所有的节点，然后进行遍历看看有没有重复的
////这样其实可以，但是空间复杂度比较大
//
////这里我们使用快慢指针， 做成一个追及问题， 
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
////第十题
//
//        //10. 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
////https://leetcode.cn/problems/linked-list-cycle-ii/description/
//
////如何找到环的入口点？
//
////网上的代码用的两种指针，但是看起来是极为的抽象， 我们来瞅瞅怎么事儿
////给了两个指针，一个是head头指针，另一个是meet指针，他们会在环的入口相遇！
//
////假设： 环里面 入环前的一段为L，slow进环又走了x
//
////我们首先要说明一点，slow进环后，fast在二圈之内，一定追上了slow
//        //为什么呢？
////他们之间最多的相对距离就是一圈少一点， 即slow最多走半圈，fast就追上slow了
////fast走的路程是 ..NC+L+X     N=1，2，3... 即N>=1
////即2*（L+X)=L+X+NC
////L=NC-X;
////L=(N-1)*C+(C-x);即 相遇点+N倍圈 和头节点一起走 最终会在路口相遇
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
////新思路： head的链表 和newhead链表的相交问题
////算出head的长度，算出 newhead的长度，长的先走 长度相等之后再同时走


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

//11. 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝。
//https://leetcode.cn/problems/copy-list-with-random-pointer/description/

//其实深拷贝 有点偏向于C++的概念
// 
//大致的意思是完全的拷贝其链表，跟他的结构和形式完全是一模一样才行

 //深拷贝就是去拷贝出一个这样的节点，然后进行random链接 


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
    while (cur)//插入copy;
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    cur = head;//恢复头节点指向
    while (cur)//对copy进行random指向拷贝
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
            //进行random指向的赋值
        }
        cur = copy->next;
    }

    //3.分除原链表和复制链表 并恢复指向
    cur = head;
    struct Node* copyhead, * copytail;
    copyhead = copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        //对复制链表进行尾插结合，同时分离俩链表
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






