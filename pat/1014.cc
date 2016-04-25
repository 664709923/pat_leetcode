#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

queue<int> windows[25];
queue<int> beside;
vector<int> serveTime;

int n,m,k,q;

class time
{
public:
	int hour;
	int minute;
	void add(int n)
	{
		minute+=n;
		if(minute>=60)
		{
			minute%=60;
			hour++;
		}
	}
	bool isExceed()
	{
		if(hour>=17) return true;
		return false;
	}
	void print()
	{
		printf("%2d:%2d\n",hour,minute);
	}
};

int chooseWindow()
{
	int i,ans=0;
	for(i=1;i<=n;i++)
	{
		if(windows[i].size()==m) continue;
		if(windows[i].size()<ans)
		{
			ans=windows[i].size();
		}
	}
}

int main()
{
	int i,j;
	cin>>n>>m>>k>>q;
	for(i=1;i<=k;i++)
	{
		cin>>serveTime[i];
	}



	return 0;
}
