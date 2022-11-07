#include "people_head.h"

/*3.删除联系人*/
int Delete() 
{
	PEO *pt1, *pt2, *head;
	char str_name[20];
	printf("\n◎请输入您要删除的联系人的名字:");
	scanf("%s", str_name);
	pt1 = ReadData();
	pt2 = pt1->next;
	head = pt1;
	int a=0,flag=0;

	while(pt2!=NULL) 
	{
		if(strcmp(pt1->name,str_name)==0) 
		{
			printf("--------------------------------------\n");
			printf("\t\t◎\n");  
			printf("该联系人的信息如下:\n");          
            printf("姓名：%s\n",pt1->name);
            printf("电话：%s\n",pt1->tel);
			printf("地址（省）：%s\n",pt1->addr.sheng);
            printf("地址（市）：%s\n",pt1->addr.shi);
            printf("邮编：%s\n",pt1->zip);
            printf("email：%s\n",pt1->ema);
			printf("--------------------------------------\n");
			printf("◎是否删除该联系人？\n(请输入 是：1/否：2):");
			scanf("%d",&a);
			if(a==1)
			{
				WriteData_w(pt2);
				printf("\n\n◎已成功删除该联系人◎\n");
				system("pause");
				system("cls"); 
				menu();
			}
			else if(a==2) 
			{ 
				system("cls"); 
				menu();
			} 
		}
		else if(strcmp(pt2->name,str_name)==0) 
		{
			
			printf("--------------------------------------\n");
			printf("\t\t◎\n");  
			printf("该联系人的信息如下:\n");          
            printf("姓名：%s\n",pt2->name);
            printf("电话：%s\n",pt2->tel);
			printf("地址（省）：%s\n",pt2->addr.sheng);
            printf("地址（市）：%s\n",pt2->addr.shi);
            printf("邮编：%s\n",pt2->zip);
            printf("email：%s\n",pt2->ema);
			printf("\n\n");
			printf("--------------------------------------\n");
			printf("◎是否删除该联系人？\n(请输入 是：1/否：2):");
			scanf("%d",&a);
			if(a==1)
			{ 
				pt1->next = pt2->next;
				WriteData_w(head);
				printf("\n\n◎已成功删除该联系人◎\n");
				system("cls"); 
				menu();
			} 
			else if(a==2) 
			{ 
				system("cls"); 
				menu();
			}
		}
		pt2 = pt2->next;
		pt1 = pt1->next;
	}
	
	printf("◎通讯录中没有存储您要删除的联系人！\n");
	printf("\n\n");
	return 0;
}

