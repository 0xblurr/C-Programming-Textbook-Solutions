#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include<math.h>
#include"ex4-5_1.h"
#include"ex4-5_2.h"
#include"ex4-5_3.h"
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
            case 'r':               /*sin*/
                push(sin(pop()));
                break;
            case 'x':                       /*e to the power of x*/
                int expo = pop();
                push(pow(pop(), expo));
                break;
            case 'e':                       /*exponentation*/
                push(exp(pop()));
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
