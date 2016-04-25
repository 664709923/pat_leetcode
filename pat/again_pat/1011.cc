#include<stdio.h>

int main()
{
    double result = 1;
    int resulti = 0;
    int i;
    double m = 0, m2 = 0, m3 = 0;
    double tmp;
    char ch[3]={'W','T','L'};
    int cnt = 3;
    while(cnt--)
    {
        for(i = 0; i < 3; i++)
        {
            scanf("%lf", &tmp);
            if(tmp > m)
            {
                m = tmp;
                resulti = i;
            }
        }
        printf("%c ", ch[resulti]);
        result *= m;
        m=0;
    }


    printf("%.2lf", (result*0.65-1)*2);

    return 0;
}
