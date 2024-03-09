#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,i,j,sum=0;
int main(void) {
    vector<int> v;
    for(i=0;i<9;i++){
        scanf("%d",&n);
        v.push_back(n);
        sum+=n;
    }
    for(i=0;i<8;i++){
        for(j=i+1;j<9;j++){
            if(sum-(v[i]+v[j])==100){
                v.erase(v.begin() + i);
                v.erase(v.begin() + j - 1);
                goto label;
            }
        }
    }
    label:
    sort(v.begin(),v.end());
    for(auto i:v) printf("%d\n",i);
    return 0;
}

