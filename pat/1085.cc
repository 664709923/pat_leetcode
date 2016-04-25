#include<stdio.h>
#include<algorithm>

#define ll long long

using namespace std;

int main()
{
	ll i,j,n,p,M,m,ans=1;
	scanf("%lld%lld",&n,&p);
	ll num[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num[i]);
	}
	sort(num,num+n);
	for(i=0;i<n;i++)
	{
		for(j=i+ans;j<n;j++)	//核心，j=i+ans为了找到更长的，则比已有结果短的直接跳过
		{
			if(num[j]<=num[i]*p)
			{
				ans=(j-i+1>ans?j-i+1:ans);
			}else
			{
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
