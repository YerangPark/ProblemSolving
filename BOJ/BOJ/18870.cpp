#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int i, j, n, m, cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    vector<int> ov;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
        ov.push_back(m);
    }
    sort(ov.begin(), ov.end());
    auto it = unique(ov.begin(), ov.end());
    for(i=0;i<n;i++){
        cout<<lower_bound(ov.begin(), it, v[i]) - ov.begin() << ' ';
    }
}
