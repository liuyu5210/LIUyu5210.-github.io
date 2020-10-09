#pragma once
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	int id;
	string name, work,clas;
	
	virtual void showinfo()=0;//展示信息

};
