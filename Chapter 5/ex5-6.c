#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAXLINE 1000

int get_line(char* , int);
int atoi_(char*);
void reverse(char []);
char* itoa_(int, char*);
void copy_(char[], char[]);

int main(void){
    int len;
    char arr[MAXLINE];
    char line[MAXLINE];
    char *arrPtr = arr;
    char string[] = "5434";
    int testNum = 5462;
    char *testString  = string;
   

    //printf("%d\n", atoi_(string));
    //testString = itoa_(testNum, line);
    printf("First: %s\n", testString);
    reverse(testString);
    printf("Second: %s\n", testString);
   

    return 0;
}

int get_line(char *ptr, int lim){
    int c,i;

    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; i++)
        *ptr = c;
    if (c == '\n'){
        *ptr = c;
        ptr++;
    }
    *ptr = '\0';
    return i;
}

//convert string to integer
int atoi_(char *s){
    int num = 0;
    int i = strlen(s) - 1;
    while(*s != '\0'){
        num = ((*s - 48) * pow(10, i)) + num;
        i--, s++;
    }
    return num;
}

char* itoa_(int n, char *strPtr){
    char *tempPtr;
    tempPtr = strPtr;
    int num;
    while(n){
        num = n % 10;
        n /= 10;
        *strPtr = num + 48;
        strPtr++;
    }

    *strPtr = '\0';
    strPtr = tempPtr;
    return strPtr;
}

void reverse(char *s)
{
  char *t = s + strlen(s) - 1;
  char aux = 0;

  if (*s == '\0')
    return;

  while (s < t)
  {
    aux = *t;
    *t-- = *s;
    *s++ = aux;
  }
}


/*Strindex and getop missing, i got bored*/
