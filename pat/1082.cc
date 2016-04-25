#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

string number[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string wei[4]={"Qian","Bai","Shi",""};

void rev(string &s)
{
	int l=s.length();
	for(int i=0;i<l/2;i++)
	{
		char temp=s[i];
		s[i]=s[l-i-1];
		s[l-i-1]=temp;
	}
}

void read_fourBit(string s,bool isHighest)
{
	int temp;
	sscanf(s.c_str(),"%d",&temp);
	char tt[15];
	sprintf(tt,"%04d",temp);
	s=string(tt);
	int i;
	if(isHighest)
	{
		for(i=0;i<4;i++)
		{
			if(s[i]=='0')
				continue;
			else
			{
				if(i==3)
					cout<<number[s[i]-'0']<<" ";
				else
					cout<<number[s[i]-'0']<<" "<<wei[i]<<" ";
			}
		}
	}else
	{
		for(i=0;i<4;i++)
		{
			int flag=false;
			while(s[i]=='0')
			{
				flag=true;
			}
			if(flag) cout<<"ling ";
			if(s[i]!='0')
			{
				if(i==3)
					cout<<number[s[i]-'0']<<" ";
				else
					cout<<number[s[i]-'0']<<" "<<wei[i]<<" ";
			}
		}
	}

}

void read(int n)
{
	if(n<0)
	{
		cout<<"Fu ";
		n=-n;
	}
	char temp[15];
	sprintf(temp,"%d",n);
	string num(temp);

	//rev(num);
	int l=num.length();
	if(l==9)
	{
		cout<<number[num[0]-'0']<<" "<<"Yi ";
		read_fourBit(num.substr(1,4),false);
		cout<<"Wan ";
		read_fourBit(num.substr(5,4),false);
	}else if(l>=5&&l<=8)
	{
		read_fourBit(num.substr(0,l-4),true);
		cout<<"Wan ";
		read_fourBit(num.substr(l-4,4),false);
	}else
	{
		read_fourBit(num,true);
	}
}


int main()
{
	int n;
	cin>>n;
	if(n==0)
	{cout<<"ling"<<endl;return 0;}
	read(n);
	return 0;
}
