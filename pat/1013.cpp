#include<iostream>

using namespace std;

bool *a = new bool[1000000];
int *sushu = new int[10001];
int main()
{
	int m,n,i,j;
    int num=0;
    cin>>m>>n;

    for(i=2; i<1000000; i++)
    {
        a[i]=true;
    }

    for(i=2; i<=1000; i++)
    {
        if(a[i])
        {
            for(j=i*i; j<1000000; j+=i)
            {
                a[j]=false;
            }
        }
    }

    for(i=2; i<1000000; i++)
    {
		if(num>9999)
		{
			break;
		}
        if(a[i])
        {
			num++;
            sushu[num]=i;
        }
    }

    for(i=m;i<=n;i++)
	{
		if((i-m)%10==0)
		{
			cout<<sushu[i];
		}else
		if((i-m)%10==9)
		{
			cout<<" "<<sushu[i]<<endl;
		}else
		cout<<" "<<sushu[i];
	}
    return 0;
}
