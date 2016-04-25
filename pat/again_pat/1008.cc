#include<stdio.h>

int main()
{
    int n;
    int pre = 0,cur;
    scanf("%d", &n);
    int sum = 5*n;
    while(n--)
    {
        scanf("%d", &cur);
        int dis = cur - pre;
        sum += dis>0 ? 6*dis : -4*dis;
        pre = cur;
    }
    printf("%d", sum);

    return 0;
}
