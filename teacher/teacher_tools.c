#include "teacher_tools.h"

void show_str(const char* str,int time)			// 使字符串显示一段时间
{
	printf("%s\n",str);
	usleep(time*1000000);
}

void anykey_continue(void)				
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	printf("任意键继续");
	getchar();
}
int stu_reset(void)					// 学生密码重置
{
	int id;       
	char key[10];
	int i=0;
	
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("请输入学生学号\n");
	if(scanf("%d",&id)==0)
	{
		show_str("学号格式错误",0.5);
		return 1;
	}
	while(id!=stu.ID[i] && i<100)
	{
		i++;
	}
	if(i==100)
	{						// 错误提示
		show_str("该学号不存在",0.5);
		return 1;
	}
	printf("请输入修改后的密码\n");
	scanf("%s",key);
	strcpy(stu.pw[i],key);
	show_str("修改成功",0.5);
	return 1;
}
void tch_show_in(void)					// 在校学生信息显示
{
	system("clear");
	printf("------在校学生信息显示------\n");
	for(int i=0;i<100;i++)
	{
		if(stu.sex[i]=='w' || stu.sex[i]=='m')
		{
			SHOW_MESSAGE(stu.name[i],stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i],stu.pw[i],stu.sex[i]=='w'?"女":"男");
		}
	}
	anykey_continue();
}
void tch_show_out(void)					// 退学学生信息显示
{
	system("clear");
	printf("------退学信息显示------\n");
	for(int i=0;i<100;i++)
	{
		if(l_stu.sex[i]=='w' || l_stu.sex[i]=='m')
		{
			SHOW_MESSAGE(l_stu.name[i],l_stu.ID[i],l_stu.Chinese[i],l_stu.Math[i],l_stu.English[i],l_stu.pw[i],l_stu.sex[i]=='w'?"女":"男");
		}
	}
	anykey_continue();
}
