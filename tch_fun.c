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
		usleep(1000000);
		return 0;
		}
	printf("请输入修改后的密码\n");
	scanf("%s",key);
	strcpy(stu.pw[i],key);
	printf("修改成功！\n");
	fflush(stdout);
	usleep(1000000);
	return 1;
	}
void tch_show_in(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	for(int i=0;i<100;i++)
	{
		while(stu.ID[i])
		{
			printf("%s %c %d %d %d %d\n",stu.name[i],stu.sex[i],stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);
			}
		}
}
void stu_show_out(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	FILE *fp=fopen("tuixue.txt","r");
	char name[100][20]={0};
	char sex[100]={0};
	int id[100]={0};
	int chinese[100]={0};
	int math[100]={0};
	int english[100]={0};
	int i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %c%d%d%d%d",name[i],&sex[i],&id[i],&chinese[i],&math[i],&english[i]);
		printf("%s %c %d %d %d %d\n",name[i],sex[i],id[i],chinese[i],math[i],english[i]);
		}
	}
