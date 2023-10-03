#include <stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[]){
    int hour = atoi(argv[1]);
 
    if (argc != 2){
        printf("時刻を指定してください\n");
        return 1;
    }
    if (hour >= 5 && hour <=10){
        printf("おはようございます\n");
        return 0;
    }
    if (hour >=11 && hour <=17){
        printf("こんにちは\n");
        return 0;
    }

    if(hour >= 0 && hour <= 4 || hour >= 21 && hour <= 23){
        printf("おやすみなさい\n");
        return 0;
    }
    
}