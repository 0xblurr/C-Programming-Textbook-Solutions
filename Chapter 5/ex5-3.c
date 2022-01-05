#include<stdio.h>

void strcpy(char *, char *);

int main(void){

    char s[20] = "hello";
    char t[20] = "world";
    strcpy(s,t);
    printf("S: %s  T: %s\n", s, t);


    return 0;
}

void strcpy(char *s, char *t){
    while(*s++){
        if(*s == '\0')
            while(*s++ = *t++)
                ;
    }    
}