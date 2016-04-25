#include<string.h>
#include<stdio.h>

using namespace std;

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
    char num[110];
    int sum = 0;
    scanf("%s", num);
    for(int i = 0; i < strlen(num); i++)
    {
        sum += num[i] - '0';
    }
    char res[110];
    int len = sprintf(res, "%d", sum);

    printf("%s", eng[res[0] - '0']);
    for(int i = 1; i < len; i++)
    {
        printf(" %s", eng[res[i] - '0']);
    }
    return 0;
}
