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
//부울은 flag, start/endXY대신에 start만 받고 사이즈 받기 방법

using namespace std;

int n, m, i, j, in[3], dp[101][101][101];

int w(int a, int b, int c){
    int x=a+50, y=b+50, z=c+50;
    if(dp[x][y][z]) return dp[x][y][z];
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
        return dp[x][y][z]=w(20,20,20);
    else if(a<b && b<c)
        return dp[x][y][z]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else
        return dp[x][y][z]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>in[0]>>in[1]>>in[2];
    while(in[0]!=-1&&in[1]!=-1&&in[2]!=-1){
        w(in[0],in[1],in[2]);
        cin>>in[0]>>in[1]>>in[2];
    }
    return 0;
}
