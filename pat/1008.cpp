#include<stdio.h>

void rev(int *a,int len)
{
	int temp;
	for(int i=0;i<len/2;i++)
	{
		temp=*(a+len-i-1);
		*(a+len-i-1)=*(a+i);
		*(a+i)=temp;
	}
}

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	n=n%m;
	int *a = new int[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d",a+i);
	}
	rev(a,m);
	rev(a,n);
	rev(a+n,m-n);

	printf("%d",*a);
	for(int i=1;i<m;i++)
	{
		printf(" %d",*(a+i));
	}

	return 0;
}
