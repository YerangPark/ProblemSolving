#include <iostream>
#include <cstring> //memset
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>

//#define INT_MAX 2147483647
//bool compare(int a, int b) {return a>b;}
//memset(dp, -1, sizeof(dp));

using namespace std;

int n, ans=0;
//상하좌우 순서
bool visit[21][21][21];
int axisX[4]={0,0,-1,1};
int axisY[4]={-1,1,0,0};
int mapp[21][21];
vector<pair<int, int>> pv;

void move(int t);
void getMax(){
    
}

void solve(int cnt){
    if(cnt>=5){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans=max(ans, mapp[i][j]);
        return;
    }
    //네 방향 이동 : 상하좌우
    for(int i=0;i<4;i++){
        int temp[20][20];
        bool isComp[20][20]={false,};
        for(int ii=0;ii<n;ii++)
            for(int jj=0;jj<n;jj++)
                temp[ii][jj]=mapp[ii][jj];
        
        //상향 -> y값 작은애들부터 옮기기
        if(i==0){
            for(int ii=2;ii<n;ii++){
                for(int jj=0;jj<n;jj++){
                    int dy=ii, dx=jj;
                    while(1){ //계속 옮기기
                        int &before=temp[dy][dx];
                        dy+=axisY[i];
                        dx+=axisX[i];
                        //0이 아니면(값이 있으면)
                        if(temp[dy][dx]!=0){
                            //0이 아닌데 값이 같으면
                            if(temp[dy][dx]==before){
                                //이전에 합쳐진 놈이 아니면...
                                if(!isComp[dy][dx]){
                                    //합치고 true할당
                                    temp[dy][dx]*=2;
                                    before=0;
                                    isComp[dy][dx]=true;
                                }
                            }
                            //값이 다르면
                            if(temp[dy][dx]!=before){
                                break;
                            }
                        }
                        //0이면 그냥 옮겨야지.
                        temp[dy][dx]=before;
                        before=0;
                    }
                }
            }
        }
    }
}
/*
void move(int t){
    //방향에 대한 Axis 연쇄적으로 더하기. pv[0]부터 순서대로.
    //움직일 항에 다른 값이 있는데,
    // -같으면 움직일 항에 현재 항 더하고, 현재 항은 0으로 바꾸기
    // -다르면 멈추기.
    for(int i=0;i<(int)pv.size();i++){
        int dy=pv[i].first;
        int dx=pv[i].second;
        
        //계속 반복
        while(1){
            cout<<"move! "<<dy<<','<<dx<<'\n';
            dy+=axisY[t];
            dx+=axisX[t];
            //맵 벗어나면 멈추기
            if(dy<0||dy>=n||dx<0||dx>=n) break;
            //다음 항에 이미 값이 있으면
            int &now=mapp[dy-axisY[t]][dx-axisX[t]];
            if(mapp[dy][dx]!=0){
                //값이 다르면 멈추기
                if(now!=mapp[dy][dx]){
                    break;
                }
                //값이 같으면 합치기
                else if(now==mapp[dy][dx]){
                    mapp[dy][dx]*=2;
                    now=0;
                    break;
                }
            }
            //다음 항에 값 없으면 옮기기
            mapp[dy][dx]=now;
            now=0;
        }
        
    }
    
    int m=5;
    while(m--){
        bool isTrue=false;
        int cnt=(int) pv.size(), ans=0;
        while(cnt--){
            
        }
        if(isTrue){
            maxx=max(maxx, ans);
            break;
        }
    }
     
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    //5번 이동하여 얻을 수 있는 점수의 최대값 구하기.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mapp[i][j];
            if(mapp[i][j]!=0) pv.push_back(make_pair(i,j));
        }
    }
    solve(0,0);
    
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mapp[i][j]<<' ';
        }
        cout<<'\n';
    }
     */
    
    return 0;
}

/*
 2048게임 구현.
 최대 5번 이동시켜서 얻을 수 잇는 가장 큰 블록을 출력.
 */
