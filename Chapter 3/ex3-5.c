#include<stdio.h>
#include<math.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void copy(char from[], char to[]);
void reverse(char src[]);


int main(void){
    char s[MAXLEN];


    itob(110, s, 16);
    printf("%s",s);
    return 0;
}

void itob(int n, char s[], int b){
    int remainder = n % b;
    int quotient = n / b;
    int i = 0;

     if(b == 16 && remainder >= 10)
        s[i] = remainder + 55;
    else
        s[i] = remainder + 48;
    i++;

    while(quotient != 0){
        remainder = quotient % b;
        quotient /= b;

        if(b == 16 && remainder >= 10)
            s[i] = remainder + 55;
        else
            s[i] = remainder + 48;
        i++;
    }
    reverse(s);
}

void reverse(char src[]){
    int len = strlen(src);
    char temp[MAXLEN];
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



    