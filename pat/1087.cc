#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#define MAX 205

using namespace std;

struct road
{
	vector<int> path;
	int costSum;
	int happySum;
}temp;

vector<road> ans;
map<int,string> idToName;
map<string,int> nameToId;
map<int,int> idToHappy;
int startCity,endCity;
int matrix[MAX][MAX];
bool visited[MAX];
int n;

void DFS(int s,int e,int costSum,int happySum)
{
	if(s==e)
	{
		temp.costSum=costSum;
		temp.happySum=happySum;
		ans.push_back(temp);
	}else
	{
		for(int i=0;i<n;i++)
		{
			if(matrix[s][i]>0&&(!visited[i]))
			{
				temp.path.push_back(i);
				visited[i]=true;
				DFS(i,e,costSum+matrix[s][i],happySum+idToHappy[i]);
				visited[i]=false;
				temp.path.pop_back();
			}
		}
	}
}

bool cmp(const road &a,const road &b)
{
	int la=a.path.size(),lb=b.path.size();
	if(a.costSum!=b.costSum) return a.costSum<b.costSum;
	else if(a.happySum!=b.happySum) return a.happySum>b.happySum;
	else return a.happySum/la>b.happySum/lb;
}

int main()
{
	int i,k;
	int happy,cost;
	string s,e;
	cin>>n>>k>>s;
	idToName.insert(make_pair(0,s));
	nameToId.insert(make_pair(s,0));
	startCity=0;
	for(i=1;i<n;i++)
	{
		cin>>s>>happy;
		idToName.insert(make_pair(i,s));
		nameToId.insert(make_pair(s,i));
		idToHappy.insert(make_pair(i,happy));
		if(s=="ROM") endCity=i;
	}
	for(i=0;i<k;i++)
	{
		cin>>s>>e>>cost;
		matrix[nameToId[s]][nameToId[e]]=cost;
		matrix[nameToId[e]][nameToId[s]]=cost;
	}
	temp.path.push_back(0);
	DFS(0,endCity,0,0);
	sort(ans.begin(),ans.end(),cmp);
	cost=ans[0].costSum;
	int countX=1;
	for(;ans[countX].costSum==cost;countX++);
	cout<<countX<<" "<<ans[0].costSum<<" "<<ans[0].happySum<<" "<<ans[0].happySum/(ans[0].path.size()-1)<<endl;
	cout<<idToName[ans[0].path[0]];
	for(i=1;i<ans[0].path.size();i++)
		cout<<"->"<<idToName[ans[0].path[i]];
	cout<<endl;
	return 0;
}
