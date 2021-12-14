#include<stdio.h>
#include<ctype.h>


int htoi(char s[]);

int main(void){


    /*Test Cases*/
    printf("Expected: 10 Actual: %d\n", htoi("A"));
    printf("Expected: 206 Actual: %d\n", htoi("CE"));
    printf("Expected: 42186 Actual: %d\n", htoi("A4CA"));
     printf("Expected: 25926 Actual: %d\n", htoi("6546"));


    return 0;
}

int htoi(char s[]){
    int n;

    n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')){
            n = 16 * n + (s[i] - 'A' + 10);
        }else if(isdigit(s[i])){
            n = 16 * n + (s[i] - '0');
        }
    }
    return n;
}