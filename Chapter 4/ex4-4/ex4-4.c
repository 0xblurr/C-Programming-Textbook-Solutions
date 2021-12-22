#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include"ex4-4_1.h"
#include"ex4-4_2.h"
#include"ex4-4_3.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */




int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void){
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case 'p':    /*peek*/
                if(sp)
                    printf("\tPeek: %g\n", val[sp - 1]);
                else
                    printf("error: stack empty\n");
                break;
            case 'd':   /*duplicate*/
                if(sp)
                    push(val[sp - 1]);
                else
                    printf("error: stack empty\n");
                break;
            case 's':      /*swap*/
                if(sp && sp - 1){
                    double temp = pop();
                    double temp2 = pop();
                    push(temp);
                    push(temp2);  
                }else
                    printf("error: insufficent number of elements\n");
                break;
            case 'c':           /*clear*/
                while(sp)
                    pop();
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
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}