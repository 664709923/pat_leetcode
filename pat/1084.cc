#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;


void upper(string &s)
{
	int i=0,l=s.length();
	for(i=0;i<l;++i)
	{
		if(s[i]>='a'&&s[i]<='z') s[i]=s[i]-'a'+'A';
	}
}

int main()
{
	int i,pos;
	string a,b,ans="";
	cin>>a>>b;
	upper(a);
	upper(b);
	for(i=0;i<b.length();i++)
	{
		pos=a.find(b[i]);
		while(pos!=string::npos)
		{
			a=a.erase(pos,1);
			pos=a.find(b[i]);
		}
	}
	for(i=0;i<a.length();i++)
	{
		if(ans.find(a[i])==string::npos)
		{
			ans+=a[i];
		}
	}

	cout<<ans<<endl;

	return 0;
}


//
//int main()
//{
//	char s1[100],s2[100];
//	bool flag[1000];
//	memset(flag,false,sizeof(flag));
//	scanf("%s%s",s1,s2);
//	upper(s1);
//	upper(s2);
//	int i=0,j=0,l=strlen(s1);
//	for(i=0,j=0;i<l;++i)
//	{
//		if(s1[i]!=s2[j])
//		{
//			if(!flag[s1[i]])
//			{
//				flag[s1[i]]=true;
//				printf("%c",s1[i]);
//			}
//		}else
//		{
//			++j;
//		}
//	}
//	return 0;
//}
