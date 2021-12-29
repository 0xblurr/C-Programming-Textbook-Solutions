#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 
#define BUFSIZE 100


int sp = 0; 
double val[MAXVAL]; 
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */


int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);


/* reverse Polish calculator */
int main(void){
    int type, modOp2;
    double op2, temp;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                modOp2 = pop();
                if(modOp2 != 0.0)
                    push((int)pop() % modOp2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':
                temp = pop();
                printf("\tTop: %.2f\n", temp);
                push(temp);
                break;
            case 's':
                temp = pop();
                double temp2 = pop();
                push(temp);
                push(temp2);
                break;
            case 'c':
                while(sp > 0)
                    pop();
                break;
            case '^':
                double exponent = pop();
                push(pow(pop(), exponent));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '~':
                push(sin(pop()));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}



void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    }


double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]){
   
    int i = 0, c, next;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
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

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}