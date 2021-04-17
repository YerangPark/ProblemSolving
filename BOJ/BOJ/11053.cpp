#include <iostream>
using namespace std;
int n, d[1001], num[1001], maxx=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmpMax=0;
        cin>>num[i];
        for(int j=1;j<i;j++){
            if(num[j]<num[i]){
                tmpMax=max(tmpMax, d[j]);
            }
        }
        d[i]=tmpMax+1;
        if(d[i]>maxx) maxx=d[i];
    }
    cout<<maxx;
}
