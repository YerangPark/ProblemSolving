const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M, K, X] = input[0].split(" ").map(Number);
let graph = Array.from({ length: N+1 }, () => []);
let distance = Array(N+1).fill(-1);

input.slice(1).map((line) => {
  const [a, b] = line.split(" ").map(Number);
  graph[a].push(b);
});

function bfs(start) {
  distance[start] = 0;

  let q = [];
  q.push(start);

  while (q.length != 0) {
    let node = q.shift();
    for (let nextNode of graph[node]) {
      if (distance[nextNode] !== -1) continue;
      distance[nextNode] = distance[node] + 1;
      q.push(nextNode);
    }
  }
}

bfs(X);

let result = new Array();
for (let i = 1; i <= N; i++) {
  if (distance[i] === K) {
    result.push(i);
  }
}

console.log(result.length > 0 ? result.join("\n") : "-1");