#include<stdio.h>
#define TAB 4 //number of spaces per tab stop

//program replaces tabs with spaces up to the next tab stop
int main(void) {
    int c;
    int count = 0;

    while((c = getchar()) != EOF){
        int space = TAB - (count % TAB);   //Credit for this line: https://stackoverflow.com/a/26692695/17590249
        if(c == '\t'){
            for(int i = 0; i < space; i++)
                putchar(' ');
                ++count;
        }else if(c == '\n'){
            count = 0;
        }else{    
            ++count;
            putchar(c);
        }
    }
    return 0;
}


