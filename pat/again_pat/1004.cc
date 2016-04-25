#include<vector>
#include<stdio.h>
#include<iostream>
#include<queue>


using namespace std;

int n,m;
vector<int> tree[105];
int level = 0;
int nochild[105];
queue<int> q;

void input()
{
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int v1, v2, cnt;
        scanf("%d%d", &v1, &cnt);
        for(int i = 0; i < cnt; i++)
        {
            scanf("%d", &v2);
            tree[v1].push_back(v2);
        }
    }
}

void BFS(int root)
{
    int cur, last;
    q.push(root);
    last = root;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        if(tree[cur].empty())
        {
            nochild[level]++;
        }else
        {
            for(int i = 0; i < tree[cur].size(); i++)
            {
                q.push(tree[cur][i]);
            }
        }
        if(cur == last)
        {
            level++;
            last = q.back();
        }
    }
}

int main()
{
    input();
    BFS(1);
    printf("%d",nochild[0]);
    for(int i = 1; i < level; i++)
    {
        printf(" %d", nochild[i]);
    }
    return 0;
}

