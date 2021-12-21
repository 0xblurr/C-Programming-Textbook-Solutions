#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void){


    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) 
        printf("Rightmost occurence of t in s: %d\n", strindex(line, pattern));

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}   


/*A simple edit to the function provided in the book will return the requsted result*/
int strindex(char s[], char t[]){
    int i, j, k;
    int index = -1;             /*index of current rightmost occurence*/
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;              
        }
        return index;      
}
