#include "tch_fun.h"
#include "student.h"
extern Student stu;
int stu_reset(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("请输入学生学号\n");
	int id;
	char key[10];
	int i=0;
	scanf("%d",&id);
	while(id!=stu.ID[i] && i<100)
	{
		i++;
		}
	if(i==100)
	{
		printf("该学号不存在，请重新输入\n");
		fflush(stdout);
		usleep(500000);
		return 0;
		}
	printf("请输入修改后的密码\n");
	scanf("%s",key);
	strcpy(stu.pw[i],key);
	printf("修改成功！\n");
	fflush(stdout);
	usleep(500000);
	return 1;
	}
void tch_show_in(void)
{
	for(int i=0;i<100;i++)
	{
		if(stu.sex[i])
		{
			printf("%s %s %d 语文：%d 数学：%d 英语：%d\n",stu.name[i],stu.sex[i]=='m'?"男":"女",stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);
			}
		}
	printf("按任意键继续");
	getchar();
}
void tch_show_out(void)
{
	FILE *fp=fopen("tuixue.txt","r");

	char name[100][20];
	char sex[100];
	int id[100];
	int i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %c%d ",name[i],&sex[i],&id[i]);
		printf("%s %s %d\n",name[i],sex[i]=='m'?"男":"女",id[i]);
		i++;
		}
	printf("按任意键继续");
	getchar();
	fclose(fp);
	}
