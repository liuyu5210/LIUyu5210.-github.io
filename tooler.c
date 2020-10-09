#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "tooler.h"
#include "teacher.h"
void tooler(int tlen,int len)
{	
  int select;
  while(1)
  {
	system("clear");
	printf("*******************************************************\n");
	printf("*              欢迎管理员登录学生管理系统             *\n");
	printf("*     1.教师信息录入       2.教师信息删除             *\n");
	printf("*     4.教师信息修改       4.教师信息查询             *\n");
	printf("*     5.学生信息录入       6.学生信息删除             *\n");
	printf("*     7.学生信息修改       8.学生信息查询             *\n");
	printf("*     9.学生信息显示       10.退出管理系统            *\n");
	printf("*******************************************************\n");
	printf("\n请选择:");
	scanf("%d",&select);
	switch(select)
	{
	  case 1:
			 tlen=tadd(tlen);
			 twfile(tlen);
		     getchar();
			 printf("输入回车返回主菜单\n");
			 getchar();
		     break;
	  case 2:
			 tlen=tdelete(tlen);
		  	 getchar();
			 printf("输入回车返回主菜单\n");
			 getchar();
			 break;
	  case 3:
			 atmodify(tlen);
			 getchar();
	       	 printf("输入回车返回主菜单\n");
			 getchar();
			 break;
	  case 4:
			 atrefer(tlen);
			 getchar();
			 printf("输入回车返回主菜单\n");
			 getchar();
			 break;
	  case 5:
			 len=stuadd(len);
			 stuwfile(len);
			 getchar();
			 printf("输入回车返回主菜单\n");
			 getchar();
			 break;
	  case 6:
			 len=studelete(len);
		     getchar();
		     printf("输入回车返回主菜单\n");
		     getchar();
		     break;
	  case 7:
			 stumodify(len);
			 getchar();
			 printf("输入回车返回主菜单\n");
			 getchar();
			 break;
	  case 8:
			  sturefer(len);
			  getchar();
			  printf("输入回车返回主菜单\n");
			  getchar();
			  break;
	  case 9:
			  sturank(len);
		      stushow(len);
		      getchar();
		      printf("输入回车返回主菜单\n");
			  getchar();
			  break;
	  case 10:
			  quit();
			  break;
	  default:
			  printf("\n输入格式有误，请重新输入:\n");
			  scanf("%d",&select);
			  break;
	}
  }
}
int tadd(int len)   //管理员对教师信息的添加函数
{
  int i,j;
  struct teacher temp;   //定义结构体变量
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(t[i].id>t[i+1].id)
	  {
		temp=t[i+1];        
		t[i+1]=t[i];
		t[i]=temp;             
	  }
	}
  }
  twfile(len);
  len=trfile();
  if(len==0)       //判断是否有老师
  {
	t[len].id=1001;
  }
  else 
  {
	t[len].id=t[len-1].id+1;
  }
  printf("请输入增加老师的姓名:");
  scanf("%s",t[len].name);
  printf("输入增加老师的密码:");
  scanf("%s",t[len].passwd);
  printf("请输入增加老师的班级:");
  scanf("%d",&t[len].teach);
  printf("信息录入成功！！！\n");
  len++;	   
  return len;
}
int tdelete(int len)    //对教师信息的删除函数
{
  while(1)
  {
	printf("请输入要删除的教师工号:");
	int id,i,j;
	char ch[128];
	scanf("%d",&id);
	if(len==0)
	{
	  printf("没有教师信息\n");
	  break;
	}
	else
	{
	  int flag=0;
	  for(i=0;i<len;i++)
	  {
		if(id==t[i].id)
		{
		  flag=1;
		  break;
		}
	  }
	  if(flag==0)
	  {
		getchar();
		printf("\n输入的工号错误,按回车键重新输入\n");
		getchar();
		continue;
	  }
	  else
	  {
		printf("\n找到要删除的信息\n");
		printf("工号：%d\n",t[i].id);
		printf("姓名：%s\n",t[i].name);
		printf("密码：%s\n",t[i].passwd);
		printf("班级：%d\n",t[i].teach);
		printf("是否删除？(y/n):");
		scanf("%s",ch);
		if(strcmp(ch,"y")==0)
		{
		  for(j=i;j<len;j++)
		  {
			t[j]=t[j+1];       //将删除的后面信息移到删除信息的位置
		  }
		  len--;
		  printf("信息删除成功！！！\n");
		}
	  }
	}
	printf("\n是否保存修改的信息(y/n):");
	scanf("%s",ch);
	if(strcmp(ch,"y")==0)
	{   
	  printf("信息保存成功！！！\n");
	  twfile(len);      //保存信息
	  len=trfile();     //读取信息
	}
	else
	  len=trfile();
	break;
  }
  return len;
}
void atmodify(int len)   //对教师信息的修改函数
{
  while(1)
  {
	int i,id;
	char ch[128];
	printf("请输入要修改的教师工号：");
	scanf("%d",&id);
	if(len == 0)
	{
	  printf("没有找到可修改的教师信息\n");
	  break;
	}
	else
	{
	  int flag=0;
	  for(i=0;i<len;i++)
	  {
		if(id==t[i].id)
		{
		  flag=1;
		  break;
		}
	  }
	  if(flag==0)
	  {
		getchar();
		printf("输入的工号错误,按回车键重新输入！！！\n");
		getchar();
		continue;
	  }
	  else
	  {
		printf("找到要修改的教师信息\n");
		printf("工号：%d\n",t[i].id);
		printf("姓名：%s\n",t[i].name);
		printf("密码：%s\n",t[i].passwd);
		printf("班级：%d\n",t[i].teach);
		printf("是否修改？(y/n):");
		scanf("%s",ch);
		if(strcmp(ch,"y")==0)
		{
		  printf("请输入修改的姓名:");
		  scanf("%s",t[i].name);
		  printf("请输入修改的密码:");
		  scanf("%s",t[i].passwd);
		  printf("请输入修改的班级:");
		  scanf("%d",&t[i].teach);
		}
		printf("信息修改成功！！！\n");
	  }
	}
	printf("是否保存修改后的信息?(y/n)\n");
	scanf("%s",ch);
	if(strcmp("y",ch)==0)
	{
	  twfile(len);
	  len=trfile();
	  printf("信息保存成功！！！");
	}
	else
	  len=trfile();
	  break;
  }
}	
void atrefer(int len)    //教师信息查询
{
  int select;
  printf("请输入要查询的方式:\n");
  printf("1.教师个人工号\n");
  printf("2.教师信息全部显示\n");
  scanf("%d",&select);
  switch(select)
  {
	case 1:
	  		tid_refer(len);
	  		break;
	case 2:
	  		tall_refer(len);
	  		break;
	default:
	  		printf("您输入的格式错误，请重新输入");
	  		scanf("%d",&select);
	  		break;
  }
}
void tid_refer(int len)    //对教师工号查询函数
{
  int id,i,a;
  printf("请输入要查询的教师工号：");
  scanf("%d",&id);
  for(i=0;i<len;i++)
  {
	if(id==t[i].id)
	{
	  a=0;
	  break;
	}
	else
	{
	  a=1;
	}
  }
  if(a==0)
  {
	printf("工号：%d\t",t[i].id);
	printf("姓名：%s\t",t[i].name);
	printf("密码：%s\t",t[i].passwd);
	printf("班级：%d\n",t[i].teach);
  }
  else
  {
	printf("未查询到工号为%d的教师信息！！！\n",id);
  }
}
void tall_refer(int len) //显示所有教师的信息函数
{
  for(int i=0;i<len;i++)
  {
	printf("工号：%d\t",t[i].id);
	printf("姓名：%s\t",t[i].name);
	printf("密码：%s\t",t[i].passwd);
	printf("班级：%d\n",t[i].teach);
  }
}
int  twfile(int len)   //教师信息的读文件
{
  FILE *fp=fopen("t.txt","w+");
  if(fp==NULL)
  {
	printf("无法打开文件\n");
	return 0;
  }
  fwrite(t,sizeof(struct teacher),len,fp);    //将录入信息写入文件
  fclose(fp);
  return 0;
}
int  trfile()     //老师信息的读文件
{
  FILE *fp=fopen("t.txt","r+"); 
  if(fp==NULL)
	return 0;
  int len=0;         //判断有无老师信息
  while(fread(&t[len],sizeof(struct teacher),1,fp)>0)
  {
	len++;
  }
  return len;
}
