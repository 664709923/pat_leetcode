#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

class Student
{
	public:
	string id;
	int acme_score[4];
	int acme_rank[4];
	Student(){}
	void setStudent(string src_id,int c,int m,int e)
	{
		id=src_id;
		acme_score[1]=c;
		acme_score[2]=m;
		acme_score[3]=e;
		acme_score[0]=c+m+e;
		acme_rank[0]=1;
		acme_rank[1]=1;
		acme_rank[2]=1;
		acme_rank[3]=1;
	}
};

char Rank[4]={'A','C','M','E'};

int main()
{
	int i,j,k,n,m;
	string id;
	int a,b,c;
	cin>>n>>m;
	Student s[n];
	for(i=0;i<n;i++)
	{
		cin>>id>>a>>b>>c;
		s[i].setStudent(id,a,b,c);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<4;k++)
			{
				if(s[j].acme_score[k]>s[i].acme_score[k])
				{
					s[i].acme_rank[k]++;
				}
			}
		}
	}

//	for(i=0;i<n;i++)
//	{
//		printf("ID:%s,a:%d,c:%d,m:%d,e:%d\n",s[i].id.c_str(),s[i].acme_score[0],s[i].acme_score[1],s[i].acme_score[2],s[i].acme_score[3]);
//		printf("rank: %d,%d,%d,%d\n\n",s[i].acme_rank[0],s[i].acme_rank[1],s[i].acme_rank[2],s[i].acme_rank[3]);
//	}

	string xid;
	while(m--)
	{
		bool flag=true;
		cin>>xid;
		for(i=0;i<n;i++)
		{
			if(xid==s[i].id)
			{
				flag=false;
				int temp=0;
				for(j=1;j<4;j++)
				{
					if(s[i].acme_rank[j]<s[i].acme_rank[temp])
					{
						temp=j;
					}
				}
				cout<<s[i].acme_rank[temp]<<" "<<Rank[temp]<<endl;
				break;
			}
		}
		if(flag)
		{
			cout<<"N/A"<<endl;
		}
	}
	return 0;
}
