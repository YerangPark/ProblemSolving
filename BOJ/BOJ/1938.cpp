#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, ans=0;
int axisY[4]={-1, 1, 0, 0};
int axisX[4]={0, 0, -1, 1};
char mat[51][51];
bool visit[51][51][3]; //중앙y, x, 방향
struct log{
    int y;
    int x;
    int d;  //가로 = 1, 세로 : 2
};
struct log B, E;


//정점 정보 : 3칸의 좌표 or 중앙좌표 & 세로/가로 상황 + 이동거리
void bfs(){
    //중앙y, 중앙x, 세로/가로 상황, 이동한 거리 순서
    queue<tuple<int, int, int, int>> q;
    q.push({B.y, B.x, B.d, 0});
    visit[B.y][B.x][B.d]=true;
    bool isFin=false;

    while(!q.empty()){
        int size=q.size();
        while(size--){
            int y, x, d, len;
            y=get<0>(q.front());
            x=get<1>(q.front());
            d=get<2>(q.front());
            len=get<3>(q.front());
            q.pop();

            if(y==E.y&&x==E.x&&d==E.d){
                isFin=true;
                //끝날 조건에 해당하는 경우
                ans=len;
                break;
            }

            //상 하 좌 우 회전
            for(int i=0;i<5;i++) {
                int dy = y, dx = x, dd = d;

                if (i < 4) { //회전 아니면 중심좌표값 갱신
                    dy += axisY[i];
                    dx += axisX[i];
                }
                else{ //회전 시 방향 바꿔줌
                    dd=d==1?2:1;
                    //그 통나무를 둘러싸고 있는 3*3 정사각형의 구역에 1이 없어야만 회전시킬 수 있다.
                    bool isOneIn=false;
                    for(int ii=dy-1;ii<=dy+1;ii++){
                        for(int jj=dx-1;jj<=dx+1;jj++){
                            if(ii<0||ii>=n||jj<0||jj>=n)continue;
                            if(mat[ii][jj]=='1') isOneIn=true;
                        }
                    }
                    if(isOneIn) continue;
                }
                if(dd == 1){ //가로이면
                    if (dx - 1 < 0 || dx + 1 >= n || dy < 0 || dy >= n) continue;
                    if (mat[dy][dx] == '1' || mat[dy][dx - 1] == '1' || mat[dy][dx + 1] == '1') continue;
                }
                else if(dd == 2) { //세로이면
                    if (dx < 0 || dx >= n || dy - 1 < 0 || dy + 1 >= n) continue;
                    if (mat[dy][dx] == '1' || mat[dy - 1][dx] == '1' || mat[dy + 1][dx] == '1') continue;
                }
                if (visit[dy][dx][dd])continue;
                visit[dy][dx][dd] = true;
                q.push({dy, dx, dd, len + 1});
            }
        }
        if(isFin){
            //끝난 경우
            cout<<ans<<'\n';
            break;
        }
    }
    if(!isFin)cout<<'0'<<'\n';
}

//1:20분 시작
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    struct log beforeB, beforeE, BB, EE;
    int cntB=0, cntE=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='B'){
                cntB++;
                BB.y=i; BB.x=j;
                if(cntB==1) beforeB=BB;
                else if(cntB==2){
                    B.y=BB.y; B.x=BB.x;
                    if(beforeB.y==BB.y) B.d=1; //같은 행 : 가로 : 1
                    else if(beforeB.x==BB.x) B.d=2; //같은 열 : 세로 : 2
                }
            }
            if(mat[i][j]=='E'){
                cntE++;
                EE.y=i; EE.x=j;
                if(cntE==1) beforeE=EE;
                else if(cntE==2){
                    E.y=EE.y; E.x=EE.x;
                    if(beforeE.y==EE.y) E.d=1; //같은 행 : 가로 : 1
                    else if(beforeE.x==EE.x) E.d=2; //같은 열 : 세로 : 2
                }
            }
        }
    }
    bfs();

    return 0;
}
