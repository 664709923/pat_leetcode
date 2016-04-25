#include<stdio.h>
#include<vector>

#define IMAX 0x7fffffff
#define MAX 510

using namespace std;

int matrix[MAX][MAX];
int rescue[MAX];
int dist[MAX];

bool mark[MAX];

int n,m,s,e; //n顶点个数，m边数
int cnt[MAX]; //源点到每个点的最短路径条数
int hands[MAX]; //源点到每个点的最大人手数
int now;

void input()
{
    freopen("1003.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&rescue[i]);
        mark[i] = false;
        dist[i] = IMAX;
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = IMAX;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int v1, v2, e;
        scanf("%d%d%d", &v1, &v2, &e);
        matrix[v1][v2] = e;
        matrix[v2][v1] = e;
    }
}

void dijkstra(int first, int last)
{
    dist[first] = 0;
    cnt[first] = 1;
    hands[first] = rescue[first];

    now = first;
    mark[now] = true;
    for(int i = 1; i < n; i++)
    {
        //更新
        for(int j = 0; j < n; j++)
        {
            if(!mark[j] && matrix[now][j] < IMAX)
            {
                if(dist[j] > dist[now] + matrix[now][j])
                {
                    dist[j] = dist[now] + matrix[now][j];
                    hands[j] = hands[now] + rescue[j];
                    cnt[j] = cnt[now];
                }else if(dist[j] == dist[now] + matrix[now][j])
                {
                    cnt[j] += cnt[now];
                    if(hands[j] < hands[now] + rescue[j])
                    {
                        hands[j] = hands[now] + rescue[j];
                    }
                }
            }
        }

        //找出最小值
        int mindist = IMAX;
        for(int j = 0; j < n; j++)
        {
            if(!mark[j] && dist[j] < mindist)
            {
                mindist = dist[j];
                now = j;
            }
        }
        mark[now] = true;
        if(now == last)
        {
            return;
        }
    }
}

int main()
{
    input();

    dijkstra(s,e);
    printf("%d %d\n", cnt[e], hands[e]);
    return 0;
}
