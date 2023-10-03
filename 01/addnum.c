#include <stdio.h>
#include <stdlib.h>

#define STRING_MAX 256         

int main(int argc, char *argv[])
{
    FILE    *filep;
    char    buff[STRING_MAX];
    int     count = 0;          

    if(argc != 2){                          
        printf("Usage : MTYPE filename\n");
        exit(1);
    }
    if((filep = fopen(argv[1], "r")) == NULL){   
        printf("can not open file. %s\n", argv[1]);
        exit(1);
    }
    while(fgets(buff, STRING_MAX, filep) != NULL){  
        ++count;                                   
        printf("%6d:%s", count, buff);              
    }
    fclose(filep);                                   
    return(0);
}