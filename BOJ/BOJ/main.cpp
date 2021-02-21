#include <iostream>

#include <cstdio>   //putchar() 에스터42, 공백 32, 개행 10
#include<cmath>     //abs()

int n, i, j, t;
int main(void){
    for(i=scanf("%d",&n);i<=n*2-1;i++){
        if(i<=n){
            for(j=1;j<i;j++){
                putchar(32);
            }
            for(j=0;j<=n*2-i*2;j++){
                putchar(42);
            }
        }
        else{
            t=i-n;
            for(j=n-t;j>1;j--){
                putchar(32);
            }
            for(j=0;j<2*t+1;j++){
                putchar(42);
            }
        }
        putchar(10);
    }
}
/* 숏코딩
 */
