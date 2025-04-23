#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<pair<int, int>>> graph;
bool visited[100001] = {false, };

int endNode = 0;
int answer = 0;

void DFS(int node, int sum) {
    visited[node] = true;

    if (answer < sum) {
        answer = sum;
        endNode = node;
    }

    for (const auto & [next, nextDis] : graph[node]) {
        if (visited[next]) continue;
        DFS(next, sum + nextDis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    graph.resize(N+1);

    for (int i=0; i<N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    DFS(1, 0);
    answer = 0;
    memset(visited, false, sizeof(visited));
    DFS(endNode, 0);

    cout << answer << '\n';

    return 0;
}
