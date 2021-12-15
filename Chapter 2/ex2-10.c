#include<stdio.h>

char lower(char s);

int main(void){

    printf("%c\n", lower('S'));
    printf("%c\n", lower('Z'));
    printf("%c\n", lower('k'));
    printf("%c\n", lower('H'));
    printf("%c\n", lower('y'));


    return 0;
}

char lower(char s){
    return ((s >= 'A' && s <= 'Z') ? s + ('a' - 'A') : s );
}