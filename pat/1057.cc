#include<stdio.h>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int ss[100010];
int top=0;
int increase[100010];

int peek()
{
	for(int i=0;i<top;i++)
	{
		increase[i]=ss[i];
	}
	sort(increase,increase+top);
	return top%2==1?increase[(top+1)/2-1]:increase[top/2-1];
}

int main()
{
	string oper;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",oper.c_str());
		switch(oper[1])
		{
			case 'o':
			{
				if(!top)
				{
					printf("Invalid\n");
				}else
				{
					printf("%d\n",ss[--top]);
				}
				break;
			}
			case 'u':
			{
				scanf("%d",&ss[top++]);
				break;
			}
			case 'e':
			{
				if(!top)
				{
					printf("Invalid\n");
				}else
				{
					printf("%d\n",peek());
				}
				break;
			}
		}

	}
	return 0;
}
