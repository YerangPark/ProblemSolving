#include "bojHeader.h"

int pow(int a, int n){
    if(n==1) return a;
    return a*pow(a,n-1);
}

int main(void){
    int a, n;
    scanf("%d %d",&a ,&n);
    printf("%d",pow(a, n));
}
