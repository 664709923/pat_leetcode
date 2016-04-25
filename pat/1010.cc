#include<iostream>
#include<string>

using namespace std;

string n1,n2;
int tag,rad;

int toDecimal(string s,int radix)
{
	int l = s.size();
	int ans=0;
	for(int i=0;i<l;i++)
	{
		ans*=radix;
		if(s[i]>='0'&&s[i]<='9')
			ans+=s[i]-'0';
		if(s[i]>='a'&&s[i]<='z')
			ans+=s[i]-'a'+10;
	}
	return ans;
}

int main()
{
	int i,left;
	cin>>n1>>n2>>tag>>rad;
	if(n1==n2)
	{
		cout<<rad<<endl;
		return 0;
	}
	if(tag==1)
	{
		left=toDecimal(n1,rad);
		for(i=2;i<36;i++)
		{
			if(toDecimal(n2,i)==left)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}else
	{
		left=toDecimal(n2,rad);
		for(i=2;i<36;i++)
		{
			if(toDecimal(n1,i)==left)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
