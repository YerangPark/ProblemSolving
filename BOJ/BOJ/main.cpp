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
//부울은 flag, start/endXY대신에 start만 받고 사이즈 받기 방법

int n, m, d[10001],maxx=0;
vector<int> vv;

void solve(vector<int> anv, int len){
    //base case
    
    
    //recursive case
    
}
void checkLen(vector<int> v){
    int status=0;
    int len=v.size();
    for(int j=0;j<len;j++){
        if(v[j]<v[j+1]&&status==0)status=1;
        else if(v[j]>v[j+1]&&status==0)status=2;
        else if(v[j]>v[j+1]&&status==1)status=3;
        else if((v[j]<v[j+1]&&(status==2||status==3))||v[j]==v[j+1]){
            status=4;
            break;
        }
    }
    if(status!=4&&maxx<len)maxx=len;
}
/*
 int status=0;
 for(int j=i;j<len+i-1;j++){
     if(v[j]<v[j+1]&&status==0)status=1;
     else if(v[j]>v[j+1]&&status==0)status=2;
     else if(v[j]>v[j+1]&&status==1)status=3;
     else if((v[j]<v[j+1]&&(status==2||status==3))||v[j]==v[j+1]){
         status=4;
         break;
     }
 }
 if(status!=4&&maxx<len)maxx=len;
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        vv.push_back(m);
    }
    solve(n);
    cout<<maxx;
}

/*
 
 */
