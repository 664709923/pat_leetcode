#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

string week[7] = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
	};

int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int i,j;
	for(i=0;i<a.size();i++)
	{
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
		{
			printf("%s ",week[a[i]-'A'].c_str());
			break;
		}
	}
	for(i++;i<a.size();i++)
	{
		if(a[i]==b[i])
		{
			if(a[i]>='A'&&a[i]<='N')
			{
				printf("%02d:",a[i]-'A'+10);
				break;
			}
			if(a[i]>='0'&&a[i]<='9')
			{
				printf("%02d:",a[i]-'0');
				break;
			}
		}
	}

	for(i=0;i<c.size();i++)
	{
		if((c[i]==d[i])&&((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z')))
		{
			printf("%02d\n",i);
			break;
		}
	}
	return 0;
}

/*
34A5djDkxh4hhGE
29A5akDfkkkkggEdsb
s&hgsfdk
s&Hyscvnm


*/
