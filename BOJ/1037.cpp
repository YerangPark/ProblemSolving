#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
    int n, m, i;
    vector<int> v;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        v.push_back(m);
    }
    sort(v.begin(),v.end());
    printf("%d",v.front() * v.back());
    return 0;
}
