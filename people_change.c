#include "people_head.h"


/*4.修改联系人信息*/
int Amend() 
{
	void menu_print_in(void);
	PEO *pt1, *pt2, *head;
	char str_name[20];
	
	printf("◎请输入您要修改的联系人的姓名:");
	scanf("%s", str_name);
	pt1 = ReadData();
	pt2 = pt1->next;
	head = pt1;
    
	int choice;
	
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
            printf("     请选择要修改的内容\n");
            printf("1.姓名       2.电话       3.邮编:\n");
            printf("4.地址（省） 5.地址（市） 6.email:\n");
            printf("--------------------------------------\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("\n请输入新的名字:");
                    scanf("%s",pt1->name);
                    break;
                case 2:
                    printf("\n请输入新的电话:");
                    scanf("%s",pt1->tel);
                    break;
                case 3:
                    printf("\n请输入新的邮编:");
                    scanf("%s",pt1->zip);
                    break;
                case 4:
                    printf("\n请输入新的地址（省）:");
                    scanf("%s",pt1->addr.sheng);
                    break;
                case 5:
                    printf("\n请输入新的地址（市）:");
                    scanf("%s",pt1->addr.shi);
                    break;
                case 6:
                    printf("\n请输入新的email:");
                    scanf("%s",pt1->ema);
                    break;
            }
			printf("\n\n◎已成功修改该联系人信息◎\n");
			WriteData_w(head);
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
            printf("--------------------------------------\n");
            printf("     请选择要修改的内容\n");
            printf("1.姓名       2.电话       3.邮编:\n");
            printf("4.地址（省） 5.地址（市） 6.email:\n");
            printf("--------------------------------------\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("\n请输入新的名字:");
                    scanf("%s",pt2->name);
                    break;
                case 2:
                    printf("\n请输入新的电话:");
                    scanf("%s",pt2->tel);
                    break;
                case 3:
                    printf("\n请输入新的邮编:");
                    scanf("%s",pt2->zip);
                    break;
                case 4:
                    printf("\n请输入新的地址（省）:");
                    scanf("%s",pt2->addr.sheng);
                    break;
                case 5:
                    printf("\n请输入新的地址（市）:");
                    scanf("%s",pt2->addr.shi);
                    break;
                case 6:
                    printf("\n请输入新的email:");
                    scanf("%s",pt2->ema);
                    break;
            }
			printf("\n\n◎已成功修改该联系人信息◎\n");
			WriteData_w(head);
		}
		pt2 = pt2->next;
		pt1 = pt1->next;
	}
	if(pt2!=NULL)
	printf("通讯录中没有存储您要修改的联系人！\n");
	return 0;
}

/*7.按姓名排列*/
int Neaten() 
{
	PEO *first;
	PEO *tail;
	PEO *p_min;
	PEO *min;
	PEO *p;
	PEO *head;
	
	head = ReadData();
	first = NULL;
	
	while(head!=NULL) 
	{
		for(p=head,min=head; p->next!=NULL; p=p->next) 
		{
			if(strcmp(p->next->name,min->name)<0) 
			{
				p_min = p;
				min = p->next;
			}
		}
		if(first==NULL) 
		{
			first = min;
			tail = min;
		}
		else 
		{
			tail->next = min;
			tail = min;
		}
		if(min==head) 
		{
			head = head->next;
		}
		else 
		{
			p_min->next = min->next;
		}
	}
	if(first!=NULL) 
	{
		tail->next = NULL;
	}
	head = first;
	printf("\n\n◎数据已成功按照姓名重新排列◎\n");
	printf("◎可以回到主菜单查看排序后的通讯录◎\n\n");
	WriteData_w(head);
	return 0;
}

