#pragma once
#include"A.h"

class stu :public A
{
public:
	stu(int id,string name,string work, string clas);//���캯������
	~stu();//������������
	 virtual void showinfo();
};