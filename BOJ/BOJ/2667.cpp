#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt;
//상하좌우 순서
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
int mapp[26][26];
int dfs(int y, int x){
    int dy, dx, tmp=0;
    mapp[y][x]=0;
    for(int i=0;i<4;i++){
        dy=y+axisY[i];
        dx=x+axisX[i];
        //map 내부인지.
        if(dy>=0&&dy<n&&dx>=0&&dx<n){
            //값이 1이면 방문.
            if(mapp[dy][dx]==1){
                tmp+=dfs(dy,dx);
            }
        }
    }
    return tmp+1;
}
int main() {
    scanf("%d",&n);
    //맵 입력
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&mapp[i][j]);
        }
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mapp[i][j]==1){
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(),v.end(),less<int>());
    cout<<v.size()<<'\n';
    for(auto p:v) cout<<p<<'\n';
    return 0;
}

