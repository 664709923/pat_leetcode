#include<string>
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


int main()
{
	int a,b,c,d,e,f,carry_a=0,carry_b=0,carry_c=0;
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&d,&e,&f);
	if(c+f>=29)
	{
		carry_c=1;
		c=(c+f)%29;
	}else{c+=f;}
	if(b+e+carry_c>=17)
	{
		carry_b=1;
		b=(b+e+carry_c)%17;
	}else{b+=e+carry_c;}	//之前错误，少加上carry_c
	a=a+d+carry_b;
	printf("%d.%d.%d",a,b,c);
	return 0;
}
