#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, A, B;
    cin >> N >> M;
    vector<pair<int, int>> buses[N+1];
    vector<int> dist(N+1, 100000001);
    for (int i=0; i<M; i++) {
        int de, ar, p;
        cin >> de >> ar >> p;
        buses[de].push_back(make_pair(ar, p));
    }
    cin >> A >> B;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, A});
    dist[A] = 0;
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i=0; i<buses[cur].size(); i++) {
            int next = buses[cur][i].first;
            int nextCost = cost + buses[cur][i].second;
            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    cout << dist[B] << '\n';


    return 0;
}
