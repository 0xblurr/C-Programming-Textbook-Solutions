#include<stdio.h>


int main(void){

  int c;

  while((c = getchar()) != EOF){
    if(c == '\n' || c == '\t' || c == ' '){   //loop will stop execution once a truth or falsehood is known
      putchar('\n');
    }else{
      putchar(c);
    }
  }
}
