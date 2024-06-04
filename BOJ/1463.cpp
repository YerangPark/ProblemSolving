#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, dp[1000000] = {-1,};

    cin >> n;

    queue<int> q;
    q.push(n);
    dp[n] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int cnt = dp[now];
        if (now == 1) {
            cout << cnt << endl;
            break;
        }
        if (!now) continue;
        if (now % 3 == 0) {
            q.push(now / 3);
            if (dp[now/3] != -1) dp[now/3] = min(dp[now]+1, dp[now/3]);
            else dp[now/3] = dp[now]+1;
        }
        if (now % 2 == 0) {
            q.push(now / 2);
            dp[now/2] = min(dp[now]+1, dp[now/2]);
        }
        if (now - 1 > 0) {
            q.push(now - 1);
            dp[now-1] = min(dp[now]+1, dp[now-1]);
        }
    }
    return 0;
}
