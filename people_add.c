#include "people_head.h"

/*��������*/
PEO *Creat(int n)
 {
	PEO *head;
	PEO *p1, *p2;
	int i;
	//system("cls");
	for(i=1;i<n+1;i++) 
	{
		p1 = (PEO*)malloc(LEN);
	
		printf("--------------------------------------\n");
		printf("\t\t��\n");      
		printf("��������ϵ��������");scanf("%s",p1->name);
        printf("��������ϵ�˵绰���룺");scanf("%s",p1->tel);
        printf("��������ϵ�˵�ַ��ʡ����");scanf("%s",p1->addr.sheng);
        printf("��������ϵ�˵�ַ���У���");scanf("%s",p1->addr.shi);
        printf("��������ϵ���ʱࣺ");scanf("%s",p1->zip);
        printf("��������ϵ��email��");scanf("%s",p1->ema);
		
		p1->next = NULL;
		
		if(i==1) 
		{
			head = p2 = p1;
		}
		else 
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}

/*����д�����ݵ�����*/
int Creat_num(void) 
{
	printf("\n�����������˴�Ҫ��ӵ����ݸ���:");
	int n;
	if(scanf("%d", &n)!=1) 
	{
		printf("\a error!");
	}
	return n;
}

/*0.���ݴ���(w���á�ֻд)*/
void WriteData_w(PEO *head) 
{
	FILE *fp;
	PEO *p;
	if((fp = fopen(filename, "wb"))==NULL)
	printf("\a error! Can not open the file!");
	p = head;
	while(p!=NULL) 
	{
		if(fwrite(p,LEN,1,fp)!=1)
		{
			printf("д�����ݳ���\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

/*1.���ݴ���(a׷��)*/
void WriteData_a(PEO *head) 
{
	FILE *fp;
	PEO *p;
	if((fp = fopen(filename, "ab"))==NULL)
	printf("\a error! Can not open the file!");
	p = head;
	while(p!=NULL) 
	{
		if(fwrite(p,LEN,1,fp)!=1) 
		{
			printf("д�����ݳ���\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

