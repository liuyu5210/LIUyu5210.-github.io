#pragma once
#include"A.h"

class tea :public A
{
public:
	tea(int id, string name, string work, string clas);//���캯������
	~tea();//������������

	virtual void showinfo();
};