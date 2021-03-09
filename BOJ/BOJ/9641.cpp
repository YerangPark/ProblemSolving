#include <iostream>
using namespace std;
long long dp[101]={0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0};
long long tri(int x){
    //기저 조건
    if(x==1) return 1;
    //메모리제이션
    long long &ret=dp[x];
    if(ret) return ret;
    //점화식
    return ret=tri(x-2)+tri(x-3);
}
int n,m,i,j,sum=0,cnt=0;
int main(void){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        printf("%lld\n",tri(m));
    }
    return 0;
}
