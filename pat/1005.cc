#include<stdio.h>
#include<string.h>
char eng[10][10]={
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int main()
{
	char num[102];
	int i=0,ans=0;
	scanf("%s",num);
	for(i=0;i<strlen(num);i++)
	{
		ans+=num[i]-'0';
	}
	char Sans[5];
	int len=sprintf(Sans,"%d",ans);
	for(i=0;i<len;i++)
	{
		if(i==0)
		{
			printf("%s",eng[Sans[i]-'0']);
		}
		else
		{
			printf(" %s",eng[Sans[i]-'0']);
		}
	}
	printf("\n");
	return 0;
}
