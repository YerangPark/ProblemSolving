#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int visited[100001] = {0}; // 0 ~ 100,000
    queue<int> q;

    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        int cnt = visited[now];
        if (now == k) {
            cout << cnt << endl;
            break;
        }

        if (now - 1 >= 0) {
            if (!visited[now - 1]) {
                visited[now - 1] = cnt + 1;
                q.push(now - 1);
            }
        }
        if (now + 1 <= 100000) {
            if (!visited[now + 1]) {
                visited[now + 1] = cnt + 1;
                q.push(now + 1);
            }
        }
        if (now * 2 <= 100000) {
            if (!visited[now * 2]) {
                visited[now * 2] = cnt + 1;
                q.push(now * 2);
            }
        }
    }
    return 0;
}
