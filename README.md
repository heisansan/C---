# C---
大一的时候用C语言写的简单通信录。存档用。

完成时间：2020年7月3日

 
目  录
第1部分  实训题目与要求	1
1．问题提出	1
2. 功能要求	1
3. 任务分工	1
第2部分  设计实训题目功能	1
1. 总体设计	1
2. 算法设计	2
3. 数据结构	4
4. 程序代码设计	5
5. 测试与调试	14
第3部分  实训总结	15
1. 个人总结	15
2. 结束语	15
附录A  程序清单	15
附录B  用户使用说明书	34
参考文献	35
《C程序设计综合实践》评分表	37



第1部分  实训题目与要求
1．问题提出
编写一个简单的通讯录管理程序。
2. 功能要求
实现通讯录的显示、增、删、改、查功能。
通讯录要保存在文件中，每次启动程序都从文件中读取当前的所有记录，每次退出程序时都更新通讯录。
通讯录中至少含有以下字段：姓名、电话号码、地址（嵌套结构）、邮政编码、email。
3. 任务分工
由我个人独自完成程序所有功能。

第2部分  设计实训题目功能
1. 总体设计
（1）模块设计：
头文件：定义数据结构、全局变量、简便写法、声明函数；
主函数文件：主函数、打印菜单；
增加联系人：新建文件/通讯录、新增联系人；
删除联系人：删除指定联系人；
查询联系人：查询所有联系人、按名字查询指定联系人、按电话查询指定联系人；
修改联系人：修改指定联系人；

（2）各函数的主要功能：
1)	int main(void);/*主函数*/
2)	void menu(void);/*菜单*/ 
3)	int File_name();/*选择将要打开的文件*/
4)	struct people *Creat(int n);/*生成链表*/
5)	int Creat_num(void); /*输入写入数据的数量*/
6)	struct people *ReadData(void);/*读取数据*/
7)	void WriteData_w(struct people *head);/*0.数据存盘(w重置、只写)*/
8)	void WriteData_a(struct people *head);/*1.数据存盘(a追加)*/
9)	void Print_inquire_all(void);/*2.所有联系人*/
10)	int Delete();/*3.删除联系人*/
11)	int Amend();/*4.修改联系人信息*/
12)	int Print_inquire_name();/*5.按姓名查询*/
13)	int Print_inquire_tel();/*6.按电话号码查询*/
14)	int Neaten();/*7.按姓名排列*/

（3）程序模块图

2. 算法设计
（1）头文件

（2）主函数文件

1)	int main(void); /*主函数*/
调用输入文件名的函数
调用主菜单函数
2)	void menu(void); /*菜单*/
打印提示选择的菜单；
使用switch语句连接各个功能函数；
3)	int File_name();/*选择将要打开的文件*/
从键盘输入文件名；
4)	struct people *ReadData(void); /*读取数据*/
接收文件名；
读取数据文件保存到链表中 ，返回指向此链表头指针；

（3）增加联系人程序文件

1)	struct people *Creat(int n); /*生成链表*/
生成/新增链表；
2)	int Creat_num(void); /*输入写入数据的数量*/
在键盘接受要写入数据的数量；
3)	void WriteData_w(struct people *head); /*数据存盘(w重置、只写)*/
接收文件名；
保存数据(重置数据)；
4)	void WriteData_a(struct people *head); /*数据存盘(a追加)*/
接收文件名；
保存数据(追加数据)；

（3）查询联系人程序文件

1)	void Print_inquire_all(void); /*打印所有联系人*/
读取数据；
打印所有联系人
2)	int Print_inquire_name();/*按姓名查询*/
读取数据；
按姓名查询特定联系人；
3)	int Print_inquire_tel();/*按电话号码查询*/
读取数据；
按电话号码查询特定联系人；

（4）删除联系人程序文件

1)	int Delete();/*删除联系人*/
读取数据；
按姓名查找特定联系人；
打印该联系人的信息；
用户确认是否该联系人；
删除该联系人；
保存数据；

（5）修改联系人程序文件

1)	int Amend();/*修改联系人信息*/
读取数据；
按姓名查找特定联系人；
打印该联系人的信息；
用户选择要修改哪项信息；
更改该联系人对应信息；
保存数据；
2)	int Neaten();/*按姓名排列*/
读取数据；
所有联系人按姓名排列（选择排序法）；
保存数据；

3. 数据结构
struct address  结构 地址
{
		char sheng[20];  省份
		char shi[20];  市
};
struct people  结构 联系人
{
	char name[20];  姓名
	char tel[20];  电话号码
	struct address addr;  地址
	char zip[20];   邮编
	char ema[30];   email
	struct people *next;   链表 
};

# define LEN sizeof(struct people)  宏定义LEN为结构 联系人的大小，方便后面读写文件
typedef struct people PEO;  自定义类型—结构类型名的简便写法
char filename[30];  全局变量，用来保存要打开的文件名字

4. 程序代码设计
（1）主函数文件
1)	int main(void);/*主函数*/
调用读取文件名函数：
	代码略
调用菜单函数：
代码略
2)	void menu(void);/*菜单*/ 
打印提示用户选择功能的菜单：
代码略
使用switch语句连接各个功能函数：
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
			printf("◎请重新输入编号:");
			scanf("%d",&a);
		}
	}
3)	int File_name();/*选择将要打开的文件*/
从键盘输入文件名：
		代码略
4)	struct people *ReadData(void); /*读取数据*/
接收文件名；
读取数据文件保存到链表中 ，返回指向此链表头指针
当文件打开失败时提示重新输入文件名：
if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("找不到文件 %s\n",filename);
		printf("\n\n");
		printf("重新输入文件名\n\n");
		system("pause");
		File_name();
		ReadData();
	}
（2）增加联系人程序文件
1)	int Creat_num(void); /*输入写入数据的数量*/
在键盘接受要写入数据的数量：
	代码略
2)	struct people *Creat(int n); /*生成链表*/
接收要写入数据的数量；
生成/新增链表，提示用户输入对应数据：
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
3)	void WriteData_w(struct people *head); /*数据存盘(w重置、只写)*/
接收文件名、对应链表位置；
将链表保存数据文件中(重置数据)：
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
4)	void WriteData_a(struct people *head); /*数据存盘(a追加)*/
接收文件名；
将链表保存到数据文件中(追加数据)：
	算法与上条函数类似，仅改变文件打开方式，代码略

（3）查询联系人程序文件
1)	void Print_inquire_all(void); /*打印所有联系人*/
读取数据；
按格式打印所有联系人：
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
2)	int Print_inquire_name();/*按姓名查询*/
读取数据；
用户输入想查询的联系人的名字；
	代码略
按姓名查询特定联系人并且打印出来：
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
	printf("◎通讯录中没有存储您要查找的联系人！\n");
3)	int Print_inquire_tel();/*按电话号码查询*/
读取数据；
用户输入想查询的联系人的电话号码；
	代码略
按电话号码查询特定联系人：
	算法与上条函数类似，仅改变检查条件，代码略

（4）删除联系人程序文件
1)	int Delete();/*删除联系人*/
读取数据；
按姓名查找特定联系人并打印该联系人的信息：
	算法与函数int Print_inquire_name()相同，代码略
用户确认是否该联系人；
删除该联系人并保存数据(重置数据)：
	pt1 = ReadData();
	pt2 = pt1->next;
	head = pt1;
		while(pt2!=NULL) 
		{
			if(strcmp(pt1->name,str_name)==0) 
			{
				WriteData_w(pt2);
				printf("\n\n◎已成功删除该联系人◎\n");
				system("pause");
				system("cls"); 
				menu(); 
			}
			else if(strcmp(pt2->name,str_name)==0) 
			{ 
				pt1->next = pt2->next;
				WriteData_w(head);
				printf("\n\n◎已成功删除该联系人◎\n");
				system("cls"); 
				menu();
			}
			pt2 = pt2->next;
			pt1 = pt1->next;
		}

（5）修改联系人程序文件
1)	int Amend();/*修改联系人信息*/
读取数据；
按姓名查找特定联系人并打印该联系人的信息：
	算法与函数int Print_inquire_name()相同，代码略
用户选择要修改哪项信息；
更改该联系人对应信息：
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
保存数据（重置数据）；
2)	int Neaten();/*按姓名排列*/
读取数据；
所有联系人按姓名排列（选择排序法）：
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
	printf("◎可以回到主菜单查看排序后的通讯录◎\n");
保存数据（重置数据）；

以上代码均有省略，完整程序请参见附录A。

5. 测试与调试
表1  测试用例
测试数据类型	测试数据	预期结果	实测结果
合法数据	新增加1个测试用的联系人
再选择查询该联系人	屏幕显示该联系人信息	屏幕显示该联系人信息
	新增加1个测试用的联系人
再删除该联系人
再选择查看所有联系人以及查询该联系人	屏幕显示
◎通讯录中没有存储您要查找的联系人！	屏幕显示
◎通讯录中没有存储您要查找的联系人！
	新增加2个测试用的联系人
再进行排序
选择查看所有联系人	屏幕显示成功排序后的联系人列表	屏幕显示成功排序后的联系人列表
非法数据	打开文件时
输入e	屏幕显示
找不到文件 e
重新输入文件名	屏幕显示
找不到文件 e
重新输入文件名
	在主菜单选择编号时
输入9	屏幕显示
error!
◎请重新输入编号！	屏幕显示
error!
◎请重新输入编号！
格式：表格的顶线、底线采用粗线1磅，栏目线、辅助线采用细线0.5磅。表头用黑体、五号、居中，表身内容汉字用宋体、五号，数字内容用Times New Roman字体、五号。

第3部分  实训总结
1. 个人总结
学习编程知识的时候，每个大知识点都是按课时一个接一个学习的，练习所用的编程题也大多是对一个一个知识点针对性地出题，所以对各知识点的综合运用并不那么熟练。通过这次实训，加深了我对每个知识点的理解，更加强了我对所有知识点的综合运用能力。
同时，实训的过程中，编写代码时出现了一些问题，比如说一开始的程序由于考虑不周，在输入非法数据时会直接退出程序或者储存乱码数据等等非预期的结果，后来就去补充了输入非法数据时重复调用函数的算法等等。虽说不出问题是最好的结果，但正因为出现了问题我才能意识到自己思维中的误区，才能找到更好的解决办法，才能提高自己的思维逻辑能力。
由于个人能力和时间的限制，本软件我认为还是有一些不足和还可以改进的地方。比方说查询联系人的算法和打印单个联系人的算法可以单独写成一个函数，就不会显得程序代码太累赘；通过以后的学习，我还想为本软件添加图片素材，甚至添加背景音乐和音效，使界面更加美观、使各种提示语句更明显，从而提高用户使用体验。
总而言之，这次实训给我带来许多收获。通过这次实训，我意识到了我存在的不足、加深了我对各知识点的理解、提高了对各知识点的综合运用能力，很好地锻炼了我的能力！
2. 结束语
最后，再此感谢我C语言的教师兼本次实训的指导老师的李革老师！教授给我们相关知识，解答我的问题，非常感谢！

附录A  程序清单
头文件people_head.h
/*
◎班级：19科技3班 
◎姓名：杨晓璇 
◎学号：201924111326
◎感谢：李革老师、odaynot、Mr.YUAN、clusterally 
*/

#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

# define LEN sizeof(struct people)//宏定义LEN为结构 联系人的大小，方便后面读写文件
typedef struct people PEO;//自定义类型-结构类型名的简便写法
char filename[30];//全局变量，用来保存要打开的文件名字

int main(void);/*主函数*/
void menu(void);/*菜单*/ 
int File_name();/*选择将要打开的文件*/
PEO *ReadData(void);/*读取数据*//*读取数据文件保存到链表中 ，返回指向此链表头指针*/

PEO *Creat(int n);/*生成链表*/
int Creat_num(void); /*输入写入数据的数量*/
void WriteData_w(PEO *head);/*0.数据存盘(w重置、只写)*/
void WriteData_a(PEO *head);/*1.数据存盘(a追加)*/

void Print_inquire_all(void);/*2.所有联系人*/
int Print_inquire_name();/*5.按姓名查询*/
int Print_inquire_tel();/*6.按电话号码查询*/

int Delete();/*3.删除联系人*/

int Amend();/*4.修改联系人信息*/
int Neaten();/*7.按姓名排列*/

//声明结构 
struct address//结构 地址
{
	char sheng[20];//省份
	char shi[20];  //市
};
struct people//结构 联系人
{
	char name[20];//姓名
	char tel[20];//电话号码
	struct address addr;//地址
	char zip[20]; //邮编
	char ema[30]; //email
	struct people *next; //链表 
};

#endif

主函数文件 people_main.c
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

增加联系人程序文件 people_add.c
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

查询联系人程序文件 people_find.c
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
	do {
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

删除联系人程序文件 people_del.c
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
	
	//if(pt2!=NULL)
	printf("◎通讯录中没有存储您要删除的联系人！\n");
	printf("\n\n");
	return 0;
}

修改联系人程序文件 people_change.c
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
 

附录B  用户使用说明书
内容：包括硬件和软件要求、使用方法、注意事项等内容。
（1）硬件要求
exe程序使用要求平台：PC.
（2）软件要求
本程序的代码使用Dev-C++编译，代码中其中存在Dev-C++的系统指令，如果使用其他编译器运行可能出现错误。
（3）注意事项
1)打开程序首先会出现该提示：
 
若使用默认数据文件，只需将前面的“e:/201924111326杨晓璇_简单通讯录”改为储存程序文件的文件路径。
若想新建一个数据文件，则需要自行新建一个空的的txt文件，然后再打开程序输入刚才新建的txt文件路径以及文件名。
2)打开文件成功后将看到主菜单：
 
请正确输入对应数字编号，若输入其他数字会回到主菜单，若输入其他字符则可能程序出错导致联系人清空！
也请务必在往后使用过程中出现的各种选项中正确输入选项对应数字！
 

参考文献
[1]	何钦铭, 颜晖, 等. C语言程序设计[M]. 3版. 北京：高等教育出版社, 2015: 253-319.
[2]	odaynot. C语言学生信息管理系统（动态链表版）[EB/OL].https://blog.csdn.net/odaynot/article/details/7942497?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-4.nonecase, 2012–09–04/2020–07–01.
[3]	clusterally. C语言通讯录（利用链表实现）[EB/OL].https://blog.csdn.net/clusterally/article/details/76670696?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80%20%E5%8D%95%E9%93%BE%E8%A1%A8%20%E9%80%9A%E8%AE%AF%E5%BD%95&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-76670696, 2017–08–04/2020–06–30.
[4]	Mr. xdc. 用c语言制作简易的个人通讯录管理系统[EB/OL].https://blog.csdn.net/qq_40632256/article/details/83928571, 2018–11–10/2020–06–30.
[5]	查心妍. C语言用链表实现通讯录并存入文件[EB/OL].https://blog.csdn.net/qq_41998576/article/details/81672751, 2018–08–14/2020–06–30.
