#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int t[1001];
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), less<int>());
    int size=v.size();
    int sum=0;
    sum=t[0]=v[0];
    for(int i=1;i<size;i++){
        t[i]=t[i-1]+v[i];
        sum+=t[i];
    }
    cout<<sum<<'\n';
    return 0;
}
