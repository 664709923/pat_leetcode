#include<stdio.h>

int myhash[1<<24];
int main()
{
	int i,m,n,num;
	scanf("%d%d",&m,&n);
	for(i=0;i<m*n;i++)
	{
		scanf("%d",&num);
		myhash[num]++;
	}
	for(i=0;i<1<<24;i++)
	{
		if(myhash[i]>m*n/2)
		{
			printf("%d",i);
		}
	}
	return 0;
}
