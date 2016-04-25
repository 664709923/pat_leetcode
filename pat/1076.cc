#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX 1005

using namespace std;

int n,l;
vector<int> tree[MAX];
bool visited[MAX];
queue<int> q;

int BFS(int root)
{
	memset(visited,false,sizeof(visited));
	int i,j,k;
	int cur,last,level=0,ans=0;
	while(!q.empty()) q.pop();
	visited[root]=true;
	q.push(root);
	last=q.back();
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		for(i=0;i<tree[cur].size();i++)
		{
			if(!visited[tree[cur][i]])
			{
				q.push(tree[cur][i]);
				visited[tree[cur][i]]=true;
			}
		}
		if(cur==last)
		{
			level++;
			ans+=q.size();
			if(!q.empty()) last=q.back();
			if(level==l) return ans;
		}
	}
	return ans;
}

int main()
{
	int i,j,k;
	int ouxiangshu,ouxiang;
	cin>>n>>l;
	for(i=1;i<=n;i++)
	{
		cin>>ouxiangshu;
		for(j=0;j<ouxiangshu;j++)
		{
			cin>>ouxiang;
			tree[ouxiang].push_back(i);
		}
	}
	cin>>k;
	while(k--)
	{
		int root;
		cin>>root;
		cout<<BFS(root)<<endl;
	}
	return 0;
}
