#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	string a,t,ans;
	int i,e;
	cin>>a;
	t=ans="";
	int epos=a.find('E');
	if(a[0]=='-') ans+='-';
	if(a[epos+1]=='-')
	{
		t=a.substr(epos+2);
		sscanf(t.c_str(),"%d",&e);
		ans+="0.";
		for(i=1;i<e;i++)
		{
			ans+="0";
		}
		ans+=a[1];
		ans+=a.substr(3,epos-3);
	}else
	{
		t=a.substr(epos+2);
		sscanf(t.c_str(),"%d",&e);
		if(e>=epos-3)
		{
			ans+=a[1];
			ans+=a.substr(3,epos-3);
			for(i=0;i<e-epos+3;i++)
				ans+="0";
		}else
		{
			ans+=a[1];
			ans+=a.substr(3,e);
			ans+=".";
			ans+=a.substr(3+e,epos-3-e);
		}
	}
	cout<<ans<<endl;

	return 0;
}
