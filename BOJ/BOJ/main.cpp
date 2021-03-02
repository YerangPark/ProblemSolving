#include <iostream>


void jagui(int n){
    if(n<=0) return;
    printf("%d\n",n);
    jagui(n-1);
}

int main(void) {
    jagui(10);
}
