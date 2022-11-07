#include "people_head.h"

/*生成链表*/
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
		printf("\t\t◎\n");      
		printf("请输入联系人姓名：");scanf("%s",p1->name);
        printf("请输入联系人电话号码：");scanf("%s",p1->tel);
        printf("请输入联系人地址（省）：");scanf("%s",p1->addr.sheng);
        printf("请输入联系人地址（市）：");scanf("%s",p1->addr.shi);
        printf("请输入联系人邮编：");scanf("%s",p1->zip);
        printf("请输入联系人email：");scanf("%s",p1->ema);
		
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

/*输入写入数据的数量*/
int Creat_num(void) 
{
	printf("\n◎请输入您此次要添加的数据个数:");
	int n;
	if(scanf("%d", &n)!=1) 
	{
		printf("\a error!");
	}
	return n;
}

/*0.数据存盘(w重置、只写)*/
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
			printf("写入数据出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

/*1.数据存盘(a追加)*/
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
			printf("写入数据出错\n");
			fclose(fp);
			return;
		}
		p=p->next;
	}
	fclose(fp);
}

