#include <iostream>
#include <cstring>
using namespace std;
int dp[301];
int stair[301];
int maxScore(int x, int c){
    if(x<=0) return 0;
    if(c>2)
        return 0;
    
    int& ret=dp[x];
    if(ret!=-1) return ret;
    
    return ret=max(maxScore(x-3,c+1)+stair[x-1]+stair[x]
                   ,maxScore(x-2,0)+stair[x]);
}
int n,i;
int main(void){
    memset(dp, -1, sizeof(dp));
    memset(stair, -1, sizeof(stair));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&stair[i]);
    }
    printf("%d",maxScore(n,0));
    return 0;
}

