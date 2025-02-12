const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, M] = input[0].split(' ').map(Number);

const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];

const map = input.slice(1).map((elem)=>[...elem]);
let visited = Array.from({ length: N }, () => Array(M).fill(false));
let cnt = 0;

for (let i=0; i<N; i++) {
  for (let j=0; j<M; j++) {
    if (map[i][j] === "I") {
      visited[i][j] = true;
      bfs(i, j);
    }
  }
}

function bfs(x, y) {
  visited[x][y] = true;
  for (let i=0; i<4; i++) {
    let xx = x + dx[i];
    let yy = y + dy[i];
    if (xx < 0 || xx >=N || yy < 0 || yy >= M ||
      visited[xx][yy] || map[xx][yy] === "X") continue;
    if (map[xx][yy] === "P") cnt++;
    bfs(xx, yy);
  }
}

console.log(cnt ? cnt : "TT");