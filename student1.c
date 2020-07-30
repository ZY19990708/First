#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
Student stu;
void anykey_continue(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	puts("任意键继续...");
	getch();
}
//查排名
void find(int num)
{
	int pm =1;
	float avg=(stu.Chinese[num]+stu.Math[num]+stu.English[num])/3;
	for(int i=0;i<100;i++)
	{
		if(stu.Chinese[i]+stu.Math[i]+stu.English[i]>stu.Chinese[num]+stu.Math[num]+stu.English[num])
		{
			pm++;	
		}
	}
	int max = (stu.Chinese[num]>stu.Math[num]) ? stu.Chinese[num] : stu.Math[num];
	    max = (max>stu.English[num]) ? max : stu.English[num];
	int min = (stu.Chinese[num]<stu.Math[num]) ? stu.Chinese[num] : stu.Math[num];
	    min = (min<stu.English[num]) ? min : stu.English[num];
	printf("排名:%d\n平均分:%g\n最高法:%d\n最低分:%d\n",pm,avg,max,min);
	anykey_continue();
}

//修改密码
void cpd(int num)
{
	char str[10];
	scanf("%s",str);
	strcpy(stu.pw[num],str);
	anykey_continue();
}

//查看个人信息
void look(int num)
{
	printf("姓名:%s\n性别:%c\n学号:%d\n语文:%d\n数学:%d\n英语:%d\n",stu.name[num],stu.sex[num],stu.ID[num],stu.Chinese[num],stu.Math[num],stu.English[num]);	
	anykey_continue();
}

//显示学生界面
char menu(void)
{
	puts("1.查询排名\n");
	puts("2.修改密码\n");
	puts("3.查看个人信息\n");
	puts("4.退出学生系统\n");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}

//进入学生界面
void run_stu(void)
{
	int num1,snum=-1,cnt=0;
	char num2[10];
	printf("欢迎进入学生管理系统!\n");
	printf("输入学号:\n");
	scanf("%d",&num1);
	printf("输入密码:\n");
	scanf("%s",num2);

	//判断输入的学号在结构中的位置
	for(int i=0;i<100;i++)
	{
		if(num1 != stu.ID[snum])
		{	
			snum++;
		}
		if(num1 == stu.ID[snum])
		{
			break;	
		}
	}
	if(snum == 99 && num1 != stu.ID[snum])
	{
		printf("无此学生，请寻找教师!");
		return 0;
	}
	for(;;)
	{
	if(3 == cnt)
	{
		printf("三次输入密码错误，请寻找教师!");
		return 0;
	}
	//密码判定
	if(strcmp(stu.pw[snum],num2)!=0)
	{
		printf("密码错误,重新输入密码:\n");
		scanf("%s",num2);
		cnt++;
	}
	if(stu.pw[snum] == num2)
	{
		break;	
	}
	}

	//如果是第一次输入密码
	if(0 == stu.pd[snum])
	{
		char str[10];
		printf("重置密码，请输入新密码:\n");
		scanf("%s",str);
		strcpy(stu.pw[snum],str);
		stu.pd[snum]=1;
	}
	for(;;)
	{
	system("clean");
	switch(menu())
	{
		case 1:find(snum);break;	
		case 2:cpd(snum);break;	
		case 3:look(snum);break;
		case 4:return 0;	
	}
	}
}
