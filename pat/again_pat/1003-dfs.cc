#include<stdio.h>
#include<vector>
#include<algorithm>

#define IMAX 0x7fffffff
#define MAX 510

using namespace std;

int matrix[MAX][MAX];
int hands[MAX];

bool visited[MAX];

int n,m,st,en; //n顶点个数，m边数

struct road{
    int handsum;
    int dissum;
}temp;

vector<road> ans;

bool cmp(road a, road b)
{
    if(a.dissum != b.dissum)
    {
        return a.dissum < b.dissum;
    }else
    {
        return a.handsum > b.handsum;
    }
}

void input()
{
    freopen("1003.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&st,&en);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&hands[i]);
    }

    for(int i = 0; i < m; i++)
    {
        int v1, v2, e;
        scanf("%d%d%d", &v1, &v2, &e);
        matrix[v1][v2] = e;
        matrix[v2][v1] = e;
    }
}

void DFS(int s, int e, int handsum, int dissum)
{
    if(s == e)
    {
        temp.handsum = handsum;
        temp.dissum = dissum;
        ans.push_back(temp);
    }else
    {
        //对与s相邻的所有结点进行DFS
        for(int i = 0; i < n; i++)
        {
            if(matrix[s][i] > 0 && !visited[i])
            {
                visited[i] = true;
                DFS(i, e, handsum + hands[i], dissum + matrix[s][i]);
                visited[i] = false;
            }
        }
    }
}


int main()
{
    input();

    if(n==1)
	{
		printf("1 %d\n",hands[0]);
		return 0;
	}

    visited[st] = true;
    DFS(st, en, hands[st], 0);

    sort(ans.begin(), ans.end(), cmp);

    int shorestCnt = 0;
    int shorest = ans[0].dissum;
    for(; ans[shorestCnt].dissum == shorest; shorestCnt++);
    printf("%d %d\n", shorestCnt, ans[0].handsum);
    return 0;
}
