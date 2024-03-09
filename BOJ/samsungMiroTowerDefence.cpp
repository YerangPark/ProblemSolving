#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int d[101], p[101]; //공격 방향, 공격 칸 수
int mat[26][26];
//우하좌상 순서
int axisY[4]={0, 1, 0, -1};
int axisX[4]={1, 0, -1, 0};
int score=0;
//좌하우상 순서
int circleY[4]={0, 1, 0, -1};
int circleX[4]={-1, 0, 1, 0};
queue<int> q;

//dfs로 짜야됨.
int  isContinue(int num){
    if(q.empty()) return 1;
    if(q.front()==num){
        q.pop();
        return isContinue(num)+1;
    }
    else{
        return 1;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin>>d[i]>>p[i];
    }

    //라운드만큼 반복.
    for(int t=0;t<m;t++){
        //공격 칸 수만큼 방향으로 공격 후 점수 얻기
        int dy, dx;
        dy=dx=n/2;
        for(int i=0;i<p[t];i++){
            //해당 방향으로 이동
            dy+=axisY[d[t]];
            dx+=axisX[d[t]];
            if(dy<0||dy>=n||dx<0||dx>=n||mat[dy][dx]==0) break;
            score+=mat[dy][dx];
            mat[dy][dx]=-1;
        }

        //빈공간 채우기
        int axis=0;
        dy=dx=n/2;
        bool isMInus=false;
        mat[dy][dx]=-1;
        bool isEnd=false;
        for(int i=1;i<n*n;i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < i; k++) {
                    //1 1 22 22 333 333
                    dy += circleY[axis % 4];
                    dx += circleX[axis % 4];
                    if(mat[dy][dx]==0||(dy == 0 && dx == 0)) {
                        isEnd=true;
                        break;
                    }
                    if (mat[dy][dx] > 0) q.push(mat[dy][dx]);
                    mat[dy][dx] = 0;
                }
                if(isEnd) break;
                axis++;
            }
            if(isEnd) break;
        }

        //연속 4개 이상인지 검사하여 삭제 후 점수 얻기 -> 5개가 될 수도 있고 6개가 될 수도 있음. 재귀로 연속 판정해야됨.
        //한 번만 하면 안됨. 4개인 애들이 없을 때까지 계~속~~해야됨~~
        bool isFin=false;
        int idx=0;
        while(!isFin) {
            int num[1001]={0,};
            int size = q.size();
            idx = 0;
            isFin=true;
            while (!q.empty()) {
                int qf = q.front();
                q.pop();
                int numCnt = isContinue(qf);
                if (numCnt >= 4) {
                    isFin=false;
                    score += qf * numCnt;
                } else {
                    //반복된 횟수만큼 배열에 넣기
                    for (int j = 0; j < numCnt; j++) {
                        num[idx++] = qf;
                    }
                }
            }
            //큐에 다시 넣기...
            for(int i=0;i<idx;i++){
                q.push(num[i]);
            }
        }
        //4개이상씩 다 삭제된 상태. 큐에 있음..


        //카운트재귀를써서 다시 군집화!!!!!!!!!!!!!!!!! 여기서 오류발생
        queue<int> grouping;
        int size=q.size();
        while(!q.empty()){
            int qf = q.front();
            q.pop();
            int numCnt = isContinue(qf);
            grouping.push(numCnt);
            grouping.push(qf);
        }

        //군집화한 결과를 mat배열에 넣어주기. 꼬불이 따라서
        axis=0;
        dy=dx=n/2;
        for(int i=1;i<n*n;i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < i; k++) {
                    //1 1 22 22 333 333
                    if(grouping.empty())break;
                    int qf=grouping.front();
                    grouping.pop();
                    dy += circleY[axis % 4];
                    dx += circleX[axis % 4];
                    mat[dy][dx]=qf;
                    if (dy == 0 && dx == 0) break;
                }
                if (grouping.empty()||(dy == 0 && dx == 0)) break;
                axis++;
            }
            if (grouping.empty()||(dy == 0 && dx == 0)) break;
        }
    }
    //모든 공격 및 정리 및 군집화 끝나면 점수 출력.
    cout<<score<<'\n';
}



