#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> graph[MAX];
    bool visit[MAX] = {false};
    int ans[MAX] = {0};

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i=0; i<graph[x].size(); i++) {
            int mx = graph[x][i];
            if (visit[mx]) continue;
            q.push(mx);
            visit[mx] = true;
            ans[mx] = x;
        }
    }

    for (int i=2; i<=n; i++) {
        cout << ans[i] << "\n";
    }
}
