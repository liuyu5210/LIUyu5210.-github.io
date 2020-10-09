#include"tea.h"

tea::tea(int id, string name, string work, string clas)
{
	this->id = id;
	this->name = name;
	this->work = work;
	this->clas = clas;
}
tea ::~tea()
{
}
void tea::showinfo()
{
	cout << "id=" << id << "\tname=" << name << "\tprofession=" << work<<"\tclass="<<clas<<endl;
}