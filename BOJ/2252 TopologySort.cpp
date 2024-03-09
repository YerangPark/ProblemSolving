#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001
int cnt=0, inDegree[MAX], result[MAX];    // inDegree: 진입 차수
vector<int> a[MAX];

void topologySort(){
    queue<int> q;
    
    // 진입 차수 0인 노드 큐에 삽입
    for(int i=1;i<=cnt;i++){
        if(inDegree[i]==0) q.push(i);
    }
    
    //정렬이 완전히 수행되려면 정확히 cnt개의 노드를 방문해야 함.
    for(int i = 1; i <= cnt; i++) {
        int x=q.front();
        q.pop();
        result[i]=x;
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            //새롭게 진입차수 0 된 정점 큐에 넣기
            if(--inDegree[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        printf("%d ", result[i]);
    }
}

int main(void){
    int  m, x, y;
    scanf("%d %d",&cnt,&m);
    for(int i=0;i<m;i++){
        //means x>y
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        inDegree[y]++;
    }
    topologySort();
}
