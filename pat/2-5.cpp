#include<stdio.h>
#include<math.h>

int main()
{
	int n;

	while(scanf("%d",&n)!=EOF)
	{
		int *p=new int[n];
		double s=0,aver=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",p+i);
			aver+=p[i];
		}
		aver=aver/n;
		for(int i=0;i<n;i++)
		{
			s+=(p[i]-aver)*(p[i]-aver);
			//printf("%5f ",p[i]);
		}
		s=sqrt(s/n);
		printf("%.5f\n",s);
	}
	return 0;
}
