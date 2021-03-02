#include <iostream>
#include <algorithm>
using namespace std;
int dp[50001]; //전역 변수이면 0으로 초기화됨.

int main(void){
    int n;
    scanf("%d",&n);
    dp[3]=dp[5]=1;
    
    //5 다음부터 순회
    for(int i=6;i<=n;i++){
        //dp[i-3]에 값이 존재하면 해당 값+1
        if(dp[i-3]) dp[i]=dp[i-3]+1;
        //만약 dp[i]에 값이 없다면
        if(dp[i-5]) dp[i]=dp[i] ? min(dp[i]+1, dp[i-5]+1) : dp[i-5]+1;
    }
    printf("%d\n",dp[n]==0?-1:dp[n]);
    return 0;
}
