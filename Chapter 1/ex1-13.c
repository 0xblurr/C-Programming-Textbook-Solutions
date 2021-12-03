#include<stdio.h>


#define MAXLENGTH 9
#define ASTERISK 42
#define SPACE 32
//program prints histogram based on word length frequency

int main(void){

  int wordLength[MAXLENGTH] = {0};
  int c;
  int count;


  while((c = getchar()) != EOF){
    if(c != ' ' && c != '\n' && c != '\t' && c != ','){
      count++;
    }else{
      wordLength[count] += 1;
      count = 0;
    }
  }


  count = 0;
  for (int i = 0; i < MAXLENGTH; i++){
    if (wordLength[i] > count){
      count = wordLength[i];
    }
  }

  printf("\n   freq");
  //generate histogram
  for(int ii = count; ii > 0; ii--){
    printf("\n%d |", ii);
    for(int kk = 0; kk < MAXLENGTH; kk++){
      if(wordLength[kk] < ii){
        printf("%c ", SPACE);
      }else{
        printf("%c ", ASTERISK);
      }
    }
  }
  printf("\n   -------------------");
  printf("\n   0 1 2 3 4 5 6 7 8 9");
  printf("\n      Word Length     ");

}
