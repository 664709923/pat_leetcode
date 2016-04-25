#include<stdio.h>
#include<string.h>

using namespace std;

double result[1001];

int main()
{
	memset(result,0,sizeof(result));
	int na,nb;
	int i,m;
	double n;
	scanf("%d",&na);
	for(i = 0;i<na;i++)
	{
		scanf("%d%lf",&m,&n);
		result[m]+=n;
	}
	scanf("%d",&nb);
	for(i = 0;i<nb;i++)
	{
		scanf("%d%lf",&m,&n);
		result[m]+=n;
	}

	int sum=0;
	for(i=0;i<1001;i++)
	{
		if(result[i])
		{
			sum++;
		}
	}
	printf("%d",sum);
	for(i=1000;i>=0;i--)
	{
		if(result[i])
		{
			printf(" %d %.1lf",i,result[i]);
		}
	}
	printf("\n");
	return 0;

}
