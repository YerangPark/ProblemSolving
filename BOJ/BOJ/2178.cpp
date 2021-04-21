#include <iostream>
#include <queue>
using namespace std;
int n, m;
//상하좌우 순서
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
int mapp[101][101];
queue<pair<pair<int, int>, int>> q;

int main() {
    scanf("%d %d",&n,&m);
    //맵 입력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&mapp[i][j]);
        }
    }
    
    q.push(make_pair(make_pair(0,0),1));
    mapp[0][0]=0;
    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(y==n-1&&x==m-1){
            printf("%d\n",d);
            break;
        }
        
        int dy, dx;
        for(int i=0;i<4;i++){
            dy=y+axisY[i];
            dx=x+axisX[i];
            if(dy>=0&&dy<n&&dx>=0&&dx<m){
                if(mapp[dy][dx]==1){
                    mapp[dy][dx]=0;
                    q.push(make_pair(make_pair(dy,dx),d+1));
                }
            }
        }
        
    }
    return 0;
}

