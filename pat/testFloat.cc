#include<stdio.h>
#include<math.h>
int main()
{
	double i;
	for(i = 0;i-10 < 0.0000001 ;i += 0.1)
	{
		printf("%.1lf\n",i);
	}
	return 0;
}
