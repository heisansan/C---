#include  "people_head.h"
#include  "people_add.c"
#include  "people_find.c"
#include  "people_del.c"
#include  "people_change.c"


/*������*/
int main(void)
{
	File_name();
	menu();
	return 0;
}

/*���˵�*/
void menu(void) 
{
	
	ReadData(); 
	int a = 0;
	
    printf("\n  ******************************************************************");
    printf("\n\t\t\t  ͨѶ¼");
    printf("\n  ******************************************************************");
    printf("\n\t\t\t  ��ѡ��:");
    printf("\n\t\t0.���ĿǰͨѶ¼���½���ϵ��");
    printf("\n\t1.������ϵ��");		printf("\t\t\t5.������ϵ�ˣ���������");
    printf("\n\t2.�鿴������ϵ��");    printf("\t\t6.������ϵ�ˣ����绰��");
	printf("\n\t3.ɾ����ϵ��");		printf("\t\t\t7.����������");
    printf("\n\t4.�޸���ϵ����Ϣ");    	printf("\t\t8.�˳�");
    printf("\n  ******************************************************************");
	printf("\n��������ѡ���ţ�0~8����");
	scanf("%d",&a);
	printf("\n");
	switch(a) 
	{
		case 0:	//���ĿǰͨѶ¼���½���ϵ�� 
			WriteData_w(Creat(Creat_num()));
			printf("\n���½��ļ��ɹ��������ѳɹ������\n");
			system("pause");
			system("cls");
			menu();
			break;
		case 1: //������ϵ��
			WriteData_a(Creat(Creat_num()));
			printf("\n����ϵ���ѳɹ���ӡ�\n");
			system("pause");
			system("cls");
			menu();
			break;
		case 2: //�鿴������ϵ��
			Print_inquire_all();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 3: //ɾ����ϵ��
			Delete();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 4: //�޸���ϵ����Ϣ
			Amend();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 5: //������ϵ�ˣ���������
			Print_inquire_name();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 6: //������ϵ�ˣ����绰��
			Print_inquire_tel();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 7: //����������
			Neaten();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 8: //�˳�
			exit(0); 
			break;
		default:
		{
			printf("error!\n\n");
			getchar();
			printf("�������������ţ�\n\n");
			system("pause");
			system("cls");
			menu(); 
		}
	}
	getchar();
}

/*ѡ��Ҫ�򿪵��ļ�*/
int File_name()
{
	printf("\n����ܰ��ʾ��Ĭ��ʹ���ļ�����e:/201924111326�����_��ͨѶ¼/list.txt\n");
	printf("\n������������Ҫʹ�õ��ļ�����");
	if(scanf("%s", filename)!=1)
	{
		printf("\a error!!\n");
	}
	system("cls");
	return 0;
}

/*��ȡ����*/
/*��ȡ�����ļ����浽������ ������ָ�������ͷָ��*/
PEO *ReadData(void)
{
	PEO *head = NULL;
	PEO *p1, *p2;
	
	int flag; 

	FILE *fp;
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("�Ҳ����ļ� %s\n",filename);
		printf("\n\n");
		printf("���������ļ���\n\n");
		system("pause");
		File_name();
		ReadData();
	}
	while(!feof(fp))
	 {
		if((p1=(PEO*)malloc(LEN))==NULL)
		{
			printf("�ڴ��������\n");
			fclose(fp);
			exit(0);
		}
		if(fread(p1,LEN,1,fp)!=1)
		{
			free(p1);
			break;
		}
		if(head==NULL)
			head=p2=p1;
		else
		{
			p2->next=p1;
			p2=p1;
		}
	}
	fclose(fp);
	return (head);
}

