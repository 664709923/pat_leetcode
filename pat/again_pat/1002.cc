#include<stdio.h>

using namespace std;

double coe[1001];

int main()
{
    int m1,m2;
    int c;
    scanf("%d", &c);
    for(int i=0;i<c;i++)
    {
        int exp;
        double t;
        scanf("%d %lf",&exp,&t);
        coe[exp] = t;
        if(i==0) m1 = exp;
    }

    scanf("%d", &c);
    for(int i=0;i<c;i++)
    {
        int exp;
        double t;
        scanf("%d %lf",&exp,&t);
        coe[exp] += t;
        if(i==0) m2 = exp;
    }

    int cnt = 0;
    for(int i=0;i<1001;i++){
            if(coe[i]!=0) cnt++;
    }


    int mm = m1>m2? m1:m2;

    printf("%d", cnt);
    for(int i=mm;i>=0;i--)
    {
        if(coe[i] != 0) printf(" %d %.1lf", i,coe[i]);
    }
    return 0;
}
