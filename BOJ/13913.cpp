#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k, ans;
bool visit[100001];
int parent[100001];
vector<int> path;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    queue<pair<int, int>> q;
    bool isFin=false;

    q.push(make_pair(n,0));
    visit[n]=true;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int nn, t;
            nn=q.front().first;
            t=q.front().second;
            q.pop();

            //끝나는지 판단
            if(nn==k){
                isFin=true;
                ans=t;
                int idx=nn;
                while(idx!=n){
                    path.push_back(idx);
                    idx=parent[idx];
                }
                path.push_back(n);
                break;
            }

            //뒤로 걷기, 앞으로 걷기, 순간이동 판단
            int dn=nn;
            for(int i=0;i<3;i++){
                if(i==0) dn+=1;
                else if(i==1) dn-=2;
                else dn=nn*2;
                if(!(dn>=100001||dn<0)&&!visit[dn]) {
                    visit[dn]=true;
                    parent[dn]=nn;
                    q.push(make_pair(dn,t+1));
                }
            }
        }
        if(isFin) {
            cout<<ans<<'\n';
            for(int i=path.size()-1;i>=0;i--)
                cout<< path[i] << ' ';
            break;
        }
    }
    return 0;
}
