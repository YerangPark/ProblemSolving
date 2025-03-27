#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node) {
    int cnt = 1;
    visited[node] = true;
    
    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            cnt += dfs(next);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for (int i=0; i<wires.size(); i++) {
        // i번째 연결을 제외한 그래프 생성
        graph = vector<vector<int>>(n+1);
        visited = vector<bool>(n+1, false);
        
        for (int j=0; j<wires.size(); j++) {
            if (i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int cntA = dfs(1);
        int cntB = n - cntA;
        int diff = abs(cntA - cntB);
        answer = min(answer, diff);
    }
    return answer;
}