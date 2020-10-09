#include <stdio.h>                                                          
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "student.h"
#include "teacher.h"
#include "tooler.h"
int menu()
{
  system("clear");
  int count;
  for(count=1;count<4;count++)
  {
	int id,flag=1;   //定义flag来判断输入是否正确
	char *passwd;
	char name[128];
	char toolername[128]="admin";
	char *toolerpasswd="123456";

	int len=sturfile();   //调用学生读文件
	int tlen=trfile();    //调用老师的读文件

	printf("****************************************************\n");
	printf("*               欢迎使用学生管理系统               *\n");
	printf("*         1.学生登录        2.教师登陆             *\n");
	printf("*         3.管理员登录      4.退出系统             *\n");
	printf("****************************************************\n");
	printf("\n请选择:");
	int select;
	scanf("%d",&select);
	switch(select)
	{
	  case 1:
			printf("请输入学号和密码\n");
			printf("学号：");
			scanf("%d",&id);
			passwd = getpass("密码：");
			for(int i=0;i<len;i++)     //学生登录识别
			{
		  		if(id==stu[i].id && strcmp(passwd,stu[i].passwd)==0)
		  		{
					student(i,len);
					flag=0;
					continue;
		  		}
			}
			break;
	  case 2:
			printf("请输入工号和密码\n");
			printf("工号：");
			scanf("%d",&id);
			passwd = getpass("密码：");
			for(int i=0;i<tlen;i++)    //老师登录识别
			{
		  		if(id==t[i].id && strcmp(passwd,t[i].passwd)==0)
		  		{
					teacher(i,len);
					flag=0;
					continue;
		  		}
			}
			break;
	  case 3:
			printf("请输入用户名和密码\n");
			printf("用户名：");
			scanf("%s",name);
			passwd = getpass("密码：");
			if(strcmp(toolername,name)==0 && strcmp(passwd,toolerpasswd)==0)//管理员登录识别
			{
		  		tooler(tlen,len);
		  		flag=0;
		  		continue;
			}
			break;
	  case 4:
			quit();
			break;
	  default:
			printf("输入格式错误，按回车键重新输入\n");
			menu();
	}
	if(flag == 1 && count<3)
	{
	  printf("\n用户名或密码输入错误，请重新输入！！！\n\n");
	}
  }
  printf("\n用户名或密码输入错误三次，退出系统！！！\n\n");
  return 0;
}
