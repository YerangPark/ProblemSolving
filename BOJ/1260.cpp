#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n, m, i, j, v, vv;
bool isVisitDfs[1001], isVisitBfs[1001];
stack<int> s;
queue<int> q;
vector<int> gv[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>vv;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        gv[a].push_back(b);
        gv[b].push_back(a);
    }
    //DFS
    s.push(vv);
    while(!s.empty()){
        v=s.top();
        s.pop();
        if(!isVisitDfs[v]){
            cout<<v<<' ';
            sort(gv[v].begin(),gv[v].end(),greater<int>());
            for(int i=0;i<gv[v].size();i++){
                if(!isVisitDfs[gv[v][i]])
                    s.push(gv[v][i]);
            }
        }
        isVisitDfs[v]=true;
    }
    cout<<'\n';
    
    //BFS
    q.push(vv);
    while(!q.empty()){
        v=q.front();
        q.pop();
        if(!isVisitBfs[v]){
            cout<<v<<' ';
            sort(gv[v].begin(),gv[v].end(),less<int>());
            for(int i=0;i<gv[v].size();i++){
                if(!isVisitBfs[gv[v][i]]){
                    q.push(gv[v][i]);
                }
            }
        }
        isVisitBfs[v]=true;
    }
    return 0;
}
