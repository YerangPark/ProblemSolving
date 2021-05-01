#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
bool visit[100001][3];
void bfs(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0, n));
    visit[n][0]=visit[n][1]=visit[n][2]=true;
    bool isFin=false;
    while(!q.empty()){
        int ans=0, size=q.size();
        while(size--){
            int d=q.top().first;
            int x=q.top().second;
            q.pop();

            if(x==k){
                 ans=d;
                 isFin=true;
                 break;
             }

            for(int i=0;i<3;i++){
                int dx=x, dd=d;

                if(i==0) dx*=2;
                else if(i==1) {dx+=1; dd++;}
                else if(i==2) {dx-=1; dd++;}

                if(dx<0||dx>100000) continue;
                if(visit[dx][i]) continue;
                //if(i==0&&dx>k) continue;

                visit[dx][i]=true;
                q.push(make_pair(dd,dx));
            }

        }
        if(isFin){
            //종료 시
            cout<<ans<<'\n';
            break;
        }
    }
    if(!isFin)
        cout<<0<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    bfs();
    return 0;
}
