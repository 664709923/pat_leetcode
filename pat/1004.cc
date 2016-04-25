#include<iostream>
#include<vector>
#include<queue>
#define MAX 110

using namespace std;
int nodes,non_leaf;
int leaves[MAX];
int level=0;
queue<int> q;
vector<int> tree[MAX];

void BFS(int root)
{
	int i;
	int cur,last;
	q.push(root);
	last=q.back();
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(tree[cur].empty())
		{
			leaves[level]++;
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
	int root=1,father,son_num,son;
	cin>>nodes>>non_leaf;
	for(i=0;i<non_leaf;i++)
	{
		cin>>father>>son_num;
		for(j=0;j<son_num;j++)
		{
			cin>>son;
			tree[father].push_back(son);
		}
	}
	BFS(root);
	cout<<leaves[0];
	for(i=1;i<level;i++)
	{
		cout<<" "<<leaves[i];
	}
	cout<<endl;
	return 0;
}
