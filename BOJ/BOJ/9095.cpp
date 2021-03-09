#include <iostream>
using namespace std;
int d[20]={0,1,2,4,0};
int dp(int x){
    if(d[x]) return d[x];
    if(x==0) return 0;
    return dp(x-1)+dp(x-2)+dp(x-3);
}
int n,m,i;
int main(void){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        printf("%d\n",dp(m));
    }
    return 0;
}
