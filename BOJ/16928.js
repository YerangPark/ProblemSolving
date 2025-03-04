const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = input.shift().split(" ").map(Number);

const move = new Map();

for (let i = 0; i < N+M; i++) {
  const [x, y] = input.shift().split(" ").map(Number);
  move.set(x, y);
}

// 주사위 최소 횟수 -> BFS?
const bfs = (start) => {
  const q = [];
  let visited = Array(101).fill(false);
  visited[start] = true;
  q.push([start, 0]);
  while (q.length != 0) {
    const [now, cnt] = q.shift();
    if (now === 100) {
      return cnt;
    }
    for (let i = 1; i <= 6; i++) {
      const next = now + i;
      if (next > 100 || visited[next]) continue;
      visited[next] = true;
      if (move.get(next)) {
        const afterMove = move.get(next);
        visited[afterMove] = true;
        q.push([afterMove, cnt + 1]);
      }
      else {
        q.push([next, cnt + 1]);
      }
    }
  }
};

console.log(bfs(1));
