#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char from[], char to[], int length);

int main(void){
    
    int len;
    char line[MAXLINE];
    char s[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0)
        reverse(line, s, len);
        printf("%s", s);

    return 0;
}

/*getline: read a line into s, return length*/
int getline(char s[], int lim)
{
    int c,i;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

//reverses a string
void reverse(char from[], char to[], int length){
    int i;
    for (i = 0; i < length - 2; i++)
            to[i] = from[(length - 3) - i];
    to[i] = '\0';
}