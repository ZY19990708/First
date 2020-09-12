#include <stdio.h>
#include "student.h"
#include"teacher.h"
#include"tools.h"
// 获取密码
int get_pw(char* member_pw,size_t len)
{
	char pw;
	if(stlen(gets(pw))>len) return 0;
	strcpy(member_pw,pw);
	return 1;
}
// 查找空位
int find_tch_empty()
{
	for(int i=0;i<100;i++)
	{
		if(tch[i].sex != 'w' && tch[i].sex != 'm') 
			return i;
	}
	return -1;
}
// 获取姓名
int get_name(char* member_name,int len)
{
	char name;
	P("请输入姓名:\n");
	if(strlen(name)>len) 
	{
		P("姓名有误!\n");
		return 0;
	}
	strcpy(member_name,name);
	return 1;
}
// 获取性别
int get_sex(char* member_sex)
{
	char sex;
	printf("请输入性别:\n");
	gets(sex);
	if( 'w' == sex || 'm' == sex ) 
	{
		strcpy(member_sex,sex);
		return 1;
	}
	return 0;
}
// 获取工号
int gei_id(int* member_id,int len)
{
	int id;
	printf("请输入工号:\n");
	scanf("%d",&id);
	if(-1 == search_tch(id)) 
	{
		P("工号重复!\n");
		return 0;
	}
	member_id=id;
	return 1;
}
// 教师查询
int search_tch(char id)
{
	for(int i=0;i<100;i++)
	{
		if(0 == strcmp(tch[i].id,id)) return i;
	}
	return -1;
}
// 教师删除
void _del_tch(int i)
{
	for(int j=0;j<100;j++)
	{
		if('w' != l_tch[j].sex && 'm' != l_tch[j])
		{
			strcpy(tch[j].name,tch[i].name);
			strcpy(tch[j].sex,tch[i].sex);
			tch[j].id=tch[i].id;
			break;
		}
	}
	if(j == 100) P("提示:离职教师名单已满!\n");
	strcpy(tch[i].name,'\0');
	strcpy(tch[i].sex,'\0');
	strcpy(tch[i].key,'\0');
	tch[i].id=0;
	tch[i].num=0;
	P("删除成功!\n");
	return;
}
// 校长文件写入
void master_message(int m.flag,char master_pw)
{
	FILE* fwp=fopen("校长登录判定.txt","w");
	fprintf(fwp,"%d %s",flag,master_pw);
	fclose(fwp);
}

// 任意键继续
void anykey_continue(void)
{
	printf("按任意键继续...");
	getch();
	printf("\n");
}
// 教师信息实时更新
void teacher_file(void)//教师信息实时更新
{
	FILE* fwp=fopen("在职教师.txt","w+");
	for(int i=0;i<100;i++)
	{
		if(tch.sex[i]=='w' || tch.sex[i]=='m')
		{
			fprintf(fwp,"--%d 姓名:%s 性别:%c 工号:%d 密码:%s\n",tch[t].num,tch[i].name,tch.sex[i],tch.id[i],tch.key[i]);
		}
	}
	fclose(fwp);
	FILE* fwp1=fopen("离职教师.txt","w+");
	for(int i=0;i<100;i++)
	{
		if(l_tch.sex[i]=='w' || l_tch.sex[i]=='m')
		{
			
			fprintf(fwp1,"姓名:%s 性别:%c 工号:%d",l_tch[i].name,l_tch[i].sex,l_tch[i].id);
		}
	}
	fclose(fwp1);
}

