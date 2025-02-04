const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);

// N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다
// 못들은사람 n명
const listenSet = new Set();
for (let i=1; i<=n; i++) {
    listenSet.add(input[i]);
}

// 못본사람 m명
let result = [];
for (let i = n + 1; i <= n + m; i++) {
    if (listenSet.has(input[i])) {
        result.push(input[i]);
    }
}
result.sort();
console.log(result.length);
console.log(result.join('\n'));