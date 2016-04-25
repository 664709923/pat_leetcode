#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int c = a+b;
	if (c==0)
	{
		printf("0\n");
		return 0;
	}
	if(c<0)
	{
		printf("-");
		c=-c;
	}
	if(c>=1000000)
	{
        printf("%d,",c/1000000);
        printf("%03d,",c%1000000/1000);
        printf("%03d",c%1000);
        return 0;
	}
	if(c>=1000)
	{
        printf("%d,",c/1000);
        printf("%03d",c%1000);
        return 0;
	}
	printf("%d",c);

    return 0;
}
