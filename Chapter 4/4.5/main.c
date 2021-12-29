#include <stdio.h>
#include <stdlib.h>
#include "calc.h" 
#define MAXOP 100
#define SETVAR '_'
#define MAXVAR 26
#define GETVAR '$'

extern int sp;
extern char vars[];
extern int varp;
extern char var;




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
            case SETVAR:
                if(varp < MAXVAR){
                    temp = pop();
                    printf("\tVariable %c = %.2f\n", 'a' + varp, temp);
                    vars[varp++] = temp;  
                }
                else{
                    printf("\tNo variables available.\n");
                }
                break;
            case GETVAR:
                push(vars[var - 'a']);
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