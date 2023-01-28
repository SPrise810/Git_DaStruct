//管理数据： 增删查改
#include"Seqlist.h"
void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	//SLPushBack(&sl, 2);
	//SLPushBack(&sl, 3);
	//SLPushBack(&sl, 4);
	//SLPushBack(&sl, 5);
	//调试看好麻烦，我们写个print
	SLPrint(&sl);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

}
void TestSeqList2()//测试尾删
//我们这里需要了解删除的过程中可能出现多删的情况，导致越界
//然而越界是不一定报错的，因为系统对越界的检查是 设岗抽查
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 4);

	SLPrint(&sl);
	int x = 0;
	printf("请输入你要删除的数据！");
	scanf("%d", &x);
	int ret=SLFind(&sl, x);
	while(ret!=-1)
	{
		SLErase(&sl, ret);
		ret = SLFind(&sl, x);
		printf("已删除%d \n",x);
		SLPrint(&sl);
		if (ret == -1)
		{
			printf("未找到该数据！");
		}
	}
}

void menu()
{
	printf("*********************\n");
	printf("*****1.尾插2.头插*****\n");
	printf("*****3.查找4.删除*****\n");
	printf("*****5.修改6.打印*****\n");
	printf("********-1.退出*******\n");

}
int main()
{
	SL sl;
	SLInit(&sl);
	int option = -1;
	do
	{
		menu();
		if (scanf("%d", &option) == EOF)
		{
			printf("scanf输入错误");
			//顺手清除一下缓冲区
			continue;
		}
		int val=0, pos=0;
		switch (option)
		{
		case 1:
			//printf("请输入你要插入的数据：>");
			printf("请连续输入你要插入的数据，以-2结束：>");
			scanf("%d", &val); 
			/*如果我们在这个地方输入字母的话，我们的scanf函数会去缓冲区寻找%d形式的值，但是
			因为找不到相当于没有读到值 会发生错误，最终返回EOF*/
			while (val != -2)//这样操作的缺点就是不能再插入0
			{
				SLPushBack(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			SLPrint(&sl);
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			printf("输入错误，请重新输入：>");
			break;
		}
	} while (option!=-1);

	return 0;
}
//顺序表重在理解逻辑，并且会敲代码实现顺序表

//最后我们讲了三个题目，同时也是我们的作业，  一定一定一定一定要画图做题