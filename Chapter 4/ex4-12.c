#include<stdio.h>
#define MAXLEN 1000
void itoa(int, char []);

int main(void){

    char str[MAXLEN];
    itoa(-454343, str);

    printf("%s\n", str);

    itoa(54652, str);

    printf("%s", str);
    return 0;
}

void itoa(int n, char s[]){
    static int i;
    if(n < 0){
        s[i++] = '-';
        n *= -1;
    }
    if (n / 10){
        i -= i;         /*reset static variable so function can be reused indefinitely*/
        itoa(n / 10, s);
    }

    s[i++] = '0' + (n % 10);
    s[i+1] = '\0';


}

