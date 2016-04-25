#include<iostream>

using namespace std;

int main()
{
	int n,current=0,next,ans=0;
	cin>>n;
	ans+=5*n;
	while(n--)
	{
		cin>>next;
		if(next>current)
		{
			ans+=6*(next-current);
			current=next;
		}else
		{
			ans+=4*(current-next);
			current=next;
		}
	}
	cout<<ans<<endl;
	return 0;
}
