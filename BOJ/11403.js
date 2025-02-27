const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = +input.shift();
const graph = input.map((v) => v.split(" ").map(Number));
const answer = [...Array(N)].map(() => Array(N).fill(0));

for (let i = 0; i < N; i++) {
  const visited = Array(N).fill(false);
  for (let j = 0; j < N; j++) {
    if (graph[i][j] && !visited[j]) {
      dfs(j, i, visited);
    }
  }
}

function dfs(node, start, visited) {
  answer[start][node] = 1;
  visited[node] = true;
  for (let i = 0; i < N; i++) {
    if (graph[node][i] && !visited[i]) {
      dfs(i, start, visited);
    }
  }
}

console.log(answer.map((v) => v.join(" ")).join("\n"));