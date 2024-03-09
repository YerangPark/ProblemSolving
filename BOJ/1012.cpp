#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt, t, k;
//상하좌우 순서
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
int mapp[51][51];
int dfs(int y, int x){
    int dy, dx, tmp=0;
    mapp[y][x]=0;
    for(int i=0;i<4;i++){
        dy=y+axisY[i];
        dx=x+axisX[i];
        //map 내부인지.
        if(dy>=0&&dy<n&&dx>=0&&dx<m){
            //값이 1이면 방문.
            if(mapp[dy][dx]==1){
                tmp+=dfs(dy,dx);
            }
        }
    }
    return tmp+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t){
        cin>>n>>m>>k;
        //맵 입력
        for(int i=0;i<k;i++){
            int a, b;
            cin>>a>>b;
            mapp[a][b]=1;
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mapp[i][j]==1){
                    v.push_back(dfs(i,j));
                }
            }
        }
        cout<<v.size()<<'\n';
        t--;
    }
    return 0;
}
