#include<stdio.h>
#include<ctype.h>


int main()
{
    int c;
    for(;;){
        c = fgetc(stdin);
        if (c == EOF){
            break;
        }
        if (isdigit(c)){ //条件はman isalphaで使えそうな関数
            c = '*';
        }
        fputc(c, stdout);
    }
    return 0;
}