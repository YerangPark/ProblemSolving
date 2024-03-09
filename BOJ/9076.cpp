#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,i,j,sum;
int main(void) {
    vector<int> v;
    for(i=scanf("%d",&n);i<=n;i++){
        v.clear();
        sum=0;
        for(j=0;j<5;j++){
            scanf("%d",&m);
            v.push_back(m);
            sum+=m;
        }
        sort(v.begin(),v.end());
        sum=sum-v[0]-v[4];
        v.erase(v.begin());
        v.pop_back();
        if(v[2]-v[0]>=4) printf("KIN\n");
        else printf("%d\n",sum);
    }
    return 0;
}
