#include<iostream>
#include<stdio.h>
using namespace std;


void f(int * &x)
{
    *x=20;
    int *b=new int(50);
    x=b;
}

int main()
{
	int a=10;
	int* x=&a;
	f(x);
    printf("%d\n",a);
    printf("%d\n",*x);

	int bb=-1%5;
	printf("%d",bb);

    return 0;
}
