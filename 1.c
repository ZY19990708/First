#include<stdio.h>
int sushu(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return 0;
		}
		
	}
	return 1;
}
int main()
{
	int n=0,id=0,idc=0,c=0,a[10001]={0},b[10001]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i]=scanf("%d",&id);
		printf("%d\n",a[i]);
	}
	scanf("%d",&c);
	for(int j=1;j<=c;j++)
	{
		b[j]=scanf("%d",&idc);
		printf("%d\n",b[j]);
	}
	for(int k=1;k<=c;k++)
	{
		int flag=0;
		for(int m=1;m<=n;m++)
		{
			if(a[m]==b[k])
			{
				if(m==1)
				{
					printf("%4d: Myster Award\n",b[k]);
					
					//a[m]=Checked;
				}
				else if(m==2 || sushu(m) )
				{
					printf("%4d: Minion\n",b[k]);
					//a[m]=Checked;

				}
				else
				{
					printf("%4d: Chocolate\n",b[k]);
					//a[m]=Checked;
				}
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("%4d: Are you kidding?\n",b[k]);
		}
	}

}
