#pragma once// 防止重定义
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//struct SeqList
//{
//	int a[100];
//	int size;
//};
//这就是一个顺序表的小雏形
//为了防止我们的顺序表存储的内容过大，类型出错，我们用宏代替
//#define N 100
//typedef int DataType;
//struct SeqList
//{
//	DataType a[N];
//	int size;
//};
//这是一种静态顺序表-- N太小， 可能不够用，  N太大可能浪费空间

//所以我们就变一变，利用通讯录学的动态内存 来开辟空间
#define N 200
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;	//指向动态数组指针
	int size;		//数据个数
	int capacity;	//容量-空间大小
}SL;
//增删查改：
void SInit(SL* ps);//初始化
void Destory(SL* ps);//销毁

//头插 头删 尾插 尾删  --其名字是 TSL代码风格，C++会重点学，好好跟着老师来，别搞事

//时间复杂度O(1)尾插 尾删 优先使用！
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//时间复杂度O(N)头插 头删
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLPrint(SL* ps);
void SLPCheckCapacity(SL* ps);
//任意位置添加和删除
void SLInsert(SL* ps, int pos, SLDataType x);//在某个位置插入数据
void SLErase(SL* ps, int pos);//删除所在位置数据
//查找和修改
int SLFind(SL* ps, SLDataType x);
void SLModify(SL* ps, int pos, SLDataType x);