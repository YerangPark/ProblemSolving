#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
char mat[51][51];
bool visit[51][51];
int n, m;
int axisY[4]={-1, 1, 0, 0};
int axisX[4]={0, 0, -1, 1};
bool cmp(tuple<int, pair<int, int>> a, tuple<int, pair<int, int>> b){
    if(get<0>(a) > get<0>(b))
        return true;
    return false;
}
void bfs(){
    vector<tuple<int, pair<int, int>>> v;
    v.push_back({0, make_pair(0,0)});
    visit[0][0]=true;
    while(!v.empty()){
        int size=v.size(), ans=0;
        bool isFin=false;
        while(size--){
            int d=get<0>(v.back());
            int y=get<1>(v.back()).first;
            int x=get<1>(v.back()).second;
            v.pop_back();

            if(y==n-1&&x==n-1){
                isFin=true;
                ans=d;
                break;
            }

            for(int i=0;i<4;i++){
                int dy=y, dx=x;
                dy+=axisY[i], dx+=axisX[i];

                if(dy<0||dy>=n||dx<0||dx>=n) continue;
                if(visit[dy][dx]==true) continue;
                
                if(mat[dy][dx]=='-1') continue;

                //지나가려는 곳이 검은 방이면
                else if(mat[dy][dx]=='0') {
                    mat[dy][dx]='-1';
                    visit[dy][dx]=true;
                    v.push_back({d+1, make_pair(dy,dx)});
                }
                else{ //흰 방이면
                    visit[dy][dx]=true;
                    v.push_back({d, make_pair(dy,dx)});
                }
            }
            sort(v.begin(), v.end(), cmp);
        }
        if(isFin){
            cout<<ans<<'\n';
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    bfs();

    return 0;
}


