#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, E;

int daijkstra(int start, int end, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(N+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start}); // 거리, 현재 노드

    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        if (dist[now] < cost) continue;

        for (auto [next, weight] : graph[now]) {
            if (dist[next] > cost + weight) {
                dist[next] = cost + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N+1);
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // 꼭 거쳐야하는 두 점
    int v1, v2;
    cin >> v1 >> v2;

    // 1 -> v1 -> v2 -> N
    int a = daijkstra(1, v1, graph);
    int b = daijkstra(v1, v2, graph);
    int c = daijkstra(v2, N, graph);

    // 1 -> v2 -> v1 -> N
    int x = daijkstra(1, v2, graph);
    int y = daijkstra(v2, v1, graph);
    int z = daijkstra(v1, N, graph);

    if ((a == 1e9 || b == 1e9 || c == 1e9) && (x == 1e9 || y == 1e9 || z == 1e9)) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = min(a+b+c, x+y+z);
    cout << ans << '\n';

    return 0;
}
