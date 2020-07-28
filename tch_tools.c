#include"tch_tools.h"
#include"student.h"
extern Student stu;
static int stu_count=0;//记录学生数
static int stu_xh=10000;
void stu_add(void)//添加学生
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
	stu.ID[i]=stu_xh++;		//自动生成学号
	stu_count++;
	printf("添加成功。");
	fflush(stdout);
	usleep(500000);
	/* 
	

		批量导入学生还没写
	

	*/
}
void stu_del(void)
{
	FILE *fp=fopen("tuixue.txt","a");  //删除信息的学生保存在一个“退学”文件中
	int i=0;					//比对信息
	int key;
	printf("请输入要删除的学生学号：");
	scanf("%d",&key);
do
	{
		if (stu.sex[i])
		{
			
				if(stu.ID[i]==key)
				{
					break;
				}
			
			
		}
	}while(++i<100);
	if(i<100)
	{
		int key1;
		printf("请再输入一遍，确认要删除的学生学号：");
		scanf("%d",&key1);
		if(key==key1)
		{		
			printf("删除%s的信息成功。\n",stu.name[i]);
			fprintf(fp,"%s %c %d",stu.name[i],stu.sex[i],stu.ID[i]);
			fflush(stdout);
			usleep(500000);
			fprintf(fp,"%s %c %d",stu.name[i],stu.sex[i],stu.ID[i]);
			stu.sex[i]=0;
<<<<<<< HEAD
			stu_count--;	
=======
			stu_count--;			
			
			
			

 
>>>>>>> 6367c08a5cdd424fc9c17c78405a97137a9de202
		}
	}
	else
	{
		printf("没有此学生。");
		
		fflush(stdout);
		usleep(500000);
	}
			fclose(fp);   //退出文件
}
void stu_find(void)//查找学生
{
	char key[20]={};
	printf("请输入查询关键字：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&(strstr(stu.name[i],key)))
		{
			printf("%s %s %d 语文：%d 数学：%d 英语：%d\n",stu.name[i],'w'==stu.sex[i]?"女":"男",stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);	
		}	
	}
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	puts("任意键继续。");
	getch();
}
void stu_modify(void)//修改学生信息
{
	char key[20]={};
	printf("输入修改的学生姓名：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&0==strcmp(stu.name[i],key))
		{
			printf("输入修改后的信息（姓名、性别、语文、数学和英语成绩：");
			scanf("%s %c %d %d %d ",stu.name[i],stu.sex+i,&stu.Chinese[i],&stu.Math[i],&stu.English[i]);
			printf("修改成功。\n");
			
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("未找到此学生。\n");
	
	fflush(stdout);
	usleep(500000);
}
void stu_score(void)//录入成绩
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
			scanf("%d %d %d ",&stu.Chinese[i],&stu.Math[i],&stu.English[i]);
			printf("录入%s成绩成功。\n",stu.name[i]);
			
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("未找到此学生。\n");
	
	fflush(stdout);
	usleep(500000);
	/*

		批量导入还没写
	
	*/
}
