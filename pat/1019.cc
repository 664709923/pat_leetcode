#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i,n,d,l;
    cin>>n>>d;
    if(n==0)
    {
		printf("Yes\n0\n");
		return 0;
    }
    vector<int> temp;
    temp.clear();
    while(n)
    {
		temp.push_back(n%d);
		n/=d;
    }
    l=temp.size();
    for(i=0;i<l/2;i++)
    {
		if(temp[i]!=temp[l-i-1])
		{
			printf("No\n");
			printf("%d",temp[l-1]);
			for(i=l-2;i>=0;i--)
			{
				printf(" %d",temp[i]);
			}
			printf("\n");
			return 0;
		}
    }
    printf("Yes\n");
	printf("%d",temp[l-1]);
	for(i=l-2;i>=0;i--)
	{
		printf(" %d",temp[i]);
	}
	printf("\n");
	return 0;
}
