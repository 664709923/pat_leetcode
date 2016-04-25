#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int father[100000];
int level[100000];

int findLevel(int x)
{
	if(level[father[x]])
		return level[father[x]]+1;
	int level=1;
	while(father[x]!=-1)
	{
		level++;
		x=father[x];
	}
	return level;
}

int main()
{
	int i,n,ans=0,num=0;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(i=0;i<n;i++)
	{
		scanf("%d",&father[i]);
	}

	for(i=0;i<n;i++) level[i]=findLevel(i);
	for(i=0;i<n;i++) ans=ans>level[i]?ans:level[i];
	for(i=0;i<n;i++) if(level[i]==ans) num++;

	printf("%.2lf %d\n",p*pow((100+r)/100,ans-1),num);
	return 0;
}
