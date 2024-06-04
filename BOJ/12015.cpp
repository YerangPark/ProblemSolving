#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n;
    cin >> t;
    int arr[2][100000] = {0};
    int dp[2][100000] = {0};
    for (int i = 0; i < t; i++) {
        cin >> n;
        int m = -1;
        for (int j = 0; j < n; j++) {
            cin >> arr[0][j];
        }
        for (int j = 0; j < n; j++) {
            cin >> arr[1][j];
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];
        m = max(dp[0][1], dp[1][1]);

        for (int j = 2; j < n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + arr[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + arr[1][j];
            if (m < dp[0][j]) m = dp[0][j];
            if (m < dp[1][j]) m = dp[1][j];
        }
        cout << m << endl;
    }
    return 0;
}