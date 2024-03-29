/*数据结构和项目学习
//这两个课都非常的长，要上特别久的时间

数据结构初阶————>C++

数据结构用C语言实现，提高代码能力欸嘿

为什么不把数据结构一次性讲完呢？因为难一点的内容不适合用C语言来讲解
缺少很多库啊，缺少模板啥的，所以不能这么整啦
数据结构 20节课

C++: 50节课
C++语法

然后高阶数据结构

然后STL.. （这里面本身的核心就是数据结构

我们还有LINUX系统编程和网络编程
后面有会和C++穿插进行
LINUX环境会有命令行啥的，会学他们的工具和指令
一直并行到最后 基本上就上完了
然后就开始讲项目啦
LINUX目测也是4、50节课，环境-系统编程-网络编程-数据库
穿插着上课
大概什么时候结课呢？我们105期是今年年底开班的，有寒假班的，是105期的
我们今年3月份结课

我们学完了之后会安排模拟面试和刷题训练，加油加油gogogo

开始我们的课程啦！！！！   
*/

/*
什么是数据结构？
很多书本化的介绍我们就 不大解说了，

我们在内存中存储管理数据的结构    就叫数据结构
C语言，我们讲过一个小程序，叫做通讯录
我们在实现的时候，会有一个扩容的过程，有动态的 有静态的版本
我们那个存储的机构就叫做顺序表
其实我们的通讯录不仅仅可以使用顺序表还有链表
我们还有更复杂的结构，例如 搜索树和哈希表，这也是一些数据结构
没有一个数据结构能解决所有问题

数据结构和数据库有什么区别？
本质都是 存储管理数据，
而数据结构--是在内存中存储管理数据
 数据库--是在磁盘中存储管理数据
 
 算法 是对数据按要求进行某种处理。 例如 查找、排序
 
  B树/B+树/B*树-- 二分查找算法
  数据结构和算法的关系 是 你中有我，我中有你

后面会有笔试强训以及算法课程啥的
都是单独的

这就是我们一些单独的介绍

*/

/*
为什么要学习数据结构？

数据结构是跨学科的

无论我们走什么代码方向都会学数据结构，
在计算机行业中，最终都会面向项目，项目中都会存储数据啥的

学习目的： IT类公司先投递简历，网申建立
然后开始 笔试  --笔试通过后--进行面试3次左右--然后发放offer

然后就正式入职了，

现阶段不推荐买书
如果真的要推荐的话，那就是严薇敏老师的数据结构
殷人昆的数据结构
还有 剑指offer  名企面试书籍
*/

/*
学习数据结构时，C语言的功底必须扎实
后面也一样，C++ LINUX都会依托C语言的基础

C语言，你能否听完课程后独立实现通讯录，那么功底就不错  否则的话 是需要补一补基础知识的
每一个班学着学着人都会人少很多，因为C语言的指针知识不扎实
二叉树和排序都需要一个功底，因为二叉树比较难，会比较吃力

很需要个人理解能力和作业情况
建议：： 如果C语言达不到要求的话，一定要边学数据结构便补充C语言知识

*/

//正式内容 ：  复杂度的讲解

//链表开始，我们就对指针和结构有要求了很好

//复杂度的计算
//复杂度是衡量一个算法效率高低的标准
/*
* 
* 复杂度分为 2种
//  时间复杂度
// 空间复杂度

现在我们不太关注空间复杂度，主要关注时间复杂度
现在我们的程序都是希望它越流畅越好，越快越好  但是不大关注它的大小
现在的手机内存都很猛，内存越来越高了

因为有一个 摩尔定律 ： 每一年半 芯片性能翻倍，价格降低

我们要关注的重点是 时间 ，我们希望程序的时间复杂度降低，性能提高

时间复杂度的概念：  我们不关注它运行了多少秒，
   算法的时间复杂度 是一个函数

   例如 冒泡排序对10000个数据进行排序
   我们用i7cpu 和16G内存的机器
       和i3cpu 和2G内存的机器
   一个算法运行时间跟硬件配置有关系，所以同样一个算法是没办法算出准确时间的

    冒泡排序：O(N^2)
    快速排序：O(logN)

由于准确时间复杂度函数式 ，不方便在算法之间进行比较  于是有了下面的表示方法

2.2 大O的渐进表示法   是一种估算，为了方便比较

1.用常数1取代运事件中的所有加法常数
2.再修改后的运行次数函数中，只保留最高阶项
3.如果最高阶项存在且不是1，则去除他的系数

特例： 我们 用大O的渐进表示法 遇到单独的常数时  必须用1替换该常数，即表示成O(1) 


示例4： strchr 函数  在字符串数组中查找一个字符

while(*str)   //helloworld
{
if(*str==character)     // h   d  w 
    return str;      
else
    ++str;
}
return NULL;

在有一些算法的时间复杂度中存在最好、平均和最坏的情况：
最坏情况： 任意输入规模的最大运行次数（上界）
平均情况： 任意输入规模的期望运行次数
最好情况： 任意输入规模的最小运行次数（下界）

我们所要的时间复杂度在实际中一般情况关注的是算法的最坏运行情况
所以数组中搜索数据时间复杂度为  O(N)
底线思维 底线思维 底线思维 啦啦啦

*/

//示例5
// 计算BubbleSort冒泡排序的时间复杂度？
void BubbleSort(int* a, int n)
{
    assert(a);
    for (size_t end = n; end > 0; --end)
    {
        int exchange = 0;
        for (size_t i = 1; i < end; ++i)
        {
            if (a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                exchange = 1;
            }
        }
        if (exchange == 0)
            break;
    }
}

//算时间复杂度不能去数循环，这个不一定正确，一定要看算法的思想来进行计算
//图1



//示例6
// 图2
// 计算BinarySearch（二分查找法）的时间复杂度？
int BinarySearch(int* a, int n, int x)
{
    assert(a);
    int begin = 0;
    int end = n - 1;
    //[begin end] begin 和end都是左闭右闭区间，因此我们有等号哈
    while (begin <= end)
    {
        //由于C语言学的东西忘了很多了，所以写一个备注
//二分查找法是我们设置一个数A,我们运用程序查找他的位置在哪
//其中查找的次数就是我们所需要的时间复杂度
        //然后我们在这个排好序的数组中利用中间值，快速分类排除数字位置
        //称为二分法
        int mid = begin + ((end - begin) >> 1);
        if (a[mid] < x)
            begin = mid + 1;
        else if (a[mid] > x)
            end = mid;
        else
            return mid;
    }
    return -1;
}
//图二

//时间复杂度是计算算法的执行次数
//一个执行次数：    不一定是一条语句    可能是多条语句    但是肯定是常数条语句
// 
// 我们要在文本中写对数不好写，而在时间复杂度中，log2 N经常出现，
//所以我们会把他简写成 logN
//在有些博客和书籍当中，他们写lgN 其实上是log2 N  (在数学中lgN是以10为底的）
//其实我们这以2为底，实际上就是2分的算法，每次都分二分之一

//O(N)   O(log N)之间的差距很大
//1000          10  (2^10=1024约等于1000）
//100W          20
//10亿          30   
//假设我们把中国所有同胞的身份证号放进一个数组中，通过排序+二分查找一个人的信息，只需要31次
//所以说 二分查找算法实际上是 一个很厉害的算法 ，但是死穴是排序 ，所以我们后面会变形，出现搜索树 B树啥的

//直接进入到了做题阶段
// 

//https://leetcode.cn/problems/missing-number-lcci/
//面试题 17.04.消失的数字

//思路2：
int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    for (int i = 0; i < numsSize + 1; i++)
    {
        x ^= i;
    }
    for (int j = 0; j < numsSize; j++)
    {
        x ^= nums[j];
    }
    return x;
}

//目前总共有四个思路
