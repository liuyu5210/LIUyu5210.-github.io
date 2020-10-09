#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#include"teacher.h"
#include"tooler.h"
int teacher(int i,int len)
{
  system("clear");
  printf("****************************************\n");
  printf("*      欢迎%s老师登录学生管理系统      *\n",t[i].name);
  printf("*  1.个人信息查询    2.个人信息修改    *\n");
  printf("*  3.学生信息录入    4.学生信息删除    *\n");
  printf("*  5.学生信息修改    6.学生信息查找    *\n");
  printf("*  7.学生信息显示    8.退出管理系统    *\n");
  printf("****************************************\n");
  printf("\n请选择:");
  int select;
  scanf("%d",&select);
  switch(select)
  {
	case 1:
	  		trefer(i,len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 2:
	  		tmodify(i,len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 3:
	  		len=stuadd(len);
	  		stuwfile(len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 4:
	  		len=studelete(len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 5:
	  		stumodify(len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 6:
	  		sturefer(len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 7:
	  		sturank(len);
	  		stushow(len);
	  		getchar();
	  		printf("输入回车返回主菜单\n");
	  		while('\n'==getchar())
	  		{
				teacher(i,len);
	  		}
	  		break;
	case 8:
	  		quit();
	  		break;
	default:
	  		printf("\n输入格式有误，请重新输入:");
	  		scanf("%d",&select);
	  		break;
  }
  return 0;
}
void  trefer(int i,int len)//教师信息查询函数
{
  printf("工号：%d\t",t[i].id);
  printf("姓名：%s\t",t[i].name);
  printf("密码：%s\t",t[i].passwd);
  printf("班级：%d\n",t[i].teach);
}
void tmodify(int i,int len)//教师信息修改函数
{
  char ch[128];
  printf("是否修改信息？(y/n)\n");
  scanf("%s",ch);
  if(!strcmp("y",ch))
  {
	printf("请输入新密码: ");
	scanf("%s",t[i].passwd);
	printf("是否保存修改后的信息?(y/n)\n");
	scanf("%s",ch);
	if(!strcmp("y",ch))
	{
	  twfile(len);
	  len=trfile();
	  printf("信息保存成功！！！\n");
	}
  }
  else
	len=trfile();
}
void sturank(int len)	//学生名次排序，冒泡排序		
{	
  int i,j;	
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].sum<stu[i+1].sum)
	  {
		temp=stu[i+1];        
		stu[i+1]=stu[i];
		stu[i]=temp;             
	  }
	}
  }
  for(i=0;i<len;i++)
  {
	stu[i].rank=i+1;
  }
  stuwfile(len);
}
int stuadd(int len)  //增加学生函数，对学生学号排序
{
  int i,j;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].id>stu[i+1].id)
	  {
		temp=stu[i+1];        
		stu[i+1]=stu[i];
		stu[i]=temp;             
	  }
	}
  }
  stuwfile(len);
  len=sturfile();
  if(len==0)
  {
	stu[len].id=1001;
	stu[len].rank=1;
  }
  else 
  {
	stu[len].id=stu[len-1].id+1;
  }
  printf("请输入增加学生的姓名:");
  scanf("%s",stu[len].name);
  printf("输入增加学生的密码:");
  scanf("%s",stu[len].passwd);
  printf("请输入增加学生的年龄:");
  scanf("%d",&stu[len].age);
  printf("请输入增加学生的班级:");
  scanf("%d",&stu[len].Class);
  printf("请输入增加学生的数学成绩:");
  scanf("%d",&stu[len].math);
  printf("请输入增加学生的C成绩: ");
  scanf("%d",&stu[len].c);
  printf("请输入增加学生的语文成绩: ");
  scanf("%d",&stu[len].chinese);
  stu[len].sum=stu[len].math+stu[len].c+stu[len].chinese;
  len++;
  sturank(len);
  stuwfile(len);
  len=sturfile();
  printf("信息录入成功！！！\n");
  return len;
}
int studelete(int len)  //删除学生函数
{
  while(1)
  {
	printf("请输入要删除的学号: ");
	int id,i,j;
	char ch[128];
	scanf("%d",&id);
	if(len==0)
	{
	  printf("没有可以删除的学生信息\n");
	  break;
	}
	else
	{
	  int a=1;
	  for(i=0;i<len;i++)
	  {
		if(id==stu[i].id)
		{
		  a=0;
		  break;
		}
	  }
	  if(a==1)
	  {
		getchar();
		printf("输入的学号错误，按回车键重新输入\n");
		getchar();
		continue;
	  }
	  else
	  {		
		printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	  	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
		printf("\n");
		printf("是否删除该学生信息？(y/n)\n");
		scanf("%s",ch);
		if(strcmp(ch,"y")==0)
		{
		  for(j=i;j<len;j++)
		  {
			stu[j]=stu[j+1];
		  }
		  len--;
		  printf("信息删除成功！！！\n");
		}
	  }
	}
	printf("是否保存修改后的信息(y/n):");
	scanf("%s",ch);
	if(strcmp(ch,"y")==0)
	{
	  printf("信息保存成功！！！\n");
	  sturank(len);
	  stuwfile(len);
	  len=sturfile();
	}
	else
	  len=sturfile();
	break;
  }
  return len;
}
void stumodify(int len)//修改学生信息函数
{
  while(1)
  {
	int id,i;
	char ch[128];
	printf("请输入要修改的学生学号: ");
	scanf("%d",&id);
	if(len==0)
	{
	  printf("没有可以修改的学生信息！！！\n");
	  break;
	}
	else
	{
	  int flag=0; 
	  for(i=0;i<len;i++)
	  {
		if(id==stu[i].id)
		{
		  flag=1;
		  break;
		}
	  }
	  if(flag==0)
	  {
		getchar();
		printf("输入的学号错误,按回车键重新输入！！！\n");
		getchar();
		continue;
	  }
	  else
	  {
		printf("找到要修改的学生信息\n");
		printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	  	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
		printf("\n");
		printf("是否修改？(y/n):");
		scanf("%s",ch);
		if(!strcmp(ch,"y"))
		{
		  printf("请输入修改的姓名:");
		  scanf("%s",stu[i].name);
		  printf("请输入修改的密码:");
		  scanf("%s",stu[i].passwd);
		  printf("请输入修改的年龄:");
		  scanf("%d",&stu[i].age);
		  printf("请输入修改的班级:");
		  scanf("%d",&stu[i].Class);
		  printf("请输入修改的数学成绩:");
		  scanf("%d",&stu[i].math);
		  printf("请输入修改的C成绩:");
		  scanf("%d",&stu[i].c);
		  printf("请输入修改的语文成绩:");
		  scanf("%d",&stu[i].chinese);
		}
		printf("信息修改成功！！！\n");
	  }
	}
	printf("是否保存修改后的信息(y/n):");
	scanf("%s",ch);
	if(strcmp(ch,"y")==0)
	{
	  sturank(len);
	  stuwfile(len);
	  len=sturfile();
	  printf("信息保存成功！！！\n");
	}
	else
	  len=sturfile();
	break;
  }
}
void sturefer(int len)  //学生信息查询函数
{
  int select;
  printf("1.根据学号查找\n");
  printf("2.根据姓名查找\n");
  printf("3.根据班级查找\n");
  printf("请选择你要查找信息的方式:");
  scanf("%d",&select);
  switch(select)
  {
	case 1:
	  		id_refer(len);
	  		break;
	case 2:
	  		name_refer(len);
	  		break;
	case 3:
	  		Class_refer(len);
	  		break;
	default:
	  		printf("您输入的格式错误，请重新输入");
	  		scanf("%d",&select);
	  		break;
  }
}
void id_refer(int len)  //根据学号查询
{
  int id,i,a;
  printf("请输入要查询的学生学号：");
  scanf("%d",&id);
  for(i=0;i<len;i++)
  {
	if(id==stu[i].id)
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
	printf("找到该学生信息\n");
	printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
	printf("\n");
  }
  else
  {
	printf("未查询到学号为%d学生的信息！！！\n",id);
  }
}
void name_refer(int len)   //姓名查询
{
  char name[128];
  int a,i;
  printf("请输入要查询的学生姓名：");
  scanf("%s",name);
  for(i=0;i<len;i++)
  {
	if(strcmp(stu[i].name,name)==0)
	{
	  printf("找到该学生信息\n");
	  printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	  printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
	  printf("\n");
	  a=0;
	  break;
	}
	else
	{
	  a=1;
	}
  }
  if(a==1)
  {
	printf("未查询到%s学生的信息！！！\n",name);
  }
}
void Class_refer(int len)  //班级查询
{
  int Class,i,a;
  printf("请输入要查询的学生班级：");
  scanf("%d",&Class);
  for(i=0;i<len;i++)
  {
	if(Class==stu[i].Class)
	{
	  a=0;
	} 
	else
	{
	  a=1;
	}
  }
  for(i=0;i<len;i++)
  {
	if(Class==stu[i].Class)
	{
		printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	  	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
		printf("\n");
	}
  }
  if(a==1)
  {
	printf("未查询到该班级的学生的信息！！！\n");
  }
}
void stushow(int len)  //显示学生信息函数
{
  int select;
  printf("1.根据学号显示\n");
  printf("2.根据名次显示\n");
  printf("3.根据学科成绩显示\n");
  printf("请选择您要显示学生信息的显示方式:\n");
  scanf("%d",&select);
  switch(select)
  {
	case 1:
	  		id_show(len);
	  		break;
	case 2:
	  		rank_show(len);
	  		break;
	case 3:
	  		subject_show(len);
	  		break;
	default:
	  		printf("您输入的格式错误，请重新输入！！！");
	  		scanf("%d",&select);
	  		break;
  }
}
void id_show(int len)  //学号显示
{
  int i,j;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].id>stu[i+1].id)
	  {
		temp=stu[i+1];       
		stu[i+1]=stu[i];
		stu[i]=temp;             
	  }
	}
	stuwfile(len);
	len=sturfile();
  }
  stuprintf(len);
}
void rank_show(int len) //将学生总成绩排序
{
  int i,j;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].rank>stu[i+1].rank)
	  {
		temp=stu[i+1];
		stu[i+1]=stu[i];
		stu[i]=temp;
	  }
	}
	stuwfile(len);
	len=sturfile();
  }
  stuprintf(len);
}
void subject_show(int len)   //学科显示
{
  int select;
  printf("1.数学\n");
  printf("2.C语言\n");
  printf("3.语文\n");
  printf("请选择您要选择的学科:\n");
  scanf("%d",&select);
  switch(select)
  {
	case 1:
	  		math_show(len);
	  		break;
	case 2:
	  		c_show(len);
	  		break;
	case 3:
	  		chinese_show(len);
	  		break;
	default:
	  		printf("您输入的格式错误，请重新输入！！！");
	  		scanf("%d",&select);
	  		break;
  }
}
void math_show(int len)   //数学成绩排序
{
  int i,j,sum=0;
  float ave;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].math<stu[i+1].math)
	  {
		temp=stu[i+1];
		stu[i+1]=stu[i];
		stu[i]=temp;
	  }
	}
  }
  for(i=0;i<len;i++)
  {
	sum+=stu[i].math;

  }
  ave=(float)sum/len;
  printf("数学的平均成绩是%.2f\n",ave);
  stuwfile(len);
  len=sturfile();
  stuprintf(len);
}
void c_show(int len)   //C成绩排序
{
  int i,j,sum=0;
  float ave;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].c<stu[i+1].c)
	  {
		temp=stu[i+1];
		stu[i+1]=stu[i];
		stu[i]=temp;
	  }
	}
  }
  for(i=0;i<len;i++)
  {
	sum+=stu[i].c;
  }
  ave=(float)sum/len;
  printf("C语言的平均成绩是%.2f\n",ave);
  stuwfile(len);
  len=sturfile();
  stuprintf(len);
}
void chinese_show(int len)   //语文成绩排序
{
  int i,j,sum=0;
  float ave;
  struct student temp;
  for(j=0;j<len-1;j++)
  {
	for(i=0;i<len-1-j;i++)
	{
	  if(stu[i].chinese<stu[i+1].chinese)
	  {
		temp=stu[i+1];
		stu[i+1]=stu[i];
		stu[i]=temp;
	  }
	}
  }
  for(i=0;i<len;i++)
  {
	sum+=stu[i].chinese;
  }
  ave=(float)sum/len;
  printf("语文的平均成绩是%.2f\n",ave);
  stuwfile(len);
  len=sturfile();
  stuprintf(len);
}
void stuprintf(int len)   //成绩输出函数
{
  for(int i=0;i<len;i++)
  {
		printf("学号\t姓名\t密码\t年龄\t班级\t数学\tC\t语文\t名次\n");
	  	printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].id,stu[i].name,stu[i].passwd,stu[i].age,stu[i].Class,stu[i].math,stu[i].c,stu[i].chinese,stu[i].rank);
		printf("\n");
  }
}
int  stuwfile(int len)   //学生信息的写文件
{
  FILE *fp=fopen("stu.txt","w");
  if(fp==NULL)
  {
	printf("无法打开文件\n");
	return -1;
  }
  fwrite(stu,sizeof(struct student),len,fp);
  fclose(fp);
  return 0;
}
int  sturfile()   //学生信息的读文件
{
  FILE *fp=fopen("stu.txt","r"); 
  if(fp==NULL)
	return -1;
  int len=0;
  while(fread(&stu[len],sizeof(struct student),1,fp)>0)
  {
	len++;
  }
  return len;
}
