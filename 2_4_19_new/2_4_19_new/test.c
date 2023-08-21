#include"SeqList.h"
void TestSeqList1()
{
	SL sl;
	SLInit(&sl);//形参的改变不会影响实参，所以我们用 
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPrint(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPrint(&sl);
}
void TestSeqList2()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPrint(&sl);
}
void TestSeqList3()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);

	SLDestory(&sl);//越界问题 内存问题 野指针问题 
}
void TestSeqList4()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	SLInsert(&sl, 4, 5);
	SLPushFront(&sl, 0);
	SLPrint(&sl);
	SLDestory(&sl);//越界问题 内存问题 野指针问题 
}
void TestSeqList5()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);	
	SLPrint(&sl);
	SLErase(&sl, 3);
	SLPrint(&sl);

}
void TestSeqList6()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	printf("请输入你要删除的数据并插入：\n");
	int a, b = 0;
	scanf("%d %d",&a,&b);
	if (SLFind(&sl, a)!=-1)
	{
		int pos = SLFind(&sl, a);
		SLErase(&sl, pos);
		SLInsert(&sl, pos, b);
	}
	SLPrint(&sl);
}
void TestSeqList7()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	

}
void menu()
{
	printf("*************************\n");
	printf("******1.尾插2.头插********\n");
	printf("******5.查找6.删除********\n");
	printf("******7.修改8.打印********\n");
	printf("*********-1.退出**********\n");
	printf("*************************\n");

}
int main()
{
	//代码出错先去调试代码  设置断点 一步步进行
	// 
	// 程序越界它不一定会报错
	/*
	//系统对越界的检查，是一种 设岗抽查。 和查酒驾一样，不一定能碰到警察
	int a[10];
	a[0]=0;
	//a[10]=0;试一次
	a[11]=1;//试一次
	//a[12]=1;//你再试一次
	*/

	//空指针问题：  0x00F415E1 处有未经处理的异常.....  写入位置0x00000000时发生访问冲突
    //空指针问题 从而引出一种 防御式编程
	//防御式编程 ： 在有传递参数的函数里面  为了防止参数为空 进行assert断言 

	//输入数据尽量放在测试函数里面，因为放在数据结构里面的话，会干扰它的正常结构
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	//TestSeqList5();
	//TestSeqList6();
	SL sl;
	SLInit(&sl);
	int option = -1;
	do
	{
		menu();
		if (scanf("%d", &option) == EOF)
			//scanf里的操作
			//首先scanf函数通过%d得出方法，它将要在缓冲区拿取整型形式的值
			//但是如果我们输入一个字母，那么就出错了，相当于它没有得到值，通过函数本身可以知道，我们发生错误或者读到文件结束，会返回EOF
		{
			printf("scanf输入错误\n");
			//continue;//还需要清除缓冲区，所以直接break
			break;//
		}
		int val, pos;
		int y, z;
		switch (option)
		{
		case 1:
			printf("请输入你要尾插插入的全部数据：以0为结束>");
			scanf("%d", &val);
			while (val != 0)
			{
				SLPushBack(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 2:				
			printf("请输入你要头插插入的数据：以0为结束>");
			scanf("%d", &val);
			while (val != 0)
			{
				SLPushFront(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			//printf("请输入你要修改的原数据和修改后的数据");
			//scanf("%d %d", &y,&z);
			//SLModify(&sl, &val, &y);

			printf("请输入你要修改的值和修改后的值:\n");
			scanf("%d%d", &y, &z);
			pos = SLFind(&sl, y);
			if (pos != -1)
			{
				SLModify(&sl, pos, z);
			}
			else
			{
				printf("没有找到%d\n",y);
			}
			break;
		case 8:
			SLPrint(&sl);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (option != -1);

	SLDestory(&sl);

	return 0;
}


  