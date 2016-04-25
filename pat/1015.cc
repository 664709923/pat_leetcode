#include<iostream>
#include<stdio.h>

using namespace std;

bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int n,d;
	while(cin>>n)
	{
		if(n<0) return 0;
		else
		{
			cin>>d;
			if(isPrime(n))
			{
				int ans=0;
				while(n)
				{
					ans*=d;
					ans+=n%d;
					n/=d;
				}
				if(isPrime(ans))
				{
					printf("Yes\n");
					continue;
				}
			}
			printf("No\n");
		}
	}
	return 0;
}
