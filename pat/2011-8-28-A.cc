#include<stdio.h>
#include<string.h>
#define N 3

int main()
{
	double a[N][N];
	int result[N];
	char tr[N]={'W','T','L'};

	memset(a,0,sizeof(a));
	memset(result,0,sizeof(result));

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			if(a[i][result[i]]<a[i][j])
			{
				result[i]=j;
			}
		}
	}

	double sum=(a[0][result[0]]*a[1][result[1]]*a[2][result[2]]*0.65-1)*2;

	//sum=(sum*100+0.5)/100;   //不进行四舍五入反而可以了？？？
	printf("%c %c %c ",tr[result[0]],tr[result[1]],tr[result[2]]);
	printf("%.2lf\n",sum);
	return 0;
}
