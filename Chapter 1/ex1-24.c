#include<stdio.h>
#define MAXLINE 1000
#define SINGLEQUOTE 39
#define DOUBLEQUOTE 34

int getline(char s[], int lim);
int checkLine(char found, char s[], int len, int foundIndex);

int lineNumber = 0;


int main(void){
    
    int len;
    char line[MAXLINE];
    
    while((len = getline(line, MAXLINE)) > 0){
        ++lineNumber;

        for(int k = 0; k < len; k++){
            if(line[k] == '(' || line[k] == '{' || line[k] == '}' || line[k] == ')' || line[k] ==  '[' || line[k] ==  ']' ||line[k] ==  
            SINGLEQUOTE || line[k] ==  DOUBLEQUOTE || (line[k] == '/' && line[k + 1] == '*') || (line[k] == '*' && line[k + 1] == '/')){
                k = checkLine(line[k], line, len, k);
            }
        }     
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

int checkLine(char found, char s[], int len, int foundIndex){
    char searchingFor;


    if(found == '(')
        searchingFor = ')';
    else if(found == '[')
        searchingFor = ']';
    else if(found == '{')
        searchingFor = '}';
    else if(found == '/' && s[foundIndex + 1] == '*')
        searchingFor = '*/';
    else if(found == SINGLEQUOTE)
        searchingFor = SINGLEQUOTE;   
    else if(found == DOUBLEQUOTE)
        searchingFor = DOUBLEQUOTE;
        
    for(int i = foundIndex + 1; i < len; i++){
        if(s[i] == searchingFor){
           return i;
        }else if(searchingFor == '*/' && s[i] == '*' && s[i + 1] == '/'){
            return i;
        }
    }

    if(found == ']')
        printf("Syntax Error. Expected [ before ] on line %d.\n\n", lineNumber);
    else if(found == ')')
        printf("Syntax Error. Expected ( before ) on line %d.\n\n", lineNumber);
    else if(found == '}')
        printf("Syntax Error. Expected { before } on line %d.\n\n", lineNumber);
    else if(searchingFor == '/')
        printf("Syntax Error. *%c expected on line %d.\n\n", searchingFor, lineNumber);
    else if(found == '*' && s[foundIndex + 1] == '/')
        printf("Syntax Error. Expected /* before */ on line %d.\n\n", lineNumber);
    else
        printf("Syntax Error. %c expected on line %d.\n\n", searchingFor, lineNumber);

   
}




