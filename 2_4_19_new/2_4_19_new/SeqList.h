#pragma once  //防止声名重定义
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 200
typedef int SLDataType;

//struct SeqList
//{
//	//int a[200];需改进  200在里面写着不好操作
//	//int a[N]	//在改进   我们不一定希望数组里元素的数据类型是 int型，希望他可以改变
//	SLDataType a[N];
//	int size;
//
//};
//这是一钟静态顺序表的形式,因为数组的大小是固定死的，万一超出范围那么就出错了

typedef struct SeqList
{
	SLDataType* a;//指向数组的指针
	int size;//数据中元素的个数
	int capacity;//元素容量 -- 空间大小

}SL;
//这是一种合理的动态版本

//开始着手于功能：  增删查改

//增删查改    -- 命名风格跟随 STL语言
void SLInit(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);
void SLDestory(SL* ps);
//在任意位置插入删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos, SLDataType x);