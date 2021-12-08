#include<stdio.h>
#include<limits.h>
#include<float.h>


int main(void){
    printf("Unsigned Char: [%d, %d]\n", 0, UCHAR_MAX);
    printf("Signed Char: [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);  
    printf("Unsigned short: [%d , %d]\n", 0, USHRT_MAX);
    printf("Signed short: [%d , %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned int: [%d , %d]\n", 0, UINT_MAX);
    printf("Signed int: [%d , %d]\n", INT_MIN, INT_MAX);
    printf("Unsigned long: [%d , %d]\n", 0, ULONG_MAX);
    printf("Signed long: [%d , %d]\n", LONG_MIN, LONG_MAX);

    /*Not sure how to compute the above values. I will return to add once I figure that out.
    This solution would be straighforward if we had access to the sizeof() function. However,
    I am trying to restrict myself to only the concepts presented in the book up to this point*/



    return 0;
}
