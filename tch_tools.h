#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<getch.h>
#ifndef TCH_TOOLS_H
#define TCH_TOOLs_H
typedef struct teacher
{
	char name[100][20];
	char sex[100];
	int id[100];
	int key[100];
	}teacher;
teacher tch;
void stu_add(void);
void stu_del(void);
void stu_modify(void);
void stu_find(void);
void stu_score(void);
#endif//TCH_TOOLS_H
