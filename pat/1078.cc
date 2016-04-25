#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std;

bool isPrime(int n)
{
	if(n==0||n==1) return false;
	if(n==2) return true;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int getIt(int* hashTable,int Tsize,int key)
{
	int val=key%Tsize;
	if(hashTable[val]==key)
	{
		return val;
	}
	int i=0;
	int p=0;
	while(++i<Tsize/2)
	{
		p=(val+i*i+Tsize)%Tsize;
		if(hashTable[p]==key)
		{
			return p;
		}
		/*
		p=(val-i*i+Tsize)%Tsize;
		if(hashTable[p]==key)
		{
			return p;
		}
		*/
	}
	return -1;
}

void hashIt(int* hashTable,int Tsize,int key)
{
	int val=key%Tsize;
	if(hashTable[val]==0)
	{
		hashTable[val]=key;
	}
	else
	{
		int i=0;
		int p=0;
		while(++i<Tsize/2)
		{
			p=(val+i*i+Tsize)%Tsize;
			if(hashTable[p]==0)
			{
				hashTable[p]=key;
				return;
			}
			/*
			p=(val-i*i+Tsize)%Tsize;
			if(hashTable[p]==0)
			{
				hashTable[p]=key;
				return;
			}
			*/
		}
	}
}



int main()
{
	int Tsize,Nsize;
	scanf("%d%d",&Tsize,&Nsize);
	if(!isPrime(Tsize))
	{
		for(int i=Tsize+1;;i++)
		{
			if(isPrime(i))
			{
				Tsize=i;
				break;
			}
		}
	}
	int hashTable[Tsize];
	memset(hashTable,0,sizeof(hashTable));
	int nums[Nsize];
	for(int i=0;i<Nsize;i++)
	{
		scanf("%d",&nums[i]);
		hashIt(hashTable,Tsize,nums[i]);
	}

	int result=getIt(hashTable,Tsize,nums[0]);

	if(result==-1) printf("-");
	else printf("%d",result);

	for(int i=1;i<Nsize;i++)
	{
		result=getIt(hashTable,Tsize,nums[i]);
		if(result==-1) printf(" -");
		else printf(" %d",result);
	}

	return 0;
}

/*

6 6
10 6 4 15 11 9

6 6
10 6 4 15 5 11

*/
