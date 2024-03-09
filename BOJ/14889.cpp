#include <iostream>
using namespace std;
int n, m, arr[20][20], ans=1e9, c[20];
void solve(int cnt, int idx){
    if(idx==n) return;
    if(cnt==n/2){
        int s1=0, s2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i]&&c[j]) s1+=arr[i][j];
                if(!c[i]&&!c[j]) s2+=arr[i][j];
            }
        }
        ans=min(ans,abs(s1-s2));
        return;
    }
    c[idx]=true;
    solve(cnt+1,idx+1);
    c[idx]=false;
    solve(cnt,idx+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    solve(0,0);
    cout<<ans;
    return 0;
}
