#ifndef STUDENT_H
#define STUDENT_H
#include <getch.h>
typedef struct Student
{
	char name[100][20];
	char sex[100];
	int ID[100];
	char pw[100][10];
	int pd[100];
	int Chinese[100];
	int Math[100];
	int English[100];
}Student;
void anykey_continue(void);
//查排名
void find(int num);

//修改密码
void cpd(int num);

//查看个人信息
void look(int num);

//进入学生界面
void run_stu(void);
#endif// STUDENT_H
