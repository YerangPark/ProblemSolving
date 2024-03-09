#include <iostream>
#include <algorithm>
using namespace std;


int hansoo(int x){
    if(x<=0) return 0;
    if(x>=100){ //세자리 수이면?
        int a=(x/100);
        int b=(x%100)/10;
        int c=x%10;
        if(a-b==b-c) return hansoo(x-1)+1;
    }
    else if(x>=10) return hansoo(x-1)+1;
    else if(x!=0) return hansoo(x-1)+1;
    return hansoo(x-1);
}

int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d",hansoo(n));
    return 0;
}
