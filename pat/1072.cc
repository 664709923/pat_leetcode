#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define MAX 1200

using namespace std;

int n,m,k,ds;
int matrix[MAX][MAX];

struct point
{
	int id;
	int mini;
	int sum;
	void print()
	{
		printf("G%d\n",id-n);
		printf("%.1lf %.1lf",(double)mini,(double)sum/n+0.05);
	}
};

vector<point> ans;

bool cmp(point a,point b)
{
	if(a.mini!=b.mini) return a.mini>b.mini;
	else if(a.sum!=b.sum) return a.sum<b.sum;
	else return a.id<b.id;
}

int main()
{
	memset(matrix,-1,sizeof(matrix));
	int i,j,kk;
	char s1[10],s2[10];
	int a,b,dis;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(i=0;i<k;i++)
	{
		scanf("%s%s%d",s1,s2,&dis);
		if(s1[0]<'0'||s1[0]>'9')
		{
			sscanf(s1+1,"%d",&a);
			a+=n;
		}else
		{
			sscanf(s1,"%d",&a);
		}

		if(s2[0]<'0'||s2[0]>'9')
		{
			sscanf(s2+1,"%d",&b);
			b+=n;
		}else
		{
			sscanf(s2,"%d",&b);
		}
		matrix[a][b]=matrix[b][a]=dis;
	}
	for(kk=1;kk<=n+m;kk++)
	{
		for(i=1;i<=n+m;i++)
		{
			for(j=1;j<=n+m;j++)
			{
				if(matrix[i][kk]==-1||matrix[kk][j]==-1) continue;
				if(matrix[i][j]==-1||matrix[i][kk]+matrix[kk][j]<matrix[i][j])
				{
					matrix[i][j]=matrix[i][kk]+matrix[kk][j];
				}
			}
		}
	}

	int minimium=-2;
	for(i=n+1;i<=n+m;i++)
	{
		minimium=matrix[i][1];
		int flag=true;
		for(j=2;j<=n;j++)
		{
			if(matrix[i][j]>ds||matrix[i][j]<0)
			{
				flag=false;
				break;
			}
			if(minimium>matrix[i][j])
			{
				minimium=matrix[i][j];
			}
		}
		if(flag)
		{
			point p;
			p.id=i;
			p.mini=minimium;
			p.sum=0;
			for(int l=1;l<=n;l++)
			{
				if(matrix[i][l]) p.sum+=matrix[i][l];
			}
			ans.push_back(p);
		}
	}
	if(ans.empty())
	{
		printf("No Solution\n");
		return 0;
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0].print();
	return 0;
}
