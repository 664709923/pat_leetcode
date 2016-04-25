#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#define ll long long

using namespace std;

vector<ll> coupon;
vector<ll> product;

int main()
{
	int i,j;
	int nc,np;
	int tc,tp;
	int cf=0,pf=0;
	cin>>nc;
	for(i=0;i<nc;i++)
	{
		cin>>tc;
		coupon.push_back(tc);
	}
	cin>>np;
	for(i=0;i<np;i++)
	{
		cin>>tp;
		product.push_back(tp);
	}
	sort(coupon.begin(),coupon.end());
	sort(product.begin(),product.end());

	ll ans=0;
	for(i=0;i<nc&&i<np;i++)
	{
		if(coupon[i]<0&&product[i]<0)
		{
			ans+=coupon[i]*product[i];
		}
	}
	for(i=nc-1,j=np-1;i>=0&&j>=0;i--,j--)
	{
		if(coupon[i]>0&&product[j]>0)
		{
			ans+=coupon[i]*product[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
