#include<stdio.h>
#include<stdint.h>

int change_bit(uint32_t x){
    if(x & (0<<13)){
        (x | (1<<13));
    }
    if(x &(1<<20)){
        (x | (0<<20));
    }
}