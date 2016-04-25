#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int n;

bool isSame(int a[],int b[])
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
	return true;
}

int main()
{
	int i,j;
	cin>>n;
	int ori[n],jud[n],temp[n];
	for(i=0;i<n;i++)
	{
		cin>>ori[i];
		temp[i]=ori[i];
	}
	for(i=0;i<n;i++)
		cin>>jud[i];


	//judge Insert
	for(i=2;i<=n;i++)
	{
		sort(ori,ori+i);
		if(isSame(ori,jud))
		{
			printf("Insertion Sort\n");
			sort(ori,ori+i+1);
			printf("%d",ori[0]);
			for(i=1;i<n;i++)
			{
				printf(" %d",ori[i]);
			}
			return 0;
		}
	}

	//judge Merge
	for(i=2;i<n;i*=2)
	{
		for(j=0;j<n/i;j++)
		{
			sort(temp+j*i,temp+j*i+i);
		}
		if(n%i)
		{
			sort(temp+n/i*i,temp+n);
		}
		if(isSame(temp,jud))
		{
			printf("Merge Sort\n");
			i*=2;
			for(j=0;j<n/i;j++)
			{
				sort(temp+j*i,temp+j*i+i);
			}
			if(n%i)
			{
				sort(temp+n/i*i,temp+n);
			}
			printf("%d",temp[0]);
			for(i=1;i<n;i++)
			{
				printf(" %d",temp[i]);
			}
			return 0;
		}
	}
	return 0;
}
