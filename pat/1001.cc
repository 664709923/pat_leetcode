#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int x = a+b;
	if(x>-1000&&x<1000)
	{
		if(x>=0)
		{
			cout<<x<<endl;
		}
		else
		{
			x=-x;
			cout<<"-"<<x<<endl;
		}
	}
	if((x>-1000000&&x<=-1000)||(x>=1000&&x<1000000))
	{
		if(x>=0)
		{
			cout<<x/1000<<","<<setw(3)<<setfill('0')<<x%1000<<endl;
		}
		else
		{
			x=-x;
			cout<<"-"<<x/1000<<","<<setw(3)<<setfill('0')<<x%1000<<endl;
		}
	}
	if(x>=1000000||x<=-1000000)
	{
		if(x>=0)
		{
			cout<<x/1000000<<","<<setw(3)<<setfill('0')<<x/1000%1000<<","<<setw(3)<<setfill('0')<<x%1000<<endl;
		}
		else
		{
			x=-x;
			cout<<"-"<<x/1000000<<","<<setw(3)<<setfill('0')<<x/1000%1000<<","<<setw(3)<<setfill('0')<<x%1000<<endl;
		}
	}
	return 0;
}
