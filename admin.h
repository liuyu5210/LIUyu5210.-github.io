#pragma once
#include"A.h"
#include"stu.h"
#include"tea.h"
#include"fudao.h"

class admin
{
public:
    int num;//����
	A** a;//�洢���ݵ�����
    bool Isempty;//�����ļ������Ƿ�Ϊ��
    admin();//���캯������
    void show_menu();//չʾ�˵�
    ~admin(); //������������
    void add();//����Ա����������
    void save();//��������
    int get_EmpNum();//Ա������
    void showInfo();//��ʾԱ����Ϣ
    int Isexist(int i);//����id�ж��Ƿ���ڸ�Ա��
    void Det();//ɾ����������
    void Mod();//�޸ĺ�������
    void find();//����id���Ҹ�Ա��
    void bulu();//����id����
    void qk();//����ļ�


};