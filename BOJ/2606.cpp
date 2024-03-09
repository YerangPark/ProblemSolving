#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m, cnt, v;
bool isVisitDfs[101];
stack<int> s;
vector<int> gv[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        gv[a].push_back(b);
        gv[b].push_back(a);
    }
    //DFS
    s.push(1);
    while(!s.empty()){
        v=s.top();
        s.pop();
        if(!isVisitDfs[v]){
            cnt++;
            for(int i=0;i<gv[v].size();i++){
                if(!isVisitDfs[gv[v][i]])
                    s.push(gv[v][i]);
            }
        }
        isVisitDfs[v]=true;
    }
    cout<<cnt-1<<'\n';
    return 0;
}

