#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#include"tooler.h"
int student(int i,int len)
{
	system("clear");
	printf("***********************************\n");
	printf("*    欢迎%s同学登录学生管理系统   *\n",stu[i].name);
	printf("*  1.信息查询  2.信息修改  3.退出 *\n");
	printf("***********************************\n");
	printf("\n请选择:");
	int select ;
	scanf("%d",&select);
	switch(select)
	{
		case 1:
				refer(i,len);
				getchar();
				printf("输入回车返回主菜单\n");
				while('\n'==getchar())
				{
					student(i,len);
				}
				break;
		case 2:
				modify(i,len);
				getchar();
				printf("输入回车返回主菜单\n");
				while('\n'==getchar())
				{
					student(i,len);
				}
				break;
		case 3:
				quit(i,len);
				break;
		default:
				printf("\n输入格式错误，请重新输入:");
				scanf("%d",&select);
				break;
	}
	return 0;
}
void refer(int i,int len)   //学生信息查询函数
{
	printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
}
void modify(int i,int len)   //学生信息修改函数
{
	char ch[128];
  	printf("是否修改信息？(y/n)\n");
    scanf("%s",ch);
	if(!strcmp("y",ch))     //判断是否修改
	{
		printf("请输入新密码:");
	 	scanf("%s",stu[i].passwd);
		printf("请输入年龄:");
		scanf("%d",&stu[i].age);
		printf("是否保存修改后的信息？(y/n)\n");
		scanf("%s",ch);
		if(strcmp("y",ch)==0)    //判断是否保存                               
		{
			stuwfile(len);      //保存信息
			len=sturfile();
			printf("信息保存成功!!!\n");
		}
	}
	else
		len=sturfile();
}
void quit()                     //退出函数
{
	char ch[128];
	printf("是否退出学生管理系统?(y/n)\n");
	scanf("%s",ch);
	if(!strcmp("y",ch))
		exit(0);
	else
		menu();
}
