#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];


int main(void) {
    int n;
    scanf("%d",&n);
    
    for(int i=n;i>=1;i--){
        if(i%3==0){
            dp[i/3]= dp[i/3]? min(dp[i]+1,dp[i/3]):dp[i]+1;
        }
        if(i%2==0){
            
            dp[i/2]= dp[i/2]? min(dp[i]+1,dp[i/2]):dp[i]+1;
        }
        if(i-1>0){
            dp[i-1]= dp[i-1]? min(dp[i]+1,dp[i-1]):dp[i]+1;
        }
        
    }
    printf("%d\n",dp[1]);
    return 0;
}
