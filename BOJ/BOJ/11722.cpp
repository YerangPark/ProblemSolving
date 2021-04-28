#include <iostream>
using namespace std;
int n, m;
int num[1001];
int d[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    int maxx=0;
    for(int i=0;i<n;i++) {
        int tmpMax=0;
        cin>>num[i];
        for(int j=0;j<i;j++){
            if(num[j]>num[i]){
                tmpMax=max(tmpMax,d[j]);
            }
        }
        d[i]=tmpMax+1;
        if(d[i]>maxx)maxx=d[i];
    }
    cout<<maxx<<'\n';

    return 0;
}
