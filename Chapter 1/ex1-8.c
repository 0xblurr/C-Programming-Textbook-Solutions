#include<stdio.h>

int main(void){

int blank, tab, newline, c;

blank, tab, newline = 0;
while ((c = getchar()) != EOF){
  if(c == '\n'){
    newline++;
  }else if(c == '\t'){
    tab++;
  }else if(c == ' '){
    blank++;
  }
}

  printf("\nTabs: %d  Newlines: %d  Blanks: %d \n",tab,newline,blank);

}
