#include<stdio.h>

char radix13[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#");
	printf("%c%c",radix13[a/13],radix13[a%13]);
	printf("%c%c",radix13[b/13],radix13[b%13]);
	printf("%c%c",radix13[c/13],radix13[c%13]);
	return 0;
}
