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
	cout << "@@@  欢迎使用学工系统  @@@" << endl;
	cout << "@@@@@  1、添加信息   @@@@@" << endl;
	cout << "@@@@@  2、查看信息   @@@@@" << endl;
	cout << "@@@@@  3、删除信息   @@@@@" << endl;
	cout << "@@@@@  4、修改信息   @@@@@" << endl;
	cout << "@@@@@  5、查找信息   @@@@@" << endl;
	cout << "@@@@@  6、排序信息   @@@@@" << endl;
	cout << "@@@@@  7、清空信息   @@@@@" << endl;
	cout << "@@@@@  0、退出       @@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}

void admin::showInfo()
{
	if (this->Isempty)
	{
		cout<<"文件不存在或记录为空！"<<endl;
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
	cout << "输入的人员数量：";
	cin >> num;
	if (num > 0)
	{
		int newsize = this->num + num;//重新计算空间大小
		A** newarr = new A * [newsize];//重新申请空间
		if (this->a != NULL) //将原来数组内容转到新数组中
		{
			for (int i = 0; i < this->num; i++)
			{
				newarr[i] = this->a[i];
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << "请输入第" << i + 1 << "个人员的id:";
			cin >> id;
			cout << "请输入第" << i + 1 << "个人员的姓名:";
			cin >> name;
			
			cout << "请选择类别" << endl;
			cout << "1、学生" << endl;
			cout << "2、老师" << endl;
			cout << "3、辅导员" << endl;
			cin >> s;
			switch (s)
			{
			case 1:
				cout << "请选择该人员所在班级" << endl;
				cin >> clas;
				aa = new stu(id, name, "学生",clas);
				break;
			case 2:
				cout << "请选择该人员所在班级" << endl;
				cin >> clas;
				aa = new tea(id, name, "老师",clas);
				break;
			case 3:
				cout << "请选择该人员所在班级" << endl;
				cin >> clas;
				aa = new fudao(id, name, "辅导员",clas);
				break;
			}
			newarr[this->num + i] = aa;
		}
		delete[] this->a;
		this->a = newarr;
		this->num = newsize;
		this->Isempty = false;
		cout << "成功添加" << num << "名新人员！" << endl;
		this->save();
	}
	else
	{
		cout << "输入错误！" << endl;
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
		//记录人数
		num++;
	}
	ifs.close();
	return num;
}
void admin::Det()
{
	if (this->Isempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int c;
		cout << "请输入您所要删除的id号";
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "员工不存在！" << endl;
		}
		else
		{
			for (int j = c; j < this->num - 1; j++)
			{
				this->a[j] = this->a[j + 1];
			}
			this->num--;
			this->save();
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void admin::Mod()
{
	if (this->Isempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int c;
		cout << "请输入你想要修改的人员id: ";//可以显示
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "员工不存在！" << endl;
		}
		else
		{
			delete this->a[a];//debug 卡在这里
			int id, s;
			A* aa = NULL;
			string name,clas;
			cout << "请输入新的id:";
			cin >> id;
			cout << "请输入新的姓名:";
			cin >> name;
			cout << "请选择该人员所在班级" << endl;
			cin >> clas;
			cout << "请选择类别" << endl;
			cout << "1、学生" << endl;
			cout << "2、老师" << endl;
			cout << "3、辅导员" << endl;
			cin >> s;
			switch (s)
			{
			case 1:
				aa = new stu(id, name, "学生", clas);
				break;
			case 2:
				aa = new tea(id, name, "老师", clas);
				break;
			case 3:
				aa = new fudao(id, name, "辅导员", clas);
				break;
			}
			this->a[a] = aa;
			cout<<"修改成功！"<<endl;
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int c;
		cout << "请输入你想要查找人员的id: ";
		cin >> c;
		int a = this->Isexist(c);
		if (a == -1)
		{
			cout << "员工不存在！" << endl;
		}
		else
		{
			cout<<"查找成功！"<<endl;
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int c;
		cout << "请选择排序方式" << endl;
		cout << "1、升序" << endl;
		cout << "2、倒序" << endl;
		cout << "请输入您的选择：";
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
			cout << "输入的选择不对，请重新输入。" << endl;
		}
		this->save();//将排序后的数据保存到文件里
		this->showInfo();//将排序后的数据展示
	}
}
void admin::qk() 
{
	if (this->Isempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		string c;
		cout << "确定清空所有数据吗？\t确定：y,取消：n" << endl;
		cout << "输入您的选择：";
		cin >> c;
		if (c == "y")
		{
			this->num = 0;
			delete[] this->a;
			this->a = NULL;
			this->Isempty = true;
			this->save();
			cout << "已清空！" << endl;
		}
		else
		{
			return;
		}
	}
	system("pause");
	system("cls");
}