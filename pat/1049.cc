#include<string>
#include<iostream>

using namespace std;

int count1(int n)
{
	int ans=0;
	while(n)
	{
		if(n%10==1) ans++;
		n/=10;
	}
	return ans;
}

int countOnes(int n)
{
	switch(n)
	{
		case 1:return 1;
		case 2:return 1;
		case 3:return 1;
		case 4:return 1;
		case 5:return 1;
		case 6:return 1;
		case 7:return 1;
		case 8:return 1;
		case 9:return 1;
		case 10:return 2;
		case 11:return 4;
		case 12:return 5;
		case 13:return 6;
		case 14:return 7;
		case 15:return 8;

	}
	return count1(n)+countOnes(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<countOnes(n)<<endl;
	return 0;
}
