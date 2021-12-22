#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

double atof(char s[]);

int main(void){

    char str[] = "2e20";
    printf("%f", atof(str));

    return 0;
}


double atof(char s[])
{
    double val, power;
    int i, sign;
    int expSign = 1;
    for (i = 0; isspace(s[i]); i++) 
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }


    if(s[i] == 'e' || 'E'){                 
        i++;
        int signExp = (s[i] == '-') ? -1 : 1;
        if(signExp == -1)
            i++;
        int exp = 0;
        double powerX = 1;
        for(int k = strlen(s) - 1; k >= i; k--){
            exp = (s[k] - '0')* powerX + exp;
            powerX *= 10;
        }
        if(signExp == -1)
            return pow((val / power), -exp) * sign;
        else
            return pow((val / power), exp) * sign;
    }
    return sign * (val / power);
}