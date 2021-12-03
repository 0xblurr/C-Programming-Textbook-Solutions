#include<stdio.h>
#define MAXLINE 1000  /*maximum input line length*/

int getline(char line[], int maxline);

#include <stdio.h>

#define MAXLINE 1000

/*Solution written by Xggggg
    "https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_18"*/

int getline(char str[], int lim);

int main(void)
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 1)
            printf("%s", line);
    return 0;
}

int getline(char str[], int lim)
{
    int c, i, j;
    i = j = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (j < lim)
            str[j++] = c;
        if (c != ' ' && c != '\t')
            i = j;
    }
    if (c == '\n' && i++ < lim)
        str[i - 1] = '\n';
    str[(i < lim) ? i : lim - 1] = '\0';
    return i;
}