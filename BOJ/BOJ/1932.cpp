#include <iostream>
#include <cstring> //memset
using namespace std;
int tri[500][500];
int dp[500][500];
int triSum(int x, int y){
    if(tri[x][y]==-1) return 0;
    int &ret = dp[x][y];
    if(ret!=-1) return ret;
    ret=0;
    int a=triSum(x+1,y);
    int b=triSum(x+1,y+1);
    return ret = tri[x][y] + ((a>b)? a:b);
}
int n,m,i,j,sum=0,cnt=0;
int main(void){
    memset(dp, -1, sizeof(dp));
    memset(tri, -1, sizeof(tri));
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            scanf("%d",&tri[i][j]);
            if(i==n-1)
                dp[i][j]=tri[i][j];
        }
    }
    printf("%d",triSum(0,0));
    return 0;
}
