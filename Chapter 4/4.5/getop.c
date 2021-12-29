#include<stdio.h>
#include<ctype.h>
#include "calc.h"

#define MAXVAR 26
#define GETVAR '$'
#define SETVAR '_'


char vars[MAXVAR];
int varp = 0;
char var = '0';


int getop(char s[]){
   
    int i = 0, c, next;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(isalpha(c)){
        var = c;
        return GETVAR;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
        
    if(c == '-'){
        next = getch();
        if(!isdigit(next) && next != '.'){
            return next;
        }

        s[i] = c;
        ungetch(c = next);
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}