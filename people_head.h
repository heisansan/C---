/*
��༶��19�Ƽ�3�� 
������������� 
��ѧ�ţ�201924111326
���л�������ʦ��odaynot��Mr.YUAN��clusterally 
*/

#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

# define LEN sizeof(struct people)//�궨��LENΪ�ṹ ��ϵ�˵Ĵ�С����������д�ļ�
typedef struct people PEO;//�Զ�������-�ṹ�������ļ��д��
char filename[30];//ȫ�ֱ�������������Ҫ�򿪵��ļ�����

int main(void);/*������*/
void menu(void);/*�˵�*/ 
int File_name();/*ѡ��Ҫ�򿪵��ļ�*/
PEO *ReadData(void);/*��ȡ����*//*��ȡ�����ļ����浽������ ������ָ�������ͷָ��*/

PEO *Creat(int n);/*��������*/
int Creat_num(void); /*����д�����ݵ�����*/
void WriteData_w(PEO *head);/*0.���ݴ���(w���á�ֻд)*/
void WriteData_a(PEO *head);/*1.���ݴ���(a׷��)*/

void Print_inquire_all(void);/*2.������ϵ��*/
int Print_inquire_name();/*5.��������ѯ*/
int Print_inquire_tel();/*6.���绰�����ѯ*/

int Delete();/*3.ɾ����ϵ��*/

int Amend();/*4.�޸���ϵ����Ϣ*/
int Neaten();/*7.����������*/

//�����ṹ 
struct address//�ṹ ��ַ
{
	char sheng[20];//ʡ��
	char shi[20];  //��
};
struct people//�ṹ ��ϵ��
{
	char name[20];//����
	char tel[20];//�绰����
	struct address addr;//��ַ
	char zip[20]; //�ʱ�
	char ema[30]; //email
	struct people *next; //���� 
};

#endif
