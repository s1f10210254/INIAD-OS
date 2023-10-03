#include <stdio.h>
int main(){
    char s[3][80];

    int i;
    for (i = 0; fgets(s[i % 3], sizeof(s[i %3]), stdin) != NULL; i++){
        
    }
    if(i<3){
        for (int j = 0; j < i; j++)
        {
            printf("%s",s[j]);
        }
    }
    else{
        //s[i % 3] - s[(i+2) %3]を順番に表示
        for (int k = 0; k < i; k++)
        {
            /* code */
        }
        
    }

    //ここでs[0]-s[2]に入ってるデータを
    //正しい順番で表示する
    
}