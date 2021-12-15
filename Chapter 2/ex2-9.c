#include<stdio.h>

int bitcount(unsigned x);

int main(void){


    printf("%d\n", bitcount(46));  /*Expect a result of 4*/

    return 0;
}


/*Counts 1 bits in x*/
int bitcount(unsigned x){
    int b = 0;

    while(x != 0){
        x &= (x-1);
        b++;
        
    }
    return b;
}