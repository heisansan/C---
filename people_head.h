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
