
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int chr;
    fp = fopen("proc/uptime", "r");
    if(fp == NULL){
        printf("file not open!\n");
        return 1;
    }
    while((chr = fgetc(fp)) != EOF){
        putchar(chr);
    }
    //fprintf(fl, "Up for %s .seconds\n",fp);
    fclose(fp);
    return 0;
}
