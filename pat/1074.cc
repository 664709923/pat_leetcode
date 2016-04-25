#include<iostream>
#include<string>
#include<algorithm>
#define MAX 100010
using namespace std;

string head;
int n,k;
int realn=0;
struct node
{
	string addr;
	int data;
	string next;
}l[MAX];

void rev(node l[],int c)
{
	for(int i=0;i<c/2;i++)
	{
		node temp=l[i];
		l[i]=l[c-1-i];
		l[c-1-i]=temp;
	}
}

int main()
{
	int i,j;
	cin>>head>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>l[i].addr>>l[i].data>>l[i].next;
	}

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(l[j].addr==head)
			{
				realn++;
				head=l[j].next;
				node temp=l[j];
				l[j]=l[i];
				l[i]=temp;
				break;
			}
		}
		if(head=="-1") break;

	}

//	for(i=0;i<realn;i++)
//	{
//		cout<<l[i].addr<<" "<<l[i].data<<" "<<l[i].next<<endl;
//	}

	for(i=0;i<realn/k;i++)
	{
		rev(l+i*k,k);
	}

	for(i=0;i<realn-1;i++)
	{
		l[i].next=l[i+1].addr;
	}
	l[realn-1].next="-1";

	for(i=0;i<realn;i++)
	{
		cout<<l[i].addr<<" "<<l[i].data<<" "<<l[i].next<<endl;
	}
	return 0;
}
/*

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

*/
