#include<iostream>

using namespace std;

int main()
{
    int a[14]={1,2,2,3,5,6,6,6,7,8,9,9,10,10};
    int c=0;
    for(int i=0;i<14;i++)
    {
        if(a[i]==a[i-1])
            c++;
		else a[i-c]=a[i];
    }
    for(int i=0;i<14-c;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
