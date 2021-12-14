#include<stdio.h>
#include<string.h>
#define MAXLINE 1000


int any(char s1[], char s2[]);


int main(void){

    char testStringOne[MAXLINE] = "Delete occurences of same letter.";
    char testStringTwo[MAXLINE] = "This line has some of the same letters.";

    
    printf("%d", any(testStringOne, testStringTwo));



    return 0;
}

int any(char s1[], char s2[]){
     int c2;
    for(int i = 0; s2[i] != '\0'; i++){
        c2 = s2[i];
        for(int k = 0; s1[k] != '\0'; k++){
            if(s1[k] == c2){
                return k;
            }
        }
    }
    return -1;


}