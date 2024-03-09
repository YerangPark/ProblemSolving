#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void){
    int n,i,m;
    double sum = 0;
    vector<int> v;
    map<int, int> mp;
    
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        v.push_back(m);
        sum+=m;
    }
    
    sort(v.begin(),v.end());
    int avg=round(sum / (double)n);
    int midl=v[n/2];
    int many;
    int range=v.back()-v[0];
    
    //빈도 계산
    for(int i=0;i<n;i++){
        if(mp[v[i]]) mp[v[i]]++;
        else mp[v[i]]=1;
    }
    int maxFreq=0;
    vector<int> f;
    for(auto p:mp){
        if(maxFreq<p.second){
            maxFreq=p.second;
        }
    }
    
    for(auto p :mp){
        if(maxFreq==p.second){
            f.push_back(p.first);
        }
    }
    sort(f.begin(),f.end());
    if(f.size()==1) many=f[0];
    else many=f[1];
    
    // 결과 출력
    cout<<avg<<endl<<midl<<endl<<many<<endl<<range<<endl;
}

