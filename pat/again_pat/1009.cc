#include<stdio.h>
#define MAX 2010

double a[MAX];
double b[MAX];
double c[MAX];

int ma,mb,mc;//a,b,c三个多项式指数的最高次数
int ca,cb,cc;//a,b,c三个多项式的项数

int i,j,k;

int main()
{
    scanf("%d", &ca);
    for(i = 0; i < ca; i++)
    {
        int exp;
        double coe;
        scanf("%d%lf", &exp, &coe);
        a[exp] = coe;
        if(i == 0)
        {
            ma = exp;
        }
    }

    scanf("%d", &cb);
    for(i = 0; i < cb; i++)
    {
        int exp;
        double coe;
        scanf("%d %lf", &exp, &coe);
        b[exp] = coe;
        if(i == 0)
        {
            mb = exp;
        }
    }

    mc = ma + mb;//两个多项式乘积得到的多项式，最高项指数即为原多项式最高项指数和

    for(i = 0; i <= ma; i++)
    {
        if(a[i] == 0){continue;}
        for(j = 0; j <= mb; j++)
        {
            if(b[j] == 0){continue;}
            c[i + j] += a[i] * b[j];
        }
    }

    for(i = 0; i <= mc; i++)
    {
        if(c[i] != 0)
        {
            cc++;
        }
    }
    printf("%d", cc);
    for(i = mc; i >= 0; i--)
    {
        if(c[i] != 0)
        {
            printf(" %d %.1lf", i, c[i]);
        }
    }

    return 0;
}
