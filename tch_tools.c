#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include"tch_tools.h"
#include<getch.h>
static int stu_count=0;			//学生数变量
static char stu.name[100][20];	//姓名
static char stu.sex[100];     	//性别
static char stu.ID[100][10];	//学号
static int stu.Chinese[100];		//语文成绩
static int stu.Math[100];		//数学成绩
static int stu.English[100];		//英语成绩
void stu_add(void)
{
	if(stu_count>=100)
		{
			printf("超出学生人数限制。");
			return;
		}	

	int i=0;
	while(stu.sex[i]) i++;
	printf("请输入学生姓名 性别：");
	scanf("%s %c",stu.name[i],stu.sex+i);
	stu.ID[i]=stu_count+1;		//自动生成学号
	stu_count++;
	/* 


		批量导入学生
	

	*/
}
void stu_del(void)
{
	char i=0;
	char key[20]={};
	printf("请输入要删除的学生信息：");
	scanf("%s",key);
do
	{
		if (stu.sex[i])
		{
			if(isdigit(key[0]))
			{
				if(0==strcmp(stu.ID[i],key))
				{
					break;
				}
			}
			else
			{
				if(0==strcmp(stu.name[i],key))
				{
					break;
				}
			}
			
		}
	}while(++i<100);
	if(i<100)
	{
		char key1[20]={};
		printf("请再输入一遍，确认要删除的学生信息：");
		scanf("%s",key1);
		if(key==key1)
		{		
			printf("删除%s的信息成功。\n",stu.name[i]);
			stu.sex[i]=0;
			stu_count--;			
			FILE *fp=fopen("tuixue.txt","a");  //删除信息的学生保存在退学文件中
			fprintf(fp,"%s ",stu.name[i]);
			int fclose(fp);

 
		}
	}
	else
	{
		printf("没有此学生。");
	}
}
void stu_find(void)
{
	char key[20]={};
	printf("请输入查询关键字：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&(strstr(stu.name[i],key)||strstr(stu.ID[i],key)))
		{
			printf("%s %s %s %d %d %d\n",stu.name[i],'w'==stu.sex[i]?"女":"男",stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);	
		}	
	}
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	puts("任意键继续。");
	getch();
}
void stu_modify(void)
{
	char key[20]={};
	printf("输入修改的学生姓名：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&0==strcmp(stu.name[i],key))
		{
			printf("输入修改后的信息：");
			scanf("%s %c %s %d %d %d",stu.name[i],stu.sex+i,stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);
			printf("修改成功。\n");
			return;
		}
	}
	printf("未找到此学生。\n");
}
void stu_score(void)
{
	char key[20]={};
	printf("输入录入成绩的学生姓名：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&0==strcmp(stu.name[i],key))
		{
			printf("输入需要录入的成绩：");
			scanf("%s %d %d %d",stu.name[i],stu.Chinese[i],stu.Math[i],stu.English[i]);
			printf("录入%s成绩成功。\n",stu.name[i]);
			return;
		}
	}
	printf("未找到此学生。\n");
	/*批量录入*/
}
