#include<stdio.h>
#define TAB 4  //number of spaces per tab stop
#define SPACETAB 4 //spaces per tab

int main(void){
    
    int c, space;
    int count = 0;
    int countSpaces = 0;

    while((c = getchar()) != EOF){
        space = TAB - (count % TAB);   //Credit for this line: https://stackoverflow.com/a/26692695/17590249


        if(c == ' '){
            ++countSpaces;
            for(int i = 0; i <= space; i++){
                if((c = getchar()) != ' '){
                    countSpaces = 0;
                    putchar(' ');
                    putchar(c);
                    i = space;
                }else if(countSpaces == SPACETAB){
                    countSpaces = 0;
                    putchar('\t');
                }else{
                    putchar(c);
                    ++countSpaces;
                }
            }
        }else if(c == '\n'){
            count = 0;
        }else{
            ++count;
            putchar(c);
        }
    }
    return 0;
}
