#include  "people_head.h"
#include  "people_add.c"
#include  "people_find.c"
#include  "people_del.c"
#include  "people_change.c"


/*主函数*/
int main(void)
{
	File_name();
	menu();
	return 0;
}

/*主菜单*/
void menu(void) 
{
	
	ReadData(); 
	int a = 0;
	
    printf("\n  ******************************************************************");
    printf("\n\t\t\t  通讯录");
    printf("\n  ******************************************************************");
    printf("\n\t\t\t  请选择:");
    printf("\n\t\t0.清空目前通讯录并新建联系人");
    printf("\n\t1.新增联系人");		printf("\t\t\t5.查找联系人（按姓名）");
    printf("\n\t2.查看所有联系人");    printf("\t\t6.查找联系人（按电话）");
	printf("\n\t3.删除联系人");		printf("\t\t\t7.按名字排序");
    printf("\n\t4.修改联系人信息");    	printf("\t\t8.退出");
    printf("\n  ******************************************************************");
	printf("\n◎请输入选项编号（0~8）：");
	scanf("%d",&a);
	printf("\n");
	switch(a) 
	{
		case 0:	//清空目前通讯录并新建联系人 
			WriteData_w(Creat(Creat_num()));
			printf("\n◎新建文件成功且数据已成功保存◎\n");
			system("pause");
			system("cls");
			menu();
			break;
		case 1: //新增联系人
			WriteData_a(Creat(Creat_num()));
			printf("\n◎联系人已成功添加◎\n");
			system("pause");
			system("cls");
			menu();
			break;
		case 2: //查看所有联系人
			Print_inquire_all();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 3: //删除联系人
			Delete();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 4: //修改联系人信息
			Amend();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 5: //查找联系人（按姓名）
			Print_inquire_name();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 6: //查找联系人（按电话）
			Print_inquire_tel();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 7: //按名字排序
			Neaten();
			system("pause");
			system("cls");
			menu(); 
			break;
		case 8: //退出
			exit(0); 
			break;
		default:
		{
			printf("error!\n\n");
			getchar();
			printf("◎请重新输入编号！\n\n");
			system("pause");
			system("cls");
			menu(); 
		}
	}
	getchar();
}

/*选择将要打开的文件*/
int File_name()
{
	printf("\n◎温馨提示：默认使用文件名：e:/201924111326杨晓璇_简单通讯录/list.txt\n");
	printf("\n◎请输入您想要使用的文件名：");
	if(scanf("%s", filename)!=1)
	{
		printf("\a error!!\n");
	}
	system("cls");
	return 0;
}

/*读取数据*/
/*读取数据文件保存到链表中 ，返回指向此链表头指针*/
PEO *ReadData(void)
{
	PEO *head = NULL;
	PEO *p1, *p2;
	
	int flag; 

	FILE *fp;
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("找不到文件 %s\n",filename);
		printf("\n\n");
		printf("重新输入文件名\n\n");
		system("pause");
		File_name();
		ReadData();
	}
	while(!feof(fp))
	 {
		if((p1=(PEO*)malloc(LEN))==NULL)
		{
			printf("内存申请出错\n");
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

