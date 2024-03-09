#include <iostream>
#include <queue>
using namespace std;
int n, m, k;
//상하좌우 순서
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
bool visit[1001][1001]={false,};
int mapp[1001][1001];
queue<pair<pair<int, int>,int>> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>m>>n;
    int cnt1=0, cntm1=0, d=-1;
    //맵 입력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>k;
            mapp[i][j]=k;
            if(k==1){
                q.push(make_pair(make_pair(i,j),0));
                visit[i][j]=true;
            }
            else if(k==-1) {
                visit[i][j]=true;
                cntm1++;
            }
        }
    }
    
    //BFS 시작
    while(!q.empty()){
        int x=q.front().first.second;
        int y=q.front().first.first;
        d=q.front().second;
        //visit[y][x]=true;
        mapp[y][x]=1;
        cnt1++;
        q.pop();
        if(cnt1==m*n-cntm1) {
            cout<<d<<'\n';
            break;
        }
        for(int i=0;i<4;i++){
            int dy=y+axisY[i];
            int dx=x+axisX[i];
            //map 내부인지.
            if(dy>=0&&dy<n&&dx>=0&&dx<m){
                //값이 -1이 아니면 1 할당.
                if(mapp[dy][dx]==0&&!visit[dy][dx]){
                    visit[dy][dx]=true;
                    q.push(make_pair(make_pair(dy,dx),d+1));
                }
            }
        }
        
        
    }
    //1이 꽉 안찬 상태이면서 애초에 꽉 찬 경우가 아니면
    if(cnt1<=m*n-cntm1&&cnt1+cntm1!=m*n){
        cout<<-1<<'\n';
    }
    return 0;
}
