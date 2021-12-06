#include<stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);



int main(void){

    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0){
        for(int i = 0; i < len; i++){
            if(line[i] == '/' && line[i + 1] == '*'){
                line[i] = ' ';
                while(line[i] != '*' && line[i + 1] != '/'){
                    ++i;
                    line[i] = ' ';
                }
                line[i] = ' ';
                line[i + 1] = ' ';
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