#include<stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
int getline(char s[], int lim);
void de_scape(char t[], char s[]);

int main(void){

    int c;
    char line[MAXLINE];
    char escapedLine[MAXLINE];

    while((c = getline(line, MAXLINE)) > 0){
        escape(line, escapedLine);
        printf("Escaped: %s\n", escapedLine);

        de_scape(escapedLine, line);
        printf("De-Escaped: %s\n", line);


    }





    return 0;
}

void escape(char s[], char t[]){
    int i = 0; 
    int j = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case '\t':
                t[j] = '\\';
                t[++j] = 't';
                i++;  
                j++;
                break;
            case '\n':
                t[j] = '\\';
                t[++j] = 'n';
                i++; 
                j++;
                break;
            case '\v':
                t[j] = '\\';
                t[++j] = 'v';
                i++;   
                j++;
                break;
            case '\b':
                t[j] = '\\';
                t[++j] = 'b';
                i++;  
                j++;
                break;
            case '\r':
                t[j] = '\\';
                t[++j] = 'r';
                i++;   
                j++;
                break;
            case '\f':
                t[j] = '\\';
                t[++j] = 'f';
                i++;  
                j++;
                break;
            case '\a':
                t[j] = '\\';
                t[++j] = 'a';
                i++;   
                j++;
                break;
            default:
                t[j] = s[i];
                i++;   
                j++;
                break;

        }
    }
    t[j] = '\0';
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

void de_scape(char t[], char s[]){
    int i, j;
    for(i = 0, j = 0; t[i] != '\0'; i++, j++){
        switch(t[i]){
            case '\\':
                switch(t[++i]){
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 'v':
                        s[j] = '\v';
                        break;
                    case 'b':
                        s[j] = '\b';
                        break;
                    case 'r':
                        s[j] = '\v';
                        break;
                    case 'f':
                        s[j] = '\f';
                        break;
                    case 'a':
                        s[j] = '\a';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j] = t[i];
                        break;
                }
                break;
            default:
                s[j] = t[i];
                break;
        }
        if(t[i] == '\0'){
            s[j] = t[i];
        }
    }


}