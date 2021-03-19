#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001

class Edge{
public:
    int node;
    int time;
    Edge(int node, int time){
        this->node=node;
        this->time=time;
    }
};

int inDegree[MAX], result[MAX], c[MAX];
int n,m,start,finish;
vector<Edge> a[MAX];    //시작점->도착점
vector<Edge> b[MAX];    //도착점->시작점

void topologySort(){
    queue<int> q;
    //시작점 노드 큐 삽입
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        // 하나의 정점 꺼내서 그 정점에 연결된 모든 노드 처리
        for(int i=0;i<a[x].size();i++){
            //현재 연결된 노드와 그 노드까지 가는 시간값 받아오기
            Edge y = Edge(a[x][i].node, a[x][i].time);
            // 해당 노드까지 가는 현재까지의 비용이 해당 간선을 거쳐 가는 비용보다 작다면
            // 더 큰 값으로 갱신.
            if(result[y.node]<=y.time+result[x]){
                result[y.node] = y.time+result[x];
            }
            //새롭게 진입차수가 0된 애 푸시
            if(--inDegree[y.node] == 0) q.push(y.node);
            
        }
    }
    // 결과 역추적
    int count = 0;
    q.push(finish);
    while(!q.empty()){
        int y=q.front();
        q.pop();
        for(int i=0;i<b[y].size();i++){
            Edge x = Edge(b[y][i].node, b[y][i].time);
            //최장 경로에 포함되는 간선인지 확인하기
            if(result[y]-result[x.node]==x.time){
                count++;
                //큐에는 한 번씩만 담아서 추적
                if(c[x.node]==0){
                    q.push(x.node);
                    c[x.node]=1;
                }
            }
        }
    }
    printf("%d\n%d",result[finish],count);
}

int main(void){
    int sn, an, t;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&sn,&an,&t);
        a[sn].push_back(Edge(an,t));    //시작점에서 도착점
        b[an].push_back(Edge(sn,t));    //도착점에서 시작점(거꾸로!)
        inDegree[an]++;
    }
    scanf("%d %d", &start, &finish);
    topologySort();
}

