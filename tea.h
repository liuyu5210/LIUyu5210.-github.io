#pragma once
#include"A.h"

class tea :public A
{
public:
	tea(int id, string name, string work, string clas);//构造函数声明
	~tea();//析构函数声明

	virtual void showinfo();
};