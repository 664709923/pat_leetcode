#include<stdio.h>

int main()
{
	int t,a,b,c,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		float x;
		scanf("%d%d%d",&a,&b,&c);
		printf("Case #%d: %s\n",i,(a+b>c ? "true" : "false"));
	}
	return 0;
}