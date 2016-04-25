#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(char x,char y)
{
	return x>y;
}

int main()
{
	string a="asdf";
	string b="xzcv";
	swap(a,b);
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}
