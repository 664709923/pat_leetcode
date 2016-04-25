#include<iostream>

using namespace std;

int main()
{
    int a[6]={1,2,3,4,5,8};
    int b[6]={2,5,7,8,9,10};
    int c[12];
    int i=0,j=0,k=0;
    while(i<6&&j<6)
    {
        if(a[i]<=b[j])
        {
            c[k++]=a[i++];
        }
	    else
	    {
	        c[k++]=b[j++];
	    }
	}
	while(i<6)
	{
	    c[k++]=a[i++];
	}
	while(j<6)
	{
	    c[k++]=b[j++];
	}

	for(int i=0;i<12;i++)
	{
	    cout<<c[i]<<endl;
	}
}
