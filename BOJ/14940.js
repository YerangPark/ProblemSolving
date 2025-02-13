const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = input[0].split(' ').map(Number);

let pX = 0;
let pY = 0;
const axisX = [0, 0, -1, 1];
const axisY = [-1, 1, 0, 0];

let land = input.slice(1).map((elem)=>elem.split(' ').map(Number));
for (let i=0; i<N; i++) {
  for (let j=0; j<M; j++) {
    if (land[i][j] === 2) {
      pX = i;
      pY = j;
    }
  }
}
let visited = Array.from({length : N}, ()=>Array(M).fill(false));

land[pX][pY] = 0;
visited[pX][pY] = true;
let q = [[pX, pY]];
while (q.length !== 0) {
  let [x, y] = q[0];
  let distance = land[x][y];
  q.shift();
  for (let i=0; i<4; i++) {
    let dx = x + axisX[i];
    let dy = y + axisY[i];
    if (dx < 0 || dx >= N || dy < 0 || dy >= M ||
        visited[dx][dy] || land[dx][dy] !== 1) continue;
    visited[dx][dy] = true;
    land[dx][dy] = distance + 1;
    q.push([dx, dy]);
  }
}

for (let i=0; i<N; i++) {
  for (let j=0; j<M; j++) {
    if (!visited[i][j] && land[i][j] == 1) {
      land[i][j] = -1;
    }
  }
}

for (let row of land) {
  console.log(row.join(" "));
}
