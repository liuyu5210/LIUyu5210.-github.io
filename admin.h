#pragma once
#include"A.h"
#include"stu.h"
#include"tea.h"
#include"fudao.h"

class admin
{
public:
    int num;//人数
	A** a;//存储数据的数组
    bool Isempty;//测试文件内容是否为空
    admin();//构造函数声明
    void show_menu();//展示菜单
    ~admin(); //析构函数声明
    void add();//增加员工函数声明
    void save();//保存数据
    int get_EmpNum();//员工人数
    void showInfo();//显示员工信息
    int Isexist(int i);//根据id判断是否存在该员工
    void Det();//删除函数声明
    void Mod();//修改函数声明
    void find();//根据id查找该员工
    void bulu();//根据id排序
    void qk();//清空文件


};