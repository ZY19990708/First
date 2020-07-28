
int stu_reset(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("请输入学生学号\n");
	int id,key;
	int i=0;
	scanf("%d",&id);
	while(id!=stu_id[i] && i<100)
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
	scanf("%d",&key);
	stu_key[i]=key;
	printf("修改成功！\n")
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
		while(stu_id)
		{
			printf("%s %s %d %d %d %d\n",stu_name,stu_sex,stu_id,stu_chinese,stu_math,stu_english);
			}
		}
void stu_show_out(void)
{
	system("clear");
	printf("----------教师管理系统----------\n");
	FILE *fp=fopen("tuuixue.txt","r");
	char name[100][20]={0};
	char sex[100]{0};
	int id[100]={0};
	int chinese[100]={0};
	int math[100]={0};
	int english[100]={0};
	int i=0;
	while(!feod(fp))
	{
		fscanf(fp,"%s %s %d %d %d %d",name[i],sex[i],&id[i],&chinese[i],&math[i],&english[i]);
		printf("%s %s %d %d %d %d\n",name[i],sex[i],id[i],chinese[i],math[i],english[i]);
		}
	}
