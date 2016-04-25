//1003 为了得到所有解，可以使用深度优先搜索
#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 505
using namespace std;

struct road
{
	int disSum;
	int handSum;
}temp;

bool cmp(const road &a,const road &b)
{
	if(a.disSum!=b.disSum)
	{
		return a.disSum<b.disSum;
	}else
	{
		return a.handSum>b.handSum;
	}

}

int n,m,startCity,endCity;
int matrix[MAX][MAX];
int hands[MAX];
vector<road> ans;
bool visited[MAX];
int shorest=1000000;
void DFS(int s,int e,int disSum,int handSum)
{
	if(s==e)
	{
		temp.disSum=disSum;
		temp.handSum=handSum;
		ans.push_back(temp);

	}else
	{
		for(int i=0;i<n;i++)
		{
			if(matrix[s][i]>0&&(!visited[i]))
			{
				visited[i]=true;
				DFS(i,e,disSum+matrix[s][i],handSum+hands[i]);
				visited[i]=false;
			}
		}
	}
}
int main()
{
	int i,s,e,dis;
	cin>>n>>m>>startCity>>endCity;
	for(i=0;i<n;i++)
	{
		cin>>hands[i];
	}
	if(n==1)
	{
		cout<<"1 "<<hands[0]<<endl;
		return 0;
	}

	for(i=0;i<m;i++)
	{
		cin>>s>>e>>dis;
		matrix[s][e]=dis;
		matrix[e][s]=dis;
	}
	visited[startCity]=true;
	DFS(startCity,endCity,0,hands[startCity]);
	sort(ans.begin(),ans.end(),cmp);
	int countx=1;
	int shortestN=ans[0].disSum;
	for(;ans[countx].disSum==shortestN;countx++);
	cout<<countx<<" "<<ans[0].handSum<<endl;
	return 0;
}
