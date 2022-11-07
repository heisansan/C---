#include "people_head.h"

/*2.所有联系人*/
void Print_inquire_all(void) 
{
	
	PEO *pt;
	pt = ReadData(); 
	
	printf("------------------------------------------------------------------------------\n");
   	printf(" 姓名\t    电话\t 所在省    所在市     邮编\t  Email\n");
	printf("-------------------------------------------------------------------------------\n");
	if(pt==NULL)
	{
		printf("\n◎数据库中没有存储联系人！\n\n");
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

/*5.按姓名查询*/
int Print_inquire_name() 
{
	PEO *pt;
	char str_name[20];
	printf("◎请输入您要查找的姓名:");
	scanf("%s", str_name);
	pt = ReadData();
	do 
	{
		if(strcmp(pt->name,str_name)==0)
		{
			printf("--------------------------------------\n");
			printf("\t\t◎\n");  
			printf("该联系人的信息如下:\n");                  
            printf("姓名：%s\n",pt->name);
            printf("电话：%s\n",pt->tel);
			printf("地址（省）：%s\n",pt->addr.sheng);
            printf("地址（市）：%s\n",pt->addr.shi);
            printf("邮编：%s\n",pt->zip);
            printf("email：%s\n",pt->ema);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	}while(pt!=NULL); 
	printf("◎数据库中没有存储您要查找的联系人！\n");
	printf("\n\n");
	return 0;
}

/*6.按电话号码查询*/
int Print_inquire_tel() 
{
	PEO *pt;
	char str_tel[20];
	printf("◎请输入您要查找的电话号码:");
	scanf("%s", str_tel);
	pt = ReadData();
	do 
	{
		if(strcmp(pt->tel,str_tel)==0) 
		{
			printf("--------------------------------------\n");
			printf("\t\t◎\n");  
			printf("该联系人的信息如下:\n");           
            printf("姓名：%s\n",pt->name);
            printf("电话：%s\n",pt->tel);
			printf("地址（省）：%s\n",pt->addr.sheng);
            printf("地址（市）：%s\n",pt->addr.shi);
            printf("邮编：%s\n",pt->zip);
            printf("email：%s\n",pt->ema);
			printf("\n\n");
			return 0;
		}
		pt = pt->next;
	}while(pt!=NULL);
	printf("◎通讯录中没有存储您要查找的联系人！\n");
	printf("\n\n");
	return 0;
}

