#include<stdio.h>
#include<algorithm>

using namespace std;

int num[10010];

int main()
{
    int n;
    scanf("%d", &n);

    int f = -1,l = -1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if(num[i] >= 0 && f == -1)
        {
            f = i;
        }
        if(num[i] > 0)
        {
            l = i;
        }
    }

    if(f == -1)
    {
        printf("0 %d %d\n", num[0], num[n-1]);
        return 0;
    }
    if(l == -1)
    {
        printf("0 0 0\n");
        return 0;
    }

    int sum = 0,maxn = 0;
    int first,last;
    for(int i = f; i < l + 1; i++)
    {
        sum = 0;
        //if(num[i] < 0)
        //{
        //    continue;
        //}
        for(int j = i; j < l + 1; j++)
        {
            sum += num[j];
            if(sum > maxn)
            {
                first = i;
                last = j;
                maxn = sum;
            }
        }
    }
    printf("%d %d %d\n", maxn, num[first], num[last]);
    return 0;
}
