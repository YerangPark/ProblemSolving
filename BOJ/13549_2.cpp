#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    bool visit[100001] = {false};
    queue<pair<int, int>> q;
    cin >> n >> k;
    visit[n] = true;

    q.push(make_pair(n, 0));
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (now == k) {
            cout << cnt << endl;
            break;
        }

        if (now * 2 <= 100000 && !visit[now * 2]) {
            q.push(make_pair(now * 2, cnt));
            visit[now * 2] = true;
        }
        if (now - 1 >= 0 && !visit[now - 1]) {
            q.push(make_pair(now - 1, cnt + 1));
            visit[now - 1] = true;
        }
        if (now + 1 <= 100000 && !visit[now + 1]) {
            q.push(make_pair(now + 1, cnt + 1));
            visit[now + 1] = true;
        }
    }
}
