//计算连通分量数
//万能层次遍历，解决树或图的问题
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 10005

using namespace std;

vector<int> tree[MAX];
bool visited[MAX];
queue<int> q;
int root_deep[MAX];
int deep=0;

void BFS(int root)
{
	//memset(visited,false,sizeof(visited));
	deep=0;
	visited[root]=true;
	int cur,last;
	q.push(root);
	last=q.back();
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(int i=0;i<tree[cur].size();i++)
		{
			int temp=tree[cur][i];
			if(!visited[temp])
			{
				visited[temp]=true;
				q.push(tree[cur][i]);
			}
		}
		if(cur==last)
		{
			deep++;
			last=q.back();
		}
	}
	root_deep[root]=deep;
}

int main()
{
	int i,n,connected_components=0;
	int a,b;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			BFS(i);
			connected_components++;
		}
	}
	if(connected_components>1)
	{
		cout<<"Error: "<<connected_components<<" components"<<endl;
		return 0;
	}
	int maxdeep=0;
	for(i=1;i<=n;i++)
	{
		memset(visited,false,sizeof(visited));
		BFS(i);
		maxdeep=root_deep[i]>maxdeep?root_deep[i]:maxdeep;
	}
	for(i=0;i<=n;i++)
	{
		if(root_deep[i]==maxdeep)
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
