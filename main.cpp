#include"admin.h"
#include"stu.h"

int main()
{
	admin a;
	while (true)
	{
		a.show_menu();
		int c;
		cout << "请输入您的选择：";
		cin >> c;
		switch (c)
		{
		case 0: //退出
			cout << "程序已退出！欢迎您的下次使用！" << endl;
			return 0;
			break;
		case 1: //添加信息
			a.add();
			break;
		case 2: //查看信息
			a.showInfo();
			break;
		case 3: //删除信息
			a.Det();
			break;
		case 4: //修改信息
			a.Mod();
			break;
		case 5: //查找信息
			a.find();
			break;
		case 6: //排序信息
			a.bulu();
			break;
		case 7: //清空信息
			a.qk();
			break;
		default:
			cout <<"您所输入的选项不正确，请重新输入!"<<endl ;
		}
	}
	system("pause");
	system("cls");
}