//树： 
//节点的度： 一个节点含有的子树的个数成为该节点的度，如上图：A的为6
//叶节点或终端节点： 度为0的节点称为叶节点，称为叶节点，如上图的B,C,H,I等节点称为叶节点
//非终端节点或分支节点： 度不为0的节点，D,E,,F,G等节点为分支节点
//双亲结点或父节点： 若一个节点含有子节点，则这个节点称为其子节点的父节点 如上图，A是B的父节点
//孩子节点或子节点： 一个节点含有的子树的根节点称为该节点的子节点， 如上图 B是A的孩子节点
//兄弟节点： 具有相同父节点的节点胡成为兄弟节点， 如上图 B,C是兄弟节点
//树的度： 一棵树中，最大的节点的度称为树的度，如上图 树的度为6
//节点的层次： 从跟开始定义起，根为第一层，根的子节点为第2层，以此类推
//树的高度或深度： 树中节点的最大层次，如上图 树的高度为4
//堂兄弟节点： 双亲在同一层的节点互为堂兄弟， 如上图 H I互为堂兄弟节点
//节点的祖先： 从根到该节点所经分支上的所有节点 如上图 A是所有节点的祖先
//子孙： 以某节点为根的子树中任一节点都称为该节点的子孙，如上图： 所有节点都是A的子孙
//森林： 由m（m>0) 棵互不相交的树的集合称为森林

//祖先也可以是自己！
//

//树是递归定义的该如何理解？
//递归就是大问题包含小问题‘

//任何一棵树都被分为根和子树 ，而子树又可以被进行同样的划分
//直到被划分为不可再分割的叶节点，如同递归中不能再往下划分的小问题

//树和非树的概念：
//树中1.子树是不相交的
//2.除了根节点外，每个节点有且仅有一个父节点
//3.一棵N个节点的树有N-1条边
//  

/*
//1.3树的表示：

//假设我树的度是6
struct Treenode
{
	int data;
	struct TreeNode* child1;
	struct TreeNode* child2;
	struct TreeNode* child3;
	//这么做肯定会造成空间的浪费
};
struct TreeNode
{
	//我们转换成静态的
	int data;
	struct TreeNode* childArray[N];
};

//我们转换成动态的
//针对于不确定树的度
// 这种形式还是麻烦，C语言缺少一些库会很麻烦
//C++有库会方便特别多，不需要自己去写顺序表
//我们这里就是做个介绍，用顺序表去存孩子的指针，这也是一种树的表示方式
typedef struct TreeNode* SLDataType;
struct TreeNode
{
	int data;
	SeqList _childs;//顺序表存孩子的指针
	
};

//树的最优结构其实是 左孩子右兄弟表示法，这是最优表示方式
typedef int DataType;
struct TreeNode
{
	struct TreeNode* firstChild1;//第一个孩子节点
	struct TreeNode* pNextBrother;//指向其下一个兄弟节点(亲兄弟)
	DataType data;//节点中的数据域
};
//当然还有许多其他表示方式
*/


//1.4树再实际当中的应用
//： 表示文件系统的目录结构

//2.二叉树概念及结构(实行计划生育的树结构）
//2.1概念
//一棵二叉树是节点的一个有限集合，该集合：
//1. 或者为空  2.由一个根节点加上两棵别称为左子树和右子树的二叉树组成

//从上图可以看出 
//1.二叉树不存在度大于2的结点
//2.二叉树的子树有左右之分，次序不能颠倒，因此二叉树是有序树
//注意： 对于任意的二叉树都是由以下几种情况符合而成的

//特殊的二叉树： 
// 满二叉树
//每一层都是满的，即每一层的结点数都达到最大值
//如果一个二叉树的层数为k,且结点总数是2^k-1，则它就是满二叉树
//结点总数为等比数列的和S，2^k-1
// 
//完全二叉树： 
// 完全二叉树是效率很高的数据结构，完全二叉树是由满二叉树而引出来的
//对于深度为K的，有n个结点的二叉树，当且仅当每一个结点都与深度为K的满二叉树中编号从1至n的结点
//对应时 称之为完全二叉树，要注意的是满二叉树是一种特殊的完全二叉树
//简单说：  其前k-1层都是满的，最后一层不满，但是最后一层从左到右是连续的，

//二叉树的性质：
//1.若规定根节点的层数为1，则一颗非空二叉树的第i层上最多有2^(i-1)个结点
//2.若规定根节点的层数为1，则深度为h的二叉树的最大结点数是2^k-1
//3.对任何一棵二叉树，如果度为0其叶节点个数为n0,度为2的分支结点个数为n2.则有n0=n2+1
//4.若规定根节点的层数为1，具有n个结点的满二叉树的深度，h=log2^(n+1)  ps:以2为底n+1的对数




//T4. 高度为h的完全二叉树，节点范围是( 2^(h-1) , 2^h-1 )

//T5.常规题

//二叉树的存储结构
//二叉树一般可以使用两种结构存储，一种顺序结构，一种链式结构
//1.顺序存储
//顺序结构存储就是使用数组来存储， 一层一层存
//一般使用数组只适合表示满二叉树和完全二叉树
//因为不是完全二叉树会有空间的浪费。下面是解释

//如果用顺序存储，每一层的位置都是固定的，按照一定的顺序进行排列  请看图
//如果二叉树中那个位置没有节点，那么仍然保留它的位置，而其他节点按照其顺序位置进行存放

//顺序存储规律
//下标计算父子间的关系
// leftchild = parent*2+1
//rightchild = parent*2+2
//
//parent = (child-1)/2
//右孩子都是偶数，左孩子是奇数
//（6-2）/2 和（6-1）/2 的 整数 结果是一样的


//堆 
//堆是一种数据结构 
//是一种特殊的二叉树 使用数组进行存储
//堆又分为 小根堆和 大根堆
//小根堆的性质：  1.是一个完全二叉树 2.树中所有的父亲都是小于等于孩子的值
//大根堆的性质：  1.是一个完全二叉树 2.树中所有的父亲都是大于等于孩子的值
//逻辑结构是想象出来的 ， 物理空间上为数组 存储结构

//应用上 我们有 堆排序 --时间复杂度为O(N*log N)  本质上是一种选择排序
//2.topk  很多个数 选出最大的前K个数
#include"Heap.h"
void TestHeap()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	
	HeapPop(&hp);
	HeapPrint(&hp);


}
int main()
{
	TestHeap();
	return 0;
}






















