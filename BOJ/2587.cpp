#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,i,sum=0;
int main(void) {
    vector<int> v;
    for(i=0;i<5;i++){
        scanf("%d",&n);
        sum+=n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    printf("%d\n%d",sum/5,v[2]);
    return 0;
}
