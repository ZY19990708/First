#include <getch.h>
#include "sign.h"
int main(int argc(),const char* argv[])
{
	tch_true[100]={0};
	while(0==tch_sign())
	{}
	tch_show();
	switch(getch())
	{
		case 1:tch_add();break;
		case 2:tch_del();break;
		case 3:tch_search();break;
		case 4:tch_revise();break;
		case 5:tch_input();break;
		case 6:
				while(0==stu_reset()){};break;
		case 7:tch_show_in();break;
		case 8:tch_show_put();break;
		case 9:return 0;
		}
	
	}
