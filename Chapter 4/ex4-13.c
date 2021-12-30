#include<stdio.h>
#include<string.h>

void reverse(char []);

int main(void){

    char s[] = "importance";
    reverse(s);
    printf("%s\n", s);

    char t[] = "testing";
    reverse(t);
    printf("%s", t);



    return 0;
}

void reverse(char s[]){
    static int i;
    char temp;
    int len = strlen(s) - 1;
    if(i <= len - i){
        temp = s[i];
        s[i] = s[len - i];
        s[len - i] = temp;
        i++;
        reverse(s);
    }else
        i = 0;
        

}