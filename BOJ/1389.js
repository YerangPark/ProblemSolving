const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const INF = Infinity;

let graph = Array.from({ length: N + 1 }, () => Array(N + 1).fill(INF));

for (let i = 1; i <= N; i++) {
    graph[i][i] = 0; // 자기 자신까지의 거리는 0
}

for (let i = 1; i <= M; i++) {
    const [A, B] = input[i].split(" ").map(Number);
    graph[A][B] = 1;
    graph[B][A] = 1;
}

for (let k = 1; k <= N; k++) {
    for (let i = 1; i <= N; i++) {
        for (let j = 1; j <= N; j++) {
            graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}

let minBacon = Infinity;
let minUser = 0;

for (let i = 1; i <= N; i++) {
    let bacon = graph[i].slice(1).reduce((sum, val) => sum + val, 0);
    if (bacon < minBacon) {
        minBacon = bacon;
        minUser = i;
    }
}

console.log(minUser);