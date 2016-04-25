#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<math.h>
#include<stdio.h>
#define MAX 100010

using namespace std;

int n;
double p,r;
int level=0;
int leaves[MAX];
int retailer[MAX];
vector<int> tree[MAX];
queue<int> q;

void BFS(int root)
{
	int i,cur,last;
	q.push(root);
	last=q.back();
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(tree[cur].empty())
		{
			leaves[level]+=retailer[cur];
		}else
		{
			for(i=0;i<tree[cur].size();i++)
			{
				q.push(tree[cur][i]);
			}
		}
		if(cur==last)
		{
			level++;
			last=q.back();
		}
	}
}

int main()
{
	int i,j;
	int k,son;
	cin>>n>>p>>r;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k)
		{
			for(j=0;j<k;j++)
			{
				cin>>son;
				tree[i].push_back(son);
			}
		}else
		{
			cin>>retailer[i];
		}
	}
	BFS(0);
	double ans=0;
	for(i=0;i<level;i++)
	{
		if(leaves[i])
		{
			ans+=leaves[i]*pow((100+r)/100,i)*p;
		}

	}
	printf("%.1lf",ans);
	return 0;
}
