#include <stdio.h>
#include <stdlib.h>
#include "sign.h"
#include "tch_fun.h"
extern struct teacher tch;
extern int tch_num[];
extern int tch_chance[];
void change(int i)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("第一次登录，请修改密码\n");
	char n[10];
	printf("请输入修改后密码\n");
	scanf("%s",n);
	printf("修改成功！\n");	
	strcpy(tch.key[i],n);
	tch_num[i]=1;
	fflush(stdout);		
	usleep(500000);
	}
int tch_sign(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("请输入工号\n");
	int id;
	char key[10];
	scanf("%d",&id);
	printf("请输入密码\n");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	gets(key);
	int i=0,j=0;
	while(tch.id[i]!=id && i<100)
	{
		i++;
		}
	if(100==i)
	{
		printf("该工号不存在，请再次输入！\n");
		fflush(stdout);		
		usleep(500000);
		return 0;
	}
	else
	{
		if(tch.key[i][0]=='\0')
		{
			printf("该账户已锁定，请找校长解锁\n");
			fflush(stdout);
			usleep(500000);
			return 0;
			}
		else
		{
			if(tch_chance[i]<3)
			{
				if(0==strcmp(key,tch.key[i]))
				{
					printf("登录成功！\n");
					fflush(stdout);
					usleep(500000);
					if(tch_num[i]==0)
					{
						change(i);
						}
					tch_chance[i]=0;
					return 1;
				}
				else
				{
					printf("密码错误，还有%d次机会\n",2-tch_chance[i]);
					fflush(stdout);
					usleep(500000);
					tch_chance[i]++;
					return 0;
				}
			}
		}
	}
	printf("该账户已锁定，请找校长解锁\n");
	tch.key[i][0]='\0';
	return 0;
}
void tch_show()
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("1.添加学生\n");
	printf("2.删除学生\n");
	printf("3.查找学生\n");
	printf("4.修改学生信息\n");
	printf("5.录入学生成绩\n");
	printf("6.重置学生密码\n");
	printf("7.显示所有在校学生信息\n");
	printf("8.显示所有退出学生信息\n");
	printf("9.退出\n");
}
