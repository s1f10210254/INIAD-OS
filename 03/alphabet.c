#include<stdio.h>
#include<string.h>

int main()
{
    int c;
    int counts[26];

    /*for (int i= 0; i< 26; i++){
        counts[i] = 0;
    }
    */
    memset(counts, 0,sizeof(counts));

    for (;;){
        c = fgetc(stdin);
        if (c == EOF) break;
        if ('a' < c && c <= 'z'){
            counts[c - 'a']++;
        }
        if ('A' < c && c <= 'Z'){
            counts[c- 'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c : %d\n", 0x61 + i, counts[i]);
    }
    
    return 0;
}