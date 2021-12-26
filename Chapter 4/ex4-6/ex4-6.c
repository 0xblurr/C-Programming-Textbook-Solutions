#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include"ex4-6_1.h"
#include"ex4-6_2.h"
#include"ex4-6_3.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVARS 26
#define VARSET '_'



int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
int main(void){
    int type;
    double op2;
    char s[MAXOP];

    double vars[MAXVARS];
    int varIndex = 0;
  

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
            case '\n':
                if((sp > 0))
                    printf("\t%.8g\n", pop());
                break;
            case VARSET:       /*set var*/
                vars[varIndex++] = pop();
                printf("variable %c: %.3f\n", 'a' + varIndex - 1, vars[varIndex - 1]);
                break;
            case VARGET:
                push(vars[var - 'a']);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}