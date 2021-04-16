#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
void recursion(vector<int>& vv){
    //base case
    if(vv.size()==n){
        for(auto p:vv) cout<<p<<' ';
        cout<<'\n';
        return;
    }
    //recursive case
    for(int i=1;i<=m;i++){
        //원소가 존재하지 않으면
        vv.push_back(i);
        recursion(vv);
        vv.pop_back();
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n;
    vector<int> v;
    recursion(v);
}

