#include "people_head.h"

/*3.ɾ����ϵ��*/
int Delete() 
{
	PEO *pt1, *pt2, *head;
	char str_name[20];
	printf("\n����������Ҫɾ������ϵ�˵�����:");
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
			printf("\t\t��\n");  
			printf("����ϵ�˵���Ϣ����:\n");          
            printf("������%s\n",pt1->name);
            printf("�绰��%s\n",pt1->tel);
			printf("��ַ��ʡ����%s\n",pt1->addr.sheng);
            printf("��ַ���У���%s\n",pt1->addr.shi);
            printf("�ʱࣺ%s\n",pt1->zip);
            printf("email��%s\n",pt1->ema);
			printf("--------------------------------------\n");
			printf("���Ƿ�ɾ������ϵ�ˣ�\n(������ �ǣ�1/��2):");
			scanf("%d",&a);
			if(a==1)
			{
				WriteData_w(pt2);
				printf("\n\n���ѳɹ�ɾ������ϵ�ˡ�\n");
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
			printf("\t\t��\n");  
			printf("����ϵ�˵���Ϣ����:\n");          
            printf("������%s\n",pt2->name);
            printf("�绰��%s\n",pt2->tel);
			printf("��ַ��ʡ����%s\n",pt2->addr.sheng);
            printf("��ַ���У���%s\n",pt2->addr.shi);
            printf("�ʱࣺ%s\n",pt2->zip);
            printf("email��%s\n",pt2->ema);
			printf("\n\n");
			printf("--------------------------------------\n");
			printf("���Ƿ�ɾ������ϵ�ˣ�\n(������ �ǣ�1/��2):");
			scanf("%d",&a);
			if(a==1)
			{ 
				pt1->next = pt2->next;
				WriteData_w(head);
				printf("\n\n���ѳɹ�ɾ������ϵ�ˡ�\n");
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
	
	printf("��ͨѶ¼��û�д洢��Ҫɾ������ϵ�ˣ�\n");
	printf("\n\n");
	return 0;
}

