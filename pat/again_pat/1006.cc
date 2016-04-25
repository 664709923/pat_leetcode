#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 100

using namespace std;

struct record{
    char id[20];
    char in[20];
    char out[20];
};

vector<record> records;

bool cmp1(record a, record b)
{
    return strcmp(b.in, a.in) > 0;
}

bool cmp2(record a, record b)
{
    return strcmp(a.out, b.out) > 0;
}


int main()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        record r;
        scanf("%s%s%s", r.id, r.in, r.out);
        records.push_back(r);
    }
    sort(records.begin(), records.end(), cmp1);
    printf("%s ", records[0].id);
    sort(records.begin(), records.end(), cmp2);
    printf("%s\n", records[0].id);
    return 0;
}
