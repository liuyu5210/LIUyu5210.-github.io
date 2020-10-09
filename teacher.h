#ifndef TEACHER_H
#define TEACHER_H
struct teacher
{
  int id;
  char name[128];
  char passwd[32];
  int teach;
};
struct teacher t[100];
int teacher(int i,int len);
void trefer(int i,int len);
void tmodify(int i,int len);
void sturank(int len);
int stuadd(int len);
int studelete(int len);
void stumodify(int len);
void sturefer(int len);
void id_refer(int len);
void Class_refer(int len);
void name_refer(int len);
void stushow(int len);
void id_show(int len);
void rank_show(int len);
void subject_show(int len);
void math_show(int len);
void c_show(int len);
void chinese_show(int len);
void stuprintf(int len);
int  stuwfile(int len);
int  sturfile();
#endif	
