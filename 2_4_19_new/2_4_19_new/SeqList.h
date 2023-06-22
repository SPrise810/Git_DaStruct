#pragma once  //��ֹ�����ض���
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 200
typedef int SLDataType;

//struct SeqList
//{
//	//int a[200];��Ľ�  200������д�Ų��ò���
//	//int a[N]	//�ڸĽ�   ���ǲ�һ��ϣ��������Ԫ�ص����������� int�ͣ�ϣ�������Ըı�
//	SLDataType a[N];
//	int size;
//
//};
//����һ�Ӿ�̬˳������ʽ,��Ϊ����Ĵ�С�ǹ̶����ģ���һ������Χ��ô�ͳ�����

typedef struct SeqList
{
	SLDataType* a;//ָ�������ָ��
	int size;//������Ԫ�صĸ���
	int capacity;//Ԫ������ -- �ռ��С

}SL;
//����һ�ֺ���Ķ�̬�汾

//��ʼ�����ڹ��ܣ�  ��ɾ���

//��ɾ���    -- ���������� STL����
void SLInit(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);
void SLDestory(SL* ps);
//������λ�ò���ɾ��
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos, SLDataType x);