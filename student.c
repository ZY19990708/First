#include <stdio.h>
#include <string.h>
#include "student.h"
Student stu;
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
	    min = (min<stu.English[num]) ? max : stu.English[num];
	printf("排名:%d\n平均分:%g\n最高法:%d\n最低分:%d\n",pm,avg,max,min);
}

//修改密码
void cpd(int num)
{
	char str[10];
	scanf("%s",str);
	strcpy(stu.pw[num],str);
}

//查看个人信息
void look(int num)
{
	printf("姓名:%s\n性别:%c\n学号:%d\n语文:%d\n数学:%d\n英语:%d\n",stu.name[num],stu.sex[num],stu.ID[num],stu.Chinese[num],stu.Math[num],stu.English[num]);	
}

//显示学生界面
char menu(void)
{
	puts("1.查询排名");
	puts("2.修改密码");
	puts("3.查看个人信息");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}

//进入学生界面
void run_stu(void)
{
	int num1,snum=0;
	char num2[10];
<<<<<<< HEAD
=======
	printf("欢迎进入学生管理系统！");
>>>>>>> 65b7d205e0f4bed5387852e980be8df26c3ea566
	printf("输入学号:");
	scanf("%d",&num1);
	printf("输入密码:");
	scanf("%s",num2);

	//判断输入的学号在结构中的位置
	while(num1 != stu.ID[snum])
	{
		snum++;
	}
	for(;;)
	{

	//密码判定
	if(strcmp(stu.pw[snum],num2)!=0)
	{
		printf("密码错误,重新输入密码:");
		scanf("%s",num2);
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
		printf("重置密码，请输入新密码:");
		scanf("%s",str);
		strcpy(stu.pw[snum],str);
		stu.pd[snum]=1;
	}
	switch(menu())
	{
		case 1:find(snum);break;	
		case 2:cpd(snum);break;	
		case 3:look(snum);break;	
	}
}
