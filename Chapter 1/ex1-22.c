/******************************************************

   Author: 0xblurr
   Github: https://github.com/0xblurr

******************************************************/




#include<stdio.h>
#define TAB 4  //number of spaces per tab stop
#define MAXTABSTOPS 10 //max columns per line
#define MAXLINE 1000

int getline(char s[], int lim);


int main(void){

    int c, len, k;
    char line[MAXLINE];

    
    while((len = getline(line, MAXLINE)) > 0){
        for(int i = 0;i < len; i++){
            if(i % (MAXTABSTOPS * TAB) == 0){
                k = i;
                while(line[k] != ' ' && line[k] != '\t')
                    k--;
                line[k] = '\n';
            }
        }
        printf("%s", line);
    }

    return 0;
}

/*getline: read a line into s, return length*/
int getline(char s[], int lim)
{
    int c,i;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}




