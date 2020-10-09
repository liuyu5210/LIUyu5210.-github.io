#pragma once
#include"A.h"

class fudao :public A
{
public:
	fudao(int id, string name, string work,string clas);//构造函数声明
	~fudao();//析构函数声明

	virtual void showinfo();
};