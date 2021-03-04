#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool compareFir(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first<b.first) return true;
    else return false;
}
bool compareSec(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second>b.second) return true;
    else return false;
}
int n,i,sum=0;
int main(void) {
    vector<pair<int, int>>v;
    for(i=1;i<=8;i++){
        scanf("%d",&n);
        v.push_back({i,n});
    }
    sort(v.begin(), v.end(), compareSec);
    for(i=8;i>=6;i--) v.pop_back();
    sort(v.begin(), v.end(), compareFir);
    for(auto i:v) sum+=i.second;
    cout<<sum<<endl;
    for(auto i : v)  cout<<i.first<<" ";
    return 0;
}
