#include"fudao.h"

fudao::fudao(int id, string name, string work,string clas)
{
	this->id = id;
	this->name = name;
	this->work = work;
	this->clas = clas;
}
fudao ::~fudao()
{
}
void fudao::showinfo()
{
	cout << "id=" << id << "\tname=" << name << "\tprofession=" << work<<"\tclass=" << clas<<endl;
}