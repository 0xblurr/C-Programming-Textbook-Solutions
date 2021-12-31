#include<stdio.h>

#define swap(t, x, y) t = x, x = y, y = t


int main(void){
    int x = 5;
    int y = 10;
    int t = 0;

    printf("X = %d  Y = %d\n", x, y);
    swap(t, x, y);
    printf("X = %d  Y = %d\n", x, y);


    return 0;
}