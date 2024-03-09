#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mat[1001][1001];
bool visit[1001][1001];
int n, m, idx=1, ans=1;
//상하좌우
int axisY[4]={-1, 1, 0, 0};
int axisX[4]={0, 0, -1, 1};
vector<int> team;
vector<bool> isAddTeam;

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y,x});
    visit[y][x]=true;
    int cnt=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int fy=q.front().first;
            int fx=q.front().second;
            q.pop();
            mat[fy][fx]=idx;
            cnt++;

            for(int i=0;i<4;i++){
                int dy=fy+axisY[i], dx=fx+axisX[i];
                if(dy<0||dy>=n||dx<0||dx>=m) continue;
                if(mat[dy][dx]==0) continue;
                if(visit[dy][dx])continue;
                visit[dy][dx]=true;
                q.push({dy,dx});
            }
        }
    }
    isAddTeam.push_back(false);
    team.push_back(cnt);
    idx++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //입력
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1) mat[i][j]=-1;
        }
    }


    //팀 인덱싱
    isAddTeam.push_back(false);
    team.push_back(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){
                bfs(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=0) continue;
            //사방에 인접한 팀 있는지 검사해서 더해주기
            int teamCnt=1;
            for(int k=0;k<4;k++){
                int dy, dx;
                dy=i+axisY[k];
                dx=j+axisX[k];
                if(dy<0||dy>=n||dx<0||dx>=m) continue;
                if(mat[dy][dx]==0) continue;
                if(isAddTeam[mat[dy][dx]]) continue;
                isAddTeam[mat[dy][dx]]=true;
                teamCnt+=team[mat[dy][dx]];
            }
            for(int k=0;k<4;k++){
                int dy, dx;
                dy=i+axisY[k];
                dx=j+axisX[k];
                if(dy<0||dy>=n||dx<0||dx>=m) continue;
                if(!isAddTeam[mat[dy][dx]]) continue;
                isAddTeam[mat[dy][dx]]=false;
            }
            ans=max(ans,teamCnt);
        }
    }

    cout<<ans<<'\n';
    return 0;
}


/*
 * 그룹 당 1의 개수 : 모양의 크기.
 * 배열의 칸 하나에 들어있는 수를 변경해서 만들 수 있는 모양의 최대 크기 구하기
 * 방법 1) n*m 배열을 순회하면서 바꾼 후 모양의 최대 크기 구하기
 *        -> 매번 전체 순회를 해야함. 비효율적일 듯
 * 방법 2) 인덱싱하여 그루핑 해놓은 후에 그룹별 크기를 기록해놓고,
 *        n*m배열을 순회하며 변경하고,
 *        해당 칸 사방에 모양이 있으면 해당 모양의 크기 합계 구하기.
 *        ->매번 전체 순회를 할 필요 없음
 * 방법 3) 애초에 그룹 indexing 할 때 변경하고/안하고로 나누어
 *        bfs로 전부 돌려버리기..? -> 어짜피 팀일 때만 검사해서 max를 계속 계산해주면 되니까...
 */
