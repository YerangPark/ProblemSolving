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
        if(!vv.empty()){
            //지금 추가하려는 원소와 같거나 그보다 큰 원소가 존재하면 컨티뉴
            bool isIn = false;
            for(int j=0;j<vv.size();j++){
                if(vv[j]>=i) isIn=true;
            }
            if(isIn)continue;
        }
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

