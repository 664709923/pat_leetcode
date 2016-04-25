#include<iostream>
#include<string>

using namespace std;

string howToWrite[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int Sum(string n)
{
	int sum=0;
	for(int i=0;i<n.length();i++)
	{
		sum+=n.at(i)-48;
	}
	return sum;
}

void WriteIt(int n)
{
	int i=0;
	int j=0;
	int a[4];
	while(n!=0)
	{
		a[i++]=n%10;
		n/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		if(j==i-1)
		{
			cout<<howToWrite[a[j]];
		}
		else
		{
			cout<<" "<<howToWrite[a[j]];
		}
	}
	cout<<endl;

}

int main()
{
	string n ;
	while(getline(cin,n))
	{
		WriteIt(Sum(n));
	}

}

