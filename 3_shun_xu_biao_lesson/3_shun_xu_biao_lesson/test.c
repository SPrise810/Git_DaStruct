//�������ݣ� ��ɾ���
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
	//���Կ����鷳������д��print
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
void TestSeqList2()//����βɾ
//����������Ҫ�˽�ɾ���Ĺ����п��ܳ��ֶ�ɾ�����������Խ��
//Ȼ��Խ���ǲ�һ������ģ���Ϊϵͳ��Խ��ļ���� ��ڳ��
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
	printf("��������Ҫɾ�������ݣ�");
	scanf("%d", &x);
	int ret=SLFind(&sl, x);
	while(ret!=-1)
	{
		SLErase(&sl, ret);
		ret = SLFind(&sl, x);
		printf("��ɾ��%d \n",x);
		SLPrint(&sl);
		if (ret == -1)
		{
			printf("δ�ҵ������ݣ�");
		}
	}
}

void menu()
{
	printf("*********************\n");
	printf("*****1.β��2.ͷ��*****\n");
	printf("*****3.����4.ɾ��*****\n");
	printf("*****5.�޸�6.��ӡ*****\n");
	printf("********-1.�˳�*******\n");

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
			printf("scanf�������");
			//˳�����һ�»�����
			continue;
		}
		int val=0, pos=0;
		switch (option)
		{
		case 1:
			//printf("��������Ҫ��������ݣ�>");
			printf("������������Ҫ��������ݣ���-2������>");
			scanf("%d", &val); 
			/*�������������ط�������ĸ�Ļ������ǵ�scanf������ȥ������Ѱ��%d��ʽ��ֵ������
			��Ϊ�Ҳ����൱��û�ж���ֵ �ᷢ���������շ���EOF*/
			while (val != -2)//����������ȱ����ǲ����ٲ���0
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
			printf("����������������룺>");
			break;
		}
	} while (option!=-1);

	return 0;
}
//˳�����������߼������һ��ô���ʵ��˳���

//������ǽ���������Ŀ��ͬʱҲ�����ǵ���ҵ��  һ��һ��һ��һ��Ҫ��ͼ����