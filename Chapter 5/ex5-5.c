#include<stdio.h>


#define MAXSTRING 100
/*strncmp*/

void strncopy(char *, char *, int);
void strcat(char *, char *);
int strcmp(char *, char *);


int main(void){
    char s[] = "hello ";
    char ct[] = "world";
    strcat(s, ct);
    printf("S: %s Ct: %s", s, ct);
    return 0;
}

void strncopy(char *s, char *ct, int n){
    for(int i = 0; i < n; i++){
        if(strlen(ct) < n && i > n)
            *s++ = '\0';
        else
            *s++ = *ct++;
    }
    *s = '\0';

}

void strcat(char *s, char *ct){
    int lenS = strlen(s);
    int lenCt = strlen(ct);
    s += lenS;
    for(int i = 0; i < lenCt; i++){
        *s++ = *ct++;
    }

    *s = '\0';

}

int strcmp(char *cs, char *ct){
    int lenCs = strlen(cs);
    int lenCt = strlen(ct);

    return lenCs - lenCt;
}

/*My solution for strcmp makes use of a library function. The instructions
made no mention that I was unable to do so. Implementing a version that doesn't
make use of strlen is trivial and can be done with a simple loop if needed.*/