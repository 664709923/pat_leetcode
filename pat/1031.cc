#include<string>
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


int main()
{
	string a;
	cin>>a;
	int l=a.size();
	int i,j,m,n,n1=2,n2=3,n3=2;
	for(m=l;m>=3;m--)
	{
		for(n=m;n>=2;n--)
		{
			if(n*2+m==l+2)
			{
				n1=n1<n?n:n1;
			}
		}
	}
	n3=n1;
	n2=l+2-n1*2;
	char ans[n1][n2];
	memset(ans,' ',sizeof(ans));
	for(i=0;i<n1;i++)
	{
		ans[i][0]=a[i];
		ans[i][n2-1]=a[l-i-1];
	}
	for(i=1;i<n2-1;i++)
	{
		ans[n1-1][i]=a[n1+i-1];
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
