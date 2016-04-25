#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>

//#define DEBUG

using namespace std;

char a[20], b[20];
int tag, radix;

int getInt(char a){
    if(a > '9'){
        return a - 'a' + 10;
    }
    return a - '0';
}

int getDecimal(char* num, int len, int radix){
    int real = 0;
    for(int i = 0; i < len; i++){
        real += getInt(num[i]) * pow(radix, len-i-1);
    }
    return real;
}



int main(){
    int real;

    cin>>a>>b>>tag>>radix;
    if(tag == 2){
        char temp[20];
        strcpy(temp, b);
        strcpy(b, a);
        strcpy(a, temp);
    }

    real = getDecimal(a, strlen(a), radix);

    int i = 2;
    while(i){
        #ifdef DEBUG
        cout<<"i:"<<i<<"  getD:"<<getDecimal(b, strlen(b), i)<<endl;
        #endif
        if(getInt(b[0]) * pow(i, strlen(b)-1) > real){
            cout<<"Impossible"<<endl;
            return 0;
        }
        if(getDecimal(b, strlen(b), i) == real){
            cout<<i<<endl;
            return 0;
        }
        i++;
    }

    return 0;
}
