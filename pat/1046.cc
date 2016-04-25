#include<iostream>
#include<stdio.h>
using namespace std;

int dis[100010];
int main()
{
	int n,m,i,sum=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		sum+=temp;
		dis[i+1]=sum;
	}
	scanf("%d",&m);
	while(m--)
	{
		ans=0;
		int s,e;
		scanf("%d%d",&s,&e);
		if(s>e)
		{
			ans=dis[s]-dis[e];
		}else
		{
			ans=dis[e]-dis[s];
		}
		printf("%d\n",ans<sum-ans?ans:sum-ans);
	}
	return 0;

}
