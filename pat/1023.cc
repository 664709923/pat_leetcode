#include<string>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

void rever(char * a)
{
	int l=strlen(a);
	for(int i=0;i<l/2;i++)
	{
		char temp=a[i];
		a[i]=a[l-1-i];
		a[l-1-i]=temp;
	}
}

char a[30],b[30],c[30];
int main()
{
	int i,l;
	char temp;
	scanf("%s",a);
	l=strlen(a);
	rever(a);
	char carry='0';
	for(i=0;i<l;i++)
	{
		b[i]=(a[i]-'0')*2%10+carry;
		carry=(a[i]-'0')*2/10+'0';
	}
	if(carry=='1')
	{
		b[i]='1';
		b[i+1]='\0';
	}
	rever(b);
	if(strlen(b)>strlen(a))
	{
		printf("No\n");
		printf("%s\n",b);
		return 0;
	}
	strcpy(c,b);
	sort(a,a+strlen(a));
	sort(c,c+strlen(c));
	if(strcmp(a,c)==0)
	{
		printf("Yes\n");
		printf("%s\n",b);
	}else
	{
		printf("No\n");
		printf("%s\n",b);
	}
	return 0;
}

