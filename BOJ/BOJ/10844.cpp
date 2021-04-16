#include <iostream>
using namespace std;
int n, d[101][11];
long long ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    //L(1)값에 대해 초기화 해주기
    d[1][0]=0;
    for(int i=1;i<10;i++) d[1][i]=1;
    //계산
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0) d[i][j]=d[i-1][j+1]% 1000000000;
            else if(j==9) d[i][j]=d[i-1][j-1]% 1000000000;
            else d[i][j]=(d[i-1][j-1]+d[i-1][j+1])% 1000000000;
        }
    }
    //결과는
    for(int i=0;i<=9;i++) ans+=d[n][i];
    cout<<ans%1000000000;
    return 0;
}
