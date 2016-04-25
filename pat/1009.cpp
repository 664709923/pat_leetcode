#include<stdio.h>
#define maxsize 50

int main()
{
	char p[maxsize][80];
	int i=0;
	while(scanf("%s",p[i])!=EOF)
	{
		i++;
	}
	printf("%s",p[i-1]);
	for(int j=i-2;j>=0;j--)
	{
		printf(" %s",p[j]);
	}
	
	return 0;
}