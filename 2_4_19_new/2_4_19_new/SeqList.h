#pragma once  //��ֹ�����ض���
#include<stdio.h>
#include<stdlib.h>
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
void SLInit(SL* ps);
