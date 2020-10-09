#include"stu.h"

 stu ::stu(int id, string name, string work,string clas)
{
	 this->id = id;
	 this->name = name;
	 this->work = work;
	 this->clas = clas;
}
 stu ::~stu()
{	
}
 void stu::showinfo()
 {
	 cout << "id="<<id<<"\tname="<<name<<"\tprofession="<<work << "\tclass=" << clas <<endl;
 }