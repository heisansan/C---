#include "people_head.h"


/*4.�޸���ϵ����Ϣ*/
int Amend() 
{
	void menu_print_in(void);
	PEO *pt1, *pt2, *head;
	char str_name[20];
	
	printf("����������Ҫ�޸ĵ���ϵ�˵�����:");
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
            printf("\t\t��\n");  
			printf("����ϵ�˵���Ϣ����:\n"); 
            printf("������%s\n",pt1->name);
            printf("�绰��%s\n",pt1->tel);
			printf("��ַ��ʡ����%s\n",pt1->addr.sheng);
            printf("��ַ���У���%s\n",pt1->addr.shi);
            printf("�ʱࣺ%s\n",pt1->zip);
            printf("email��%s\n",pt1->ema);
            printf("--------------------------------------\n");
            printf("     ��ѡ��Ҫ�޸ĵ�����\n");
            printf("1.����       2.�绰       3.�ʱ�:\n");
            printf("4.��ַ��ʡ�� 5.��ַ���У� 6.email:\n");
            printf("--------------------------------------\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("\n�������µ�����:");
                    scanf("%s",pt1->name);
                    break;
                case 2:
                    printf("\n�������µĵ绰:");
                    scanf("%s",pt1->tel);
                    break;
                case 3:
                    printf("\n�������µ��ʱ�:");
                    scanf("%s",pt1->zip);
                    break;
                case 4:
                    printf("\n�������µĵ�ַ��ʡ��:");
                    scanf("%s",pt1->addr.sheng);
                    break;
                case 5:
                    printf("\n�������µĵ�ַ���У�:");
                    scanf("%s",pt1->addr.shi);
                    break;
                case 6:
                    printf("\n�������µ�email:");
                    scanf("%s",pt1->ema);
                    break;
            }
			printf("\n\n���ѳɹ��޸ĸ���ϵ����Ϣ��\n");
			WriteData_w(head);
		}
		else if(strcmp(pt2->name,str_name)==0)
		 {
			printf("--------------------------------------\n");
			printf("\t\t��\n");  
            printf("����ϵ�˵���Ϣ����:\n");
            printf("������%s\n",pt2->name);
            printf("�绰��%s\n",pt2->tel);
			printf("��ַ��ʡ����%s\n",pt2->addr.sheng);
            printf("��ַ���У���%s\n",pt2->addr.shi);
            printf("�ʱࣺ%s\n",pt2->zip);
            printf("email��%s\n",pt2->ema);
            printf("--------------------------------------\n");
            printf("     ��ѡ��Ҫ�޸ĵ�����\n");
            printf("1.����       2.�绰       3.�ʱ�:\n");
            printf("4.��ַ��ʡ�� 5.��ַ���У� 6.email:\n");
            printf("--------------------------------------\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("\n�������µ�����:");
                    scanf("%s",pt2->name);
                    break;
                case 2:
                    printf("\n�������µĵ绰:");
                    scanf("%s",pt2->tel);
                    break;
                case 3:
                    printf("\n�������µ��ʱ�:");
                    scanf("%s",pt2->zip);
                    break;
                case 4:
                    printf("\n�������µĵ�ַ��ʡ��:");
                    scanf("%s",pt2->addr.sheng);
                    break;
                case 5:
                    printf("\n�������µĵ�ַ���У�:");
                    scanf("%s",pt2->addr.shi);
                    break;
                case 6:
                    printf("\n�������µ�email:");
                    scanf("%s",pt2->ema);
                    break;
            }
			printf("\n\n���ѳɹ��޸ĸ���ϵ����Ϣ��\n");
			WriteData_w(head);
		}
		pt2 = pt2->next;
		pt1 = pt1->next;
	}
	if(pt2!=NULL)
	printf("ͨѶ¼��û�д洢��Ҫ�޸ĵ���ϵ�ˣ�\n");
	return 0;
}

/*7.����������*/
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
	printf("\n\n�������ѳɹ����������������С�\n");
	printf("����Իص����˵��鿴������ͨѶ¼��\n\n");
	WriteData_w(head);
	return 0;
}

