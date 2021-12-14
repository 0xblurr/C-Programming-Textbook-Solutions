#include<stdio.h>
#define MAXLINE 1000


void squeeze(char s1[], char s2[]);


int main(void){

    char testStringOne[MAXLINE] = "Delete occurences of same letter.";
    char testStringTwo[MAXLINE] = "This line has some of the same letters.";

    squeeze(testStringOne, testStringTwo);
    printf("%s", testStringOne);

    

    return 0;
}

void squeeze(char s1[], char s2[]){
    int c1;
    for(int i = 0; s1[i] != '\0'; i++){
        c1 = s1[i];
        for(int k = 0; s2[k] != '\0'; k++){
            if(s2[k] == c1){
                s1[i] = ' ';
            }
        }
    }
}

