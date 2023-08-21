#include"SeqList.h"
void TestSeqList1()
{
	SL sl;
	SLInit(&sl);//�βεĸı䲻��Ӱ��ʵ�Σ����������� 
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

	SLDestory(&sl);//Խ������ �ڴ����� Ұָ������ 
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
	SLDestory(&sl);//Խ������ �ڴ����� Ұָ������ 
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
	printf("��������Ҫɾ�������ݲ����룺\n");
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
	printf("******1.β��2.ͷ��********\n");
	printf("******5.����6.ɾ��********\n");
	printf("******7.�޸�8.��ӡ********\n");
	printf("*********-1.�˳�**********\n");
	printf("*************************\n");

}
int main()
{
	//���������ȥ���Դ���  ���öϵ� һ��������
	// 
	// ����Խ������һ���ᱨ��
	/*
	//ϵͳ��Խ��ļ�飬��һ�� ��ڳ�顣 �Ͳ�Ƽ�һ������һ������������
	int a[10];
	a[0]=0;
	//a[10]=0;��һ��
	a[11]=1;//��һ��
	//a[12]=1;//������һ��
	*/

	//��ָ�����⣺  0x00F415E1 ����δ��������쳣.....  д��λ��0x00000000ʱ�������ʳ�ͻ
    //��ָ������ �Ӷ�����һ�� ����ʽ���
	//����ʽ��� �� ���д��ݲ����ĺ�������  Ϊ�˷�ֹ����Ϊ�� ����assert���� 

	//�������ݾ������ڲ��Ժ������棬��Ϊ�������ݽṹ����Ļ�����������������ṹ
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
			//scanf��Ĳ���
			//����scanf����ͨ��%d�ó�����������Ҫ�ڻ�������ȡ������ʽ��ֵ
			//���������������һ����ĸ����ô�ͳ����ˣ��൱����û�еõ�ֵ��ͨ�������������֪�������Ƿ���������߶����ļ��������᷵��EOF
		{
			printf("scanf�������\n");
			//continue;//����Ҫ���������������ֱ��break
			break;//
		}
		int val, pos;
		int y, z;
		switch (option)
		{
		case 1:
			printf("��������Ҫβ������ȫ�����ݣ���0Ϊ����>");
			scanf("%d", &val);
			while (val != 0)
			{
				SLPushBack(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 2:				
			printf("��������Ҫͷ���������ݣ���0Ϊ����>");
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
			//printf("��������Ҫ�޸ĵ�ԭ���ݺ��޸ĺ������");
			//scanf("%d %d", &y,&z);
			//SLModify(&sl, &val, &y);

			printf("��������Ҫ�޸ĵ�ֵ���޸ĺ��ֵ:\n");
			scanf("%d%d", &y, &z);
			pos = SLFind(&sl, y);
			if (pos != -1)
			{
				SLModify(&sl, pos, z);
			}
			else
			{
				printf("û���ҵ�%d\n",y);
			}
			break;
		case 8:
			SLPrint(&sl);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (option != -1);

	SLDestory(&sl);

	return 0;
}


  