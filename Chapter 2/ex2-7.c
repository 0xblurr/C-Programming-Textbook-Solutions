#include<stdio.h>

int invert(unsigned x, int p, int n);

int main(void){

    printf("%d", invert(162, 4, 3));
    return 0;
}

int invert(unsigned x, int p, int n){
    return (~(~0 << (p+2-n)) << (p+1-n)) | x;

}