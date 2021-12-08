#include<stdio.h>
#define MAXLINE 1000


int main(void){
    int c;
    int lim = MAXLINE;
    for(int i = 0; (i < lim-1) + ((c=getchar()) != '\n' ) + (c != EOF) == 3; i++){
        printf("Iteration: %d\n", i);
    }
    printf("Success.");


    return 0;
}