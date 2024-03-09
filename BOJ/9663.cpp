#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt=0;
void recursion(vector<pair<int,int>>& pv){
    //base case
    if(pv.size()==n){
        cnt++;
        return;
    }
    //recursive case
    for(int i=0;i<n;i++){
        int nx, ny;
        ny=(int)pv.size(); nx=i;
        //i열에 퀸 추가할 수 있는지 검사
        bool prob=true;
        for(auto p:pv){
            if(p.second==nx||abs(nx-p.second)==abs(ny-p.first)){
                prob=false; break;
            }
        }
        if(!prob) continue;
        pv.push_back(make_pair(ny,nx));
        recursion(pv);
        pv.pop_back();
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    vector<pair<int,int>> v;
    recursion(v);
    cout<<cnt;
}
