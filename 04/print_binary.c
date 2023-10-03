#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

void prinnt_binary(uint32_t x)
{
    int first = 1;

    for (int i = 31; i >= 0; i--){
        //i番目の桁を表示する
        if(x & (1 << i)){
            putchar('1');
        }
        else{
            putchar('0');
        }
    }
    putchar('\n');
}
int main(){
    uint32_t x = 0xdeadbeef;
    prinnt_binary(x);
    return 0;
}