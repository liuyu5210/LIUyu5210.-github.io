#ifndef STUDENT_H
#define STUDENT_H
struct student
{
  int id;
  char name[128];
  char passwd[32];
  int age;
  int Class;
  int math;
  int c;
  int chinese;
  int sum;
  int rank;
};
struct student stu[500];
int student(int i,int len);
void refer(int i,int len);
void modify(int i,int len);
void quit();
int menu();
#endif	


