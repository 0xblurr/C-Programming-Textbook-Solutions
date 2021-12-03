#include<stdio.h>


int main(void){
  int c;
  int blank = 0;
  while((c = getchar()) != EOF){
    if(c != ' '){
      putchar(c);
      blank = 0;
    }else{
      blank++;
      if(blank > 1)
        ;
      else{
        putchar(c);
      }
    }
  }
}
