#pragma once
#include"A.h"

class stu :public A
{
public:
	stu(int id,string name,string work, string clas);//构造函数声明
	~stu();//析构函数声明
	 virtual void showinfo();
};