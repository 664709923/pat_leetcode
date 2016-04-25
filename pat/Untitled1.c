#include<stdio.h>

int main(){

	char c, ch;
	c=getch();     /*从键盘上读入一个字符不回显送给字符变量c*/
    putchar(c);    /*输出该字符*/
    ch=getche();   /*从键盘上带回显的读入一个字符送给字符变量ch*/
    putchar(ch);
    return 0;
}
