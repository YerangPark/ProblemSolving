#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<int> dp(K + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int w = K; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    cout << dp[K] << '\n';
    return 0;
}
