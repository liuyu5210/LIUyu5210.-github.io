#pragma once
#include"A.h"

class fudao :public A
{
public:
	fudao(int id, string name, string work,string clas);//���캯������
	~fudao();//������������

	virtual void showinfo();
};