#include "tch_fun.h"
#include "sign.h"
#include "tch_tools.h"
#include "student.h"
int tch_num[100]={0};//判断老师是否第一次登录;
int tch_chance[100]={0};
struct teacher tch;
int main(int argc(),const char* argv[])
{
	while(0==tch_sign())
	{}
	tch_show();
	switch(getch())
	{
		case 1:stu_add();break;
		case 2:stu_del();break;
		case 3:stu_find();break;
		case 4:stu_modify();break;
		case 5:stu_score();break;
		case 6:
				while(0==stu_reset()){};break;
		case 7:tch_show_in();break;
		case 8:tch_show_out();break;
		case 9:return 0;
		}
	
	}
