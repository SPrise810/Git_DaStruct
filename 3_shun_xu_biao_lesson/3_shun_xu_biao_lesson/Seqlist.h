#pragma once// ��ֹ�ض���
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//struct SeqList
//{
//	int a[100];
//	int size;
//};
//�����һ��˳����С����
//Ϊ�˷�ֹ���ǵ�˳���洢�����ݹ������ͳ��������ú����
//#define N 100
//typedef int DataType;
//struct SeqList
//{
//	DataType a[N];
//	int size;
//};
//����һ�־�̬˳���-- N̫С�� ���ܲ����ã�  N̫������˷ѿռ�

//�������Ǿͱ�һ�䣬����ͨѶ¼ѧ�Ķ�̬�ڴ� �����ٿռ�
#define N 200
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;	//ָ��̬����ָ��
	int size;		//���ݸ���
	int capacity;	//����-�ռ��С
}SL;
//��ɾ��ģ�
void SInit(SL* ps);//��ʼ��
void Destory(SL* ps);//����

//ͷ�� ͷɾ β�� βɾ  --�������� TSL������C++���ص�ѧ���úø�����ʦ���������

//ʱ�临�Ӷ�O(1)β�� βɾ ����ʹ�ã�
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

//ʱ�临�Ӷ�O(N)ͷ�� ͷɾ
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);
void SLPrint(SL* ps);
void SLPCheckCapacity(SL* ps);
//����λ����Ӻ�ɾ��
void SLInsert(SL* ps, int pos, SLDataType x);//��ĳ��λ�ò�������
void SLErase(SL* ps, int pos);//ɾ������λ������
//���Һ��޸�
int SLFind(SL* ps, SLDataType x);
void SLModify(SL* ps, int pos, SLDataType x);