#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, op[4], minn=1000000000, maxx=-1000000000;
vector<int> v;
void ans(vector<int> operV){
    int prev=v[0];
    for(int i=0;i<operV.size();i++){
        if(operV[i]==0) prev+=v[i+1];
        else if(operV[i]==1) prev-=v[i+1];
        else if(operV[i]==2) prev*=v[i+1];
        else if(operV[i]==3) prev/=v[i+1];
    }
    if(prev>maxx) maxx=prev;
    if(prev<minn) minn=prev;
}

void recursive(vector<int> operV){
    //base case
    if(operV.size()>=n-1){
        ans(operV);
        return;
    }
    //recursive case
    for(int i=0;i<4;i++){
        if(op[i]==0) continue;
        op[i]--;
        operV.push_back(i);
        recursive(operV);
        op[i]++;
        operV.pop_back();
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    vector<int> cv;
    for(int i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
    }
    for(int i=0;i<4;i++)cin>>op[i];
    recursive(cv);
    cout<<maxx<<'\n'<<minn;
}
