#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
//#include<bits/stdc++.h>

//#define INT_MAX 2147483647
//bool compare(int a, int b) {return a>b;}
//memset(dp, -1, sizeof(dp));

//int n,m,i,j,sum=0,cnt=0,a, b,ran;

using namespace std;
//답은 ans, 함수는 solve, 부울은 flag, start/endXY대신에 start만 받고 사이즈 받기 방법
int n, m, cnt;

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
            //cout<<"i : "<<i<<" / m : "<< m <<'\n';
            //원소가 존재하면
            bool isIn = false;
            for(int j=0;j<vv.size();j++){
                if(vv[j]==i) isIn=true;
            }
            if(isIn){
                //cout<<"컨티뉴!\n";
                continue;
            }
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

