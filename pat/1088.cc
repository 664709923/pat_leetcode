#include<stdio.h>
#include<algorithm>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	a=abs(a);
	b=abs(b);
	return b!=0 ? gcd(b,a%b) : a;
}

void print(long long up,long long down)
{
	if(up==0)
	{
		printf("0");
		return;
	}
	int f=up>0?1:-1;
	up=abs(up);
	down=abs(down);
	if(f==-1) printf("(");
	if(up>=down)
	{
		printf("%lld",up/down*f);
		if(up%down) printf(" %lld/%lld",up%down,down);
	}else
	{
		printf("%lld/%lld",f*up,down);
	}

	if(f==-1) printf(")");
}

int main()
{
	long long int a,b,c,d,tup,tdown,gc;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
	gc=gcd(a,b);
	a=a/gc;
	b=b/gc;
	gc=gcd(c,d);
	c=c/gc;
	d=d/gc;

	//+
	print(a,b);
	printf(" + ");
	print(c,d);
	printf(" = ");

	tup=a*d+b*c;
	tdown=b*d;
	gc=gcd(tup,tdown);
	tup=tup/gc;
	tdown=tdown/gc;
	print(tup,tdown);

	printf("\n");

	//-
	print(a,b);
	printf(" - ");
	print(c,d);
	printf(" = ");

	tup=a*d-b*c;
	tdown=b*d;
	gc=gcd(tup,tdown);
	tup=tup/gc;
	tdown=tdown/gc;
	print(tup,tdown);

	printf("\n");

	//*
	print(a,b);
	printf(" * ");
	print(c,d);
	printf(" = ");

	tup=a*c;
	tdown=b*d;
	gc=gcd(tup,tdown);
	tup=tup/gc;
	tdown=tdown/gc;
	print(tup,tdown);

	printf("\n");

	// /
	print(a,b);
	printf(" / ");
	print(c,d);
	printf(" = ");
	if(c==0)
	{
		printf("Inf\n");
	}else
	{
		tup=a*d;
		tdown=b*c;
		if(tdown<0)
		{
			tup=-tup;
			tdown=-tdown;
		}
		gc=gcd(tup,tdown);
		tup=tup/gc;
		tdown=tdown/gc;
		print(tup,tdown);
		printf("\n");
	}
	return 0;
}
