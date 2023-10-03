#include<stdio.h>
#include<stdint.h>
void change_bit(uint32_t x){
    x = (x | (1 << 13) | (0 << 20));
    
}