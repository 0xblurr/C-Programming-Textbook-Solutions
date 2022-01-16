#include<stdio.h>
#include<string.h>

int strend(char *, char *);

int main(void){

    char s[20] = "helloworld";
    char t[20] = "world";
    int result = strend(s,t);
    printf("Result: %d\n", result);


    return 0;
}

int strend(char *s, char *t){
    int lenS = strlen(s);
    int lenT = strlen(t);

    s += lenS;
    t += lenT;

    while(lenT && (*s-- == *t--))
        --lenT;

    if(lenT)
        return 0;

    return 1;
   
    
}