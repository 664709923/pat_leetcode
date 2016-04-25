#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

bool increase(int a,int b)
{
	return a<b;
}

bool decrease(int a,int b)
{
	return a>b;
}

int main()
{
	int m,n;
	cin>>m;
	char num[6];
	sprintf(num,"%04d",m);
	sort(num,num+4,decrease);
	if(num[0]==num[3])
	{
		printf("%s - %s = 0000\n",num,num);
		return 0;
	}
	else
	{
		do
		{
			sort(num,num+4,decrease);
			sscanf(num,"%d",&m);
			sort(num,num+4,increase);
			sscanf(num,"%d",&n);
			printf("%04d - %04d = %04d\n",m,n,m-n);
			sprintf(num,"%04d",m-n);
		}while(strcmp(num,"6174")!=0);


	}
	return 0;
}
