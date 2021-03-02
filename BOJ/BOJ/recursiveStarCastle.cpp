#include "bojHeader.h"
/*
 input> 5
 output>
 *****
 ****
 ***
 **
 *
 **
 ***
 ****
 *****
 */
void make_castle(int n, int i){
    if(2*n-1<=i) return;
    for(int j=0;j<abs(n-i)+1;j++) AST;
    EN;
    return make_castle(n,i+1);
}

int main(void){
    int n;
    scanf("%d",&n);
    make_castle(n,1);
}
