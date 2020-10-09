#include "admin.h"
#include<fstream>

admin::admin()
{
	this->num = 0;
	this->a = NULL;
	this->Isempty = true;
}
admin::~admin()
{
	if (!this->Isempty)
	{
		delete[] a;
	}
}
void admin::show_menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@  ��ӭʹ��ѧ��ϵͳ  @@@" << endl;
	cout << "@@@@@  1�������Ϣ   @@@@@" << endl;
	cout << "@@@@@  2���鿴��Ϣ   @@@@@" << endl;
	cout << "@@@@@  3��ɾ����Ϣ   @@@@@" << endl;
	cout << "@@@@@  4���޸���Ϣ   @@@@@" << endl;
	cout << "@@@@@  5��������Ϣ   @@@@@" << endl;
	cout << "@@@@@  6��������Ϣ   @@@@@" << endl;
	cout << "@@@@@  7�������Ϣ   @@@@@" << endl;
	cout << "@@@@@  0���˳�       @@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

void admin::showInfo()
{
	if (this->Isempty)
	{
		cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		for (int i = 0; i < this->num; i++)
		{
			this->a[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
int admin::Isexist(int i)
{
	int index = -1;
	for (int c=0;c<this->num;c++)
	{
		if (this->a[c]->id==i)
		{
			index = c;
			break;
		}
	}
	return index;
}
void admin::add()
{
	int num, s, id;
	string name,clas;
	A* aa = NULL;
	cout << "�������Ա������";
	cin >> num;
	if (num > 0)
	{
		int newsize = this->num + num;//���¼���ռ��С
		A** newarr = new A * [newsize];//��������ռ�
		if (this->a != NULL) //��ԭ����������ת����������
		{
			for (int i = 0; i < this->num; i++)
			{
				newarr[i] = this->a[i];
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << "�������" << i + 1 << "����Ա��id:";
			cin >> id;
			cout << "�������" << i + 1 << "����Ա������:";
			cin >> name;
			
			cout << "��ѡ�����" << endl;
			cout << "1��ѧ��" << endl;
			cout << "2����ʦ" << endl;
			cout << "3������Ա" << endl;
			cin >> s;
			switch (s)
			{
			case 1:
				cout << "��ѡ�����Ա���ڰ༶" << endl;
				cin >> clas;
				aa = new stu(id, name, "ѧ��",clas);
				break;
			case 2:
				cout << "��ѡ�����Ա���ڰ༶" << endl;
				cin >> clas;
				aa = new tea(id, name, "��ʦ",clas);
				break;
			case 3:
				cout << "��ѡ�����Ա���ڰ༶" << endl;
				cin >> clas;
				aa = new fudao(id, name, "����Ա",clas);
				break;
			}
			newarr[this->num + i] = aa;
		}
		delete[] this->a;
		this->a = newarr;
		this->num = newsize;
		this->Isempty = false;
		cout << "�ɹ����" << num << "������Ա��" << endl;
		this->save();
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}

void admin::save()
{
	ofstream ofs;
	ofs.open("info.txt", ios::out);
	for (int i = 0; i < this->num; i++)
	{
		ofs << this->a[i]->id << "  " << this->a[i]->name << "  " << this->a[i]->work <<"  "<<this->a[i]->clas<< endl;
	}
}
int admin::get_EmpNum()
{
	ifstream ifs;
	ifs.open("info.txt", ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//��¼����
		num++;
	}
	ifs.close();
	return num;
}
void admin::Det()
{
	if (this->Isempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int c;
		cout << "����������Ҫɾ����id��";
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "Ա�������ڣ�" << endl;
		}
		else
		{
			for (int j = c; j < this->num - 1; j++)
			{
				this->a[j] = this->a[j + 1];
			}
			this->num--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void admin::Mod()
{
	if (this->Isempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int c;
		cout << "����������Ҫ�޸ĵ���Աid: ";//������ʾ
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "Ա�������ڣ�" << endl;
		}
		else
		{
			delete this->a[a];//debug ��������
			int id, s;
			A* aa = NULL;
			string name,clas;
			cout << "�������µ�id:";
			cin >> id;
			cout << "�������µ�����:";
			cin >> name;
			cout << "��ѡ�����Ա���ڰ༶" << endl;
			cin >> clas;
			cout << "��ѡ�����" << endl;
			cout << "1��ѧ��" << endl;
			cout << "2����ʦ" << endl;
			cout << "3������Ա" << endl;
			cin >> s;
			switch (s)
			{
			case 1:
				aa = new stu(id, name, "ѧ��", clas);
				break;
			case 2:
				aa = new tea(id, name, "��ʦ", clas);
				break;
			case 3:
				aa = new fudao(id, name, "����Ա", clas);
				break;
			}
			this->a[a] = aa;
			cout<<"�޸ĳɹ���"<<endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}
void admin::find() 
{
	if (this->Isempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int c;
		cout << "����������Ҫ������Ա��id: ";
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "Ա�������ڣ�" << endl;
		}
		else
		{
			cout<<"���ҳɹ���"<<endl;
			this->a[a]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
void admin::bulu()
{
	if (this->Isempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int c;
		cout << "��ѡ������ʽ" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		cout << "����������ѡ��";
		cin >> c;
		switch (c)
		{
		case 1:
			for (int i = 0; i < this->num; i++)
			{
				for (int j = 0; j < this->num - 1; j++)
				{
					if (this->a[j]->id > this->a[j + 1]->id)
					{
						A* w = this->a[j];
						this->a[j] = this->a[j + 1];
						this->a[j + 1] = w;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < this->num; i++)
			{
				for (int j = 0; j < this->num - 1; j++)
				{
					if (this->a[j]->id < this->a[j + 1]->id)
					{
						A* w = this->a[j];
						this->a[j] = this->a[j + 1];
						this->a[j + 1] = w;
					}
				}
			}
			break;
		default:
			cout << "�����ѡ�񲻶ԣ����������롣" << endl;
		}
		this->save();//�����������ݱ��浽�ļ���
		this->showInfo();//������������չʾ
	}
}
void admin::qk() 
{
	if (this->Isempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		string c;
		cout << "ȷ���������������\tȷ����y,ȡ����n" << endl;
		cout << "��������ѡ��";
		cin >> c;
		if (c == "y")
		{
			this->num = 0;
			delete[] this->a;
			this->a = NULL;
			this->Isempty = true;
			this->save();
			cout << "����գ�" << endl;
		}
		else
		{
			return;
		}
	}
	system("pause");
	system("cls");
}