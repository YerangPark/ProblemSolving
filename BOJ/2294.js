const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, K] = input[0].split(' ').map(Number);

// n종류의 동전, 가치의 합이 k원
// n줄에 동전의 가치
// 출력 : 전체 경우의 수

const coinValues = input.slice(1).map(Number);

let dp = new Array(K+1).fill(100001);
dp[0] = 0; // 0원을 만들 수 있는 경우의 수 0개.

for (let i=1; i<=K; i++) {
  coinValues.map((coinValue)=>{
    if (i-coinValue >= 0) {
      dp[i] = Math.min(dp[i], dp[i-coinValue] + 1);
    }
  })
}
if (dp[K] === 100001) console.log(-1);
else console.log(dp[K]);
