#include "people_head.h"

/*2.������ϵ��*/
void Print_inquire_all(void) 
{
	
	PEO *pt;
	pt = ReadData(); 
	
	printf("------------------------------------------------------------------------------\n");
   	printf(" ����\t    �绰\t ����ʡ    ������     �ʱ�\t  Email\n");
	printf("-------------------------------------------------------------------------------\n");
	if(pt==NULL)
	{
		printf("\n�����ݿ���û�д洢��ϵ�ˣ�\n\n");
		system("pause");
		system("cls");
		menu();
	}
	do 
	{

		printf(" %-10s",pt->name);
		printf("%-15s",pt->tel);
		printf("%-10s",pt->addr.sheng);
		printf("%-10s",pt->addr.shi);
        printf("%-10s",pt->zip);
    	printf("%-20s\n",pt->ema);
		pt = pt->next;
	}while(pt!=NULL);
	printf("\n\n");
}

/*5.��������ѯ*/
int Print_inquire_name() 
{
	PEO *pt;
	char str_name[20];
	printf("����������Ҫ���ҵ�����:");
	scanf("%s", str_name);
	pt = ReadData();
	do 
	{
		if(strcmp(pt->name,str_name)==0)
		{
			printf("--------------------------------------\n");
			printf("\t\t��\n");  
			printf("����ϵ�˵���Ϣ����:\n");                  
            printf("������%s\n",pt->name);
            printf("�绰��%s\n",pt->tel);
			printf("��ַ��ʡ����%s\n",pt->addr.sheng);
            printf("��ַ���У���%s\n",pt->addr.shi);
            printf("�ʱࣺ%s\n",pt->zip);
            printf("email��%s\n",pt->ema);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	}while(pt!=NULL); 
	printf("�����ݿ���û�д洢��Ҫ���ҵ���ϵ�ˣ�\n");
	printf("\n\n");
	return 0;
}

/*6.���绰�����ѯ*/
int Print_inquire_tel() 
{
	PEO *pt;
	char str_tel[20];
	printf("����������Ҫ���ҵĵ绰����:");
	scanf("%s", str_tel);
	pt = ReadData();
	do 
	{
		if(strcmp(pt->tel,str_tel)==0) 
		{
			printf("--------------------------------------\n");
			printf("\t\t��\n");  
			printf("����ϵ�˵���Ϣ����:\n");           
            printf("������%s\n",pt->name);
            printf("�绰��%s\n",pt->tel);
			printf("��ַ��ʡ����%s\n",pt->addr.sheng);
            printf("��ַ���У���%s\n",pt->addr.shi);
            printf("�ʱࣺ%s\n",pt->zip);
            printf("email��%s\n",pt->ema);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	}while(pt!=NULL);
	printf("��ͨѶ¼��û�д洢��Ҫ���ҵ���ϵ�ˣ�\n");
	printf("\n\n");
	return 0;
}

