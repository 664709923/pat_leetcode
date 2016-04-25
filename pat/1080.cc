#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int app_num,sch_num,cho_num;
int quota[105];
vector<int> ans[105];
int lastRank[105];
class applicant
{
public:
	int id;
	int e_score;
	int i_score;
	int rank;
	vector<int> choices;
	void setApp(int i,int E,int I)
	{
		id=i;
		e_score=E;
		i_score=I;
	}
};

bool cmp(const applicant& a,const applicant& b)
{
	if(a.e_score+a.i_score!=b.e_score+b.i_score)
	{
		return a.e_score+a.i_score>b.e_score+b.i_score;
	}else
	{
		return a.e_score>b.e_score;
	}
}

applicant app[40005];

int main()
{
	int i,j,k;
	int E,I,temp;
	cin>>app_num>>sch_num>>cho_num;
	for(i=0;i<sch_num;i++)
	{
		cin>>quota[i];
	}
	for(i=0;i<app_num;i++)
	{
		cin>>E>>I;
		app[i].setApp(i,E,I);
		for(j=0;j<cho_num;j++)
		{
			cin>>temp;
			app[i].choices.push_back(temp);
		}
	}
	sort(app,app+app_num,cmp);

	app[0].rank=1;
	for(i=1;i<app_num;i++)
	{
		app[i].rank=i+1;
		if(app[i].e_score==app[i-1].e_score&&app[i].i_score==app[i-1].i_score)
		{
			app[i].rank=app[i-1].rank;
		}
	}

	for(i=0;i<app_num;i++)
	{
		int choice;
		for(j=0;j<app[i].choices.size();j++)
		{
			choice=app[i].choices[j];
			if(quota[choice])
			{
				quota[choice]--;
				ans[choice].push_back(app[i].id);
				if(quota[choice]==0)
				{
					lastRank[choice]=app[i].rank;
				}
				break;
			}else
			{
				if(app[i].rank==lastRank[choice])
				{
					ans[choice].push_back(app[i].id);
					break;
				}
			}
		}
	}
	for(i=0;i<sch_num;i++)
	{
		if(ans[i].empty())
		{
			cout<<endl;
		}else
		{
			sort(ans[i].begin(),ans[i].end());
			cout<<ans[i][0];
			for(j=1;j<ans[i].size();j++)
			{
				cout<<" "<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}


