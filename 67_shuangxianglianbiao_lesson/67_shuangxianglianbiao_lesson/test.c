#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

//链表其实有八种组合的结构
//1.单向  双向  2.带头或不带头（哨兵位）  3.循环或非循环 
//三种两两结合
//我们一开始学的是 ： 单向 不带头 不循环

//我们的哈希表 邻接不带头矩阵都是这样的
//我们要学的是 双向 带头 循环  
//听起来很难， 结构复杂 但是它操作简单
//学完这个链表 就会感觉其他链表都是垃圾

void TestList1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
}
void TestList2()
{
	LTNode* plist = ListInit();
	ListPushFront(plist, 5);
	ListPushFront(plist, 5);
	ListPushFront(plist, 5);
	ListPushFront(plist, 5);
	ListPushFront(plist, 5);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);
	
	ListPopBack(plist);
	ListPrint(plist);
	
	ListPopBack(plist);
	ListPrint(plist);
	
	ListPopBack(plist);
	ListPrint(plist);

}


//虽然我们的链表有8种结构

//但最实用的还是无头单向非循环链表： 结构简单，一般不会单独用来存数据，实际中更多是作为其他数据结构的
//子结构，如哈希桶，图的邻接表，在笔试面试中出现过很多次了

//带头双向循环链表： 结构最复杂，一般用在 单独存储数据。实际中使用的链表数据结构，都是带头双向循环链表
//另外这个结构虽然结构复杂，但是使用代码实现以后会发现结构会带来很多优势
// 实现反而简单了，后面我们代码实现了就知道了

//但我们的链表不能完全代替 顺序表

//它的缺点是不能进行随机访问，即下标访问
//物理空间上是不连续的 ！

//第二个比方， 对二分查找来说，链表无法进行操作。 
//它实际上和顺序表是相辅相成的/
//我们的带头双向链表其实最重要的地方是 这个Insert插入，使得头插头删尾插尾删都能够很好的实现




//顺序表和链表（带头双向列表）的区别
//顺序表优点：  可进行下表随机访问
//缺点： 头部或中间插入删除效率低，扩容（有一定程度性能的消耗、可能存在一定程度的空间浪费）

//链表优点L:任意位置插入删除  时间复杂度为O(1) 按需申请释放
// 缺点： 不支持下标的随机访问！
//

//两者缺点优点互相对应，相辅相成

//补充知识： 顺序表的优点： CPU高速缓存命中率高相对于链表而言。
//
int main()
{
	TestList2();

	return 0;
}







