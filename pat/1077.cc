#include<stdio.h>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>

#define maxsize 300
using namespace std;

int mmin(int *l,int n)
{
	int m=maxsize;
	for(int i=0;i<n;i++)
	{
		if(l[i]<m)
		{
			m=l[i];
		}
	}
	return m;
}

int main()
{
	int i,j,n;

	while(cin>>n)
	{
		getchar();
		char s[n][maxsize];
		int len[n];
		memset(len,0,sizeof(len));
		for(i=0;i<n;i++)
		{
			cin.getline(s[i],maxsize);
			len[i]=strlen(s[i]);
		}
		int cc=mmin(len,n);

		int temp,flag;
		for(i=1;i<=cc;i++)
		{
			flag=1;
			temp=s[0][len[0]-i];
			for(j=1;j<n;j++)
			{
				if(s[j][len[j]-i]!=temp)
				{
					flag=0;
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(i>1)
		{
			i--;
			for(j=i;j>0;j--)
			{
				if(j==1)	printf("%c\n",s[0][len[0]-j]);
				else printf("%c",s[0][len[0]-j]);
			}
		}
		else
		{
			printf("nai\n");
		}
	}

	return 0;
}
