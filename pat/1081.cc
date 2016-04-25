#include<stdio.h>
#include<algorithm>
#define ll long long int

using namespace std;


void print(ll up,ll down)
{
	if(up==0)
	{
		printf("0");
		return;
	}
	int f=up>0?1:-1;
	up=abs(up);
	down=abs(down);
	if(up>=down)
	{
		printf("%lld",up/down*f);
		if(up%down) printf(" %lld/%lld",up%down,down);
	}else
	{
		printf("%lld/%lld",f*up,down);
	}
}

ll gcd(ll a,ll b)
{
	a=abs(a),b=abs(b);
	return b!=0?gcd(b,a%b):a;
}

int main()
{
	ll up[110],down[110];
	int i,n;
	ll gc,tup,tdown;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld/%lld",&up[i],&down[i]);
		gc=gcd(up[i],down[i]);
		up[i]/=gc;
		down[i]/=gc;
	}

	tup=0;
	tdown=1;
	for(i=0;i<n;i++)
	{
		tup=tup*down[i]+up[i]*tdown;
		tdown=tdown*down[i];
		gc=gcd(tup,tdown);
		tup/=gc;
		tdown/=gc;
	}

	print(tup,tdown);

	return 0;
}
