#include<stdio.h>


int setbits(unsigned x, int p, int n, int y);


int main(void){


    printf("%d", setbits(5, 3, 4, 40));


    return 0;
}

int setbits(unsigned x, int p, int n, int y){
    return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
}