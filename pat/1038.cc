#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#define MAX 10005
using namespace std;

string num[MAX];
int n;

bool cmp(const string a,const string b)
{
	string c=a+b;
	string d=b+a;
	return c<d;
}

int main()
{
	int i;
	int leading;
	cin>>n;
	bool flag=true;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(i=0;i<n;i++)
	{
		sscanf(num[0].c_str(),"%d",&leading);
		if(leading!=0) flag=false;
	}
	if(flag)
	{
		cout<<"0"<<endl;
		return 0;
	}
	sort(num,num+n,cmp);

	sscanf(num[0].c_str(),"%d",&leading);
	if(leading) cout<<leading;
	for(int i=1;i<n;i++)
	{
		cout<<num[i];
	}
	cout<<endl;
	return 0;
}
