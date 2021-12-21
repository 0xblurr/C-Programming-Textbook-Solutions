#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAXLENGTH 1000

void itoa(int n, char s[]);
void reverse(char src[]);
void copy(char from[], char to[]);

int main(void){

    int n = 785;
    char str[MAXLENGTH];

    itoa(n, str);
    printf("%s\n", str);

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;                    
    i = 0;
    do {                                
        s[i++] = abs(n % 10) + '0';          
    } while ((n /= 10) > 0);           
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    
}

void reverse(char src[]){
    int len = strlen(src);
    char temp[MAXLENGTH];
    int i;

    for(i = 0; i < len; i++){
        temp[i] = src[(len - 1) - i];
    }
    temp[i] = '\0';
    copy(temp, src);

}

void copy(char from[], char to[]){
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}



/*
It doesn't handle the largest negative number because
there is no positive equivalent. Taking the abs() of n % 10 will
solve this
*/