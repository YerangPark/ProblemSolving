#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e7;
int V, E, K; // 정점 수 (1~), 간선 개수, 시작 정점 번호

void dajikstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 정점, 누적 거리
    pq.push({0, K});
    dist[K] = 0;
    while (!pq.empty()) {
        auto [sumDir, node] = pq.top();
        pq.pop();

        for (const auto &[next, dir] : graph[node]) {
            if (dist[next] == INF || dist[next] > sumDir + dir) {
                dist[next] = sumDir + dir;
                pq.push({sumDir + dir, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E >> K;
    vector<vector<pair<int, int>>> graph(V+1);
    vector<int> dist(V+1, INF);

    // vector<pair<int, int>> graph[E];
    for (int i=0; i<E; i++) {
        int u, v, w;
        // u -> v, 가중치 w
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // 각 정점까지 최단경로 저장 시작점은 0
    dajikstra(graph, dist);

    for (int i=1; i<=V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
