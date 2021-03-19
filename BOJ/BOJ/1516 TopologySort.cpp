#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 501
int cnt=0, inDegree[MAX], result[MAX], c[MAX];
vector<int> a[MAX];

void topologySort(){
    queue<int> q;
    
    // 진입 차수 0인 노드 큐에 삽입
    for(int i=1;i<=cnt;i++){
        if(inDegree[i]==0){
            result[i]=c[i];
            q.push(i);
        }
    }
    
    //정렬이 완전히 수행되려면 정확히 cnt개의 노드를 방문해야 함.
    for(int i = 1; i <= cnt; i++) {
        int x=q.front();
        q.pop();
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            result[y]=max(result[y],result[x]+c[y]);
            //새롭게 진입차수 0 된 정점 큐에 넣기
            if(--inDegree[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        printf("%d\n", result[i]);
    }
}

int main(void){
    int y;
    scanf("%d",&cnt);
    for(int i=1;i<=cnt;i++){
        scanf("%d",&c[i]);
        scanf("%d",&y);
        while(y!=-1){
            a[y].push_back(i);
            inDegree[i]++;
            scanf("%d",&y);
        }
    }
    topologySort();
}
