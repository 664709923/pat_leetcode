#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>

using namespace std;

int n,k,m;
int full[6];
struct student
{
	bool flag[6];
	int id;
	int score[6];
	bool canShow;
	int sum;
	int rank;
	int perfect;
	student()
	{
		for(int i=0;i<6;i++)
			score[i]=-1;
	}
	void print()
	{
		printf("%d %05d %d",rank,id,sum);
		for(int i=1;i<=k;i++)
		{
			if(score[i]==-1)
			{
				printf(" -");
			}else
			{
				printf(" %d",score[i]);
			}
		}
		printf("\n");
	}
}s[10005];

bool cmp(const student &a,const student &b)
{
	if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
	else return a.id<b.id;
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&full[i]);
	}
	int id,pid,pscore;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&id,&pid,&pscore);
		s[id].id=id;
		if(pscore!=-1) s[id].canShow=true;
		else pscore=0;
		s[id].score[pid]=s[id].score[pid]>pscore?s[id].score[pid]:pscore;
		if(pscore==full[pid]) s[id].perfect++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			s[i].sum+=s[i].score[j]>=0?s[i].score[j]:0;
		}
	}

	vector<student> v;
	for(i=1;i<=n;i++)
	{
		if(s[i].canShow) v.push_back(s[i]);
	}

	sort(v.begin(),v.end(),cmp);
	v[0].rank=1;
	for(i=1;i<=n;i++)
	{
		if(v[i].sum==v[i-1].sum) v[i].rank=v[i-1].rank;
		else v[i].rank=i+1;
	}

	for(i=0;i<v.size();i++)
	{
		v[i].print();
	}
	return 0;
}
