#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,i,j,sum;
int main(void) {
    vector<int> v;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        v.clear();
        for(j=0;j<10;j++){
            scanf("%d",&m);
            v.push_back(m);
        }
        sort(v.begin(),v.end());
        printf("%d\n",v[7]);
    }
    return 0;
}

