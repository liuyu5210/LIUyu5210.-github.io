#include"admin.h"
#include"stu.h"

int main()
{
	admin a;
	while (true)
	{
		a.show_menu();
		int c;
		cout << "����������ѡ��";
		cin >> c;
		switch (c)
		{
		case 0: //�˳�
			cout << "�������˳�����ӭ�����´�ʹ�ã�" << endl;
			return 0;
			break;
		case 1: //�����Ϣ
			a.add();
			break;
		case 2: //�鿴��Ϣ
			a.showInfo();
			break;
		case 3: //ɾ����Ϣ
			a.Det();
			break;
		case 4: //�޸���Ϣ
			a.Mod();
			break;
		case 5: //������Ϣ
			a.find();
			break;
		case 6: //������Ϣ
			a.bulu();
			break;
		case 7: //�����Ϣ
			a.qk();
			break;
		default:
			cout <<"���������ѡ���ȷ������������!"<<endl ;
		}
	}
	system("pause");
	system("cls");
}