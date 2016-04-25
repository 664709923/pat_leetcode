#include<math.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define MAX 100005
using namespace std;

vector<int> tree[MAX];
queue<int> q;
int ans=0;
int num[MAX];
void BFS(int root)
{
	int cur,last;
	q.push(root);
	last=q.back();
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(int i=0;i<tree[cur].size();i++)
		{
			q.push(tree[cur][i]);
		}
		if(cur==last)
		{
			num[++ans]=q.size();
			last=q.back();
		}
	}
}

int main()
{
	int root,i,n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp==-1)
			root=i;
		else
		{
			tree[temp].push_back(i);
		}
	}
	num[0]=1;
	BFS(root);
	printf("%.2lf %d\n",p*pow((100+r)/100,ans-1),num[ans-1]);
	return 0;
}

