#include<stdio.h>

int conversion(int, int, int, int);

int main(void){

  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;

  conversion(fahr,upper, step, celsius);
}

int conversion(int fahr, int upper, int step, int celsius){
  while (fahr <= upper){
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n",fahr, celsius);
    fahr = fahr + step;
  }

}
