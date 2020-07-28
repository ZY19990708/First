#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef TCH_FUN_H
#define TCH_FUN_H
struct teacher
{
	char name[100][20];
	char sex[100];
	int id[100];
	int key[100];
	};
int stu_reset(void);
void tch_show_in(void);
void tch_show_out(void);
#endif//TCH_FUN_H
