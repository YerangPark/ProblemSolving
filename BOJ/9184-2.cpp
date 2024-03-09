//9184-2번째 복습
#include <iostream>
#include <cstring>
using namespace std;
int n, m, i, j, dp[21][21][21];
int w(int a, int b, int c){
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
        return w(20,20,20);
    
    int &ret=dp[a][b][c];
    if(ret!=-1) return ret;
    
    if(a<b && b<c) return ret=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return ret=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>i;
    while(!(n==-1&&m==-1&&i==-1)){
        cout<<"w("<<n<<", "<<m<<", "<<i<<") = "<<w(n,m,i)<<'\n';
        cin>>n>>m>>i;
    }
    return 0;
}
