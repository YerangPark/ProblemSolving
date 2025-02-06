const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, K] = input[0].split(' ').map(Number);

const coinValues = input.slice(1).map(Number);

let dp = new Array(K+1).fill(0);
dp[0] = 1;

for (const coinValue of coinValues) {
  for (let i=coinValue; i<=K; i++) {
    dp[i] += dp[i - coinValue];
  }
}
console.log(dp[K]);

// 어떻게 풀이하든 노드만 올려도 4메가가 초과되므로 이 문제는 JavaScript로 통과할 수 없다.
// 그래서 C++로 아래와 같이 풀었다.
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N, K;
//     cin >> N >> K;

//     vector<int> coins(N);
//     for (int i = 0; i < N; i++) {
//         cin >> coins[i];
//     }

//     vector<int> dp(K + 1, 0);
//     dp[0] = 1;

//     for (int coin : coins) {
//         for (int i = coin; i <= K; i++) {
//             dp[i] += dp[i - coin];
//         }
//     }

//     cout << dp[K] << "\n";
//     return 0;
// }