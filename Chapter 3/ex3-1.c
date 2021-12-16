#include<stdio.h>
#include<time.h>

#define ITERATIONS 100000

int binsearch(int x, int v[], int n);
int newBinsearch(int x, int v[], int n);
void timer(int binsearch(int x, int v[], int n), int x, int v[], int n);

int main(void){

    int v[11] = {0,1,2,3,4,5,6,7,8,9,10};

    printf("K&R Test\n");
    timer(binsearch, 8, v, 11);

    printf("New Binsearch Test\n");
    timer(newBinsearch, 8, v, 11);
    


    return 0;
}


int newBinsearch(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(x == v[low - 1]){
        return low - 1;
    }else{
        return -1;
    }

}

int binsearch(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid + 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

void timer(int binsearch(int x, int v[], int n), int x, int v[], int n){
    double timer = clock();

    for (int i = 0; i < ITERATIONS; ++i){
        binsearch(x,v,n);
    }

    timer = clock() - timer;

     printf("(%.6f seconds)\n",(double)timer / CLOCKS_PER_SEC);


}
