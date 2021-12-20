#include<stdio.h>
#include <ctype.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);
int getline(char s[], int lim);

int main(void){
    char s1[MAXLINE], s2[MAXLINE];
    int c;
    while((c = getline(s1, MAXLINE)) > 0){
        expand(s1, s2);
        printf("%s\n", s2);
    }

    return 0;
}

void expand(char s1[], char s2[]){
    int c, s2Length = 0;
    for(int i = 0; s1[i] != '\0'; i++){

        if(s1[i] == '-'){

            if(isalpha(s1[i - 1]) && isalpha(s1[i + 1]) || isdigit(s1[i - 1]) && isdigit(s1[i + 1])){
                int k;
                if(s1[i + 1] > s1[i - 1]){
                    for(k = 0; c != s1[i + 1]; k++){
                        c = s1[i-1] + k;
                        s2[s2Length + k] = c;
                    }
                    s2Length += k;
                }else{
                     for(k = 0; c != s1[i + 1]; k++){
                         c = s1[i-1] - k;
                        s2[s2Length + k] = c;
                    } 
                    s2Length += k;
                }
            }else{
                s2[s2Length] = s1[i];
                s2Length++;
            }
        }
    }
    s2[s2Length] = '\0';
}

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