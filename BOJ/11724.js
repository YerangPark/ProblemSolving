const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [N, M] = input[0].split(' ').map(Number);

const graph = Array.from({ length: N + 1 }, () => new Set());
let visited = Array.from({ length: N + 1 }, () => false);
let cnt = 0;

input.slice(1).forEach((elem) => {
  const [node1, node2] = elem.split(' ').map(Number);
  graph[node1].add(node2);
  graph[node2].add(node1);
});

for (let i = 1; i <= N; i++) {
  if (!visited[i]) {
    visited[i] = true;
    dfs(i);
    cnt++;
  }
}

function dfs(node) {
  visited[node] = true;
  graph[node].forEach((child)=>{
    if (!visited[child]) {
      dfs(child);
    }
  })
}
console.log(cnt);