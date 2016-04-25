#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>

using namespace std;


int i,n;
int bets[100010];
int flag[100010];
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>bets[i];
		flag[bets[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(flag[bets[i]]==1)
		{
			cout<<bets[i]<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}
