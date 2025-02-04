const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let n = Number(input[0]);
let cnt = 0;

let dp = Array(n+1).fill(5);
dp[0] = 0;

for (let i = 1; i <= n; i++) {
  for (let j = 1; j * j <= i; j++) {
    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
  }
}

console.log(dp[n]);